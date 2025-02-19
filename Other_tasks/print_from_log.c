/*
USAGE:
lr2_dumpgenlog "($CLIENT_ID)" "(html)/(plain)" "($LOG_FILE_1)" "($LOG_FILE_2)" ...
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printInput(char strInput[], int iArgTwo)
{
  if (iArgTwo == 1)
  {
    int j = 0;
    while((strInput[j] != '\n') && (strInput[j] != '\0'))
    {
      j++;
    }
    if(strInput[j] == '\0')
    {
      printf("%s%s", strInput, "<br>");
    }
    else
    {
      strInput[j] = '\0';
      printf("%s%s\n", strInput, "<br>");
    }
  }
  else if(iArgTwo == 2)
  {
    printf("%s", strInput);
  }
}

int validateArgTwo(char* argv[], int *iArgTwo)
{
  if (strcmp(argv[2], "html") == 0)
  {
    *iArgTwo = 1;
  }
  else if(strcmp(argv[2], "plain") == 0)
  {
    *iArgTwo = 2;
  }
  if((*iArgTwo != 1) && (*iArgTwo != 2))
  {
    printf("Wrong second argument\n");
    exit(-1);
  }
  return 0;
}

int inputLogic(char* argv[], int* bHasFoundArgOne, char strMask[], int* iArgTwo, int i)
{
  char strInput[300];
  strInput[300] = '\0';
  int iIsBetweenEqual = 0;
  FILE* pinFP;
  unsigned long uliPosition;
  int k = 0;
  
  pinFP = fopen(argv[i], "r");
  if(pinFP == NULL)
  {
    printf("Error file missing\n");
    exit(-2);
  }
  while((feof(pinFP) == 0) && (fgets(strInput, 300, pinFP) != NULL))
  { 
    if(strstr(strInput, "============================================================") != NULL)
    {
     iIsBetweenEqual = 1;
     uliPosition = ftell(pinFP);
    }
    if(strstr(strInput, strMask) != 0 && iIsBetweenEqual == 1)
    {
     *bHasFoundArgOne = 1;
     fseek(pinFP,uliPosition,SEEK_SET);
     // strInput is equal to found strMask; put it at start of uliPosition
     fgets(strInput, 300, pinFP);
     do
     {
       printInput(strInput, *iArgTwo);
     } while((fgets(strInput, 300, pinFP) != NULL) && (feof(pinFP) == 0) &&
              (strstr(strInput,"============================================================") == NULL));
        
      
      printInput(strInput, *iArgTwo);
      if(feof(pinFP) != 0)
        printf("\n");
      
      //ungetc to return the start of next block
      /*while(strInput[k] != '\n')
      {
      	k++;
      }
      for( ; k >= 0; k--)
      {
        ungetc(strInput[k], pinFP);
      }*/
      iIsBetweenEqual = 0;
    }
    
  }
  return 0;
}

int main(int argc, char * argv[])
{
  int iArgTwo = 0;
  int bHasFoundArgOne = 0;
  char strMask[100];
  int i;
  
  snprintf(strMask, 100, "CLIENT_ID...........: %s", argv[1]);
  
  validateArgTwo(argv, &iArgTwo);
  for(i = 3; i < argc; i++)
  {
    inputLogic(argv, &bHasFoundArgOne, strMask, &iArgTwo, i);
  }
  if(bHasFoundArgOne == 0)
  {
    printf("ClientID match not found\n");
    return -3;
  }
  return 0;
}
