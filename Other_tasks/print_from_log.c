#include <stdio.h>
#include <string.h>

void printInput(char strInput[], int bIsHtml, int bIsPlain)
{
  if (bIsHtml == 1)
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
  else if(bIsPlain == 1)
  {
    printf("%s", strInput);
  }
}

int main(int argc, char * argv[])
{
  char strInput[300];
  strInput[300] = '\0';
  char strMask[100];
  int iIsBetweenEqual = 0;
  FILE* pinFP;
  unsigned long uliPosition;
  int bIsHtml = 0;
  int bIsPlain = 0;
  int i, k = 0;
  int bHasFoundArgOne = 0;
  
  snprintf(strMask, 100, "CLIENT_ID...........: %s", argv[1]);
  if (strcmp(argv[2], "html") == 0)
  {
    bIsHtml = 1;
  }
  else if(strcmp(argv[2], "plain") == 0)
  {
    bIsPlain = 1;
  }
  if((bIsPlain != 1) && (bIsHtml != 1))
  {
    printf("Wrong second argument\n");
    return -1;
  }
  
  for(i = 3; i < argc; i++)
  {
    pinFP = fopen(argv[i], "r");
    if(pinFP == NULL)
    {
      printf("Error file missing\n");
      return -2;
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
      	bHasFoundArgOne = 1;
      	fseek(pinFP,uliPosition,SEEK_SET);
      	// strInput is equal to found strMask; put it at start of uliPosition
      	fgets(strInput, 300, pinFP);
      	do
      	{
      	  printInput(strInput, bIsHtml, bIsPlain);
        } while((fgets(strInput, 300, pinFP) != NULL) && (feof(pinFP) == 0) &&
                (strstr(strInput,"============================================================") == NULL));
        
        if(feof(pinFP) != 0)
        {
          printInput(strInput, bIsHtml, bIsPlain);
        }
        //ungetc to return the start of next block
      	while(strInput[k] != '\n')
      	{
      	  k++;
        }
        for( ; k >= 0; k--)
        {
          ungetc(strInput[k], pinFP);
        }
      	printf("\n\n============================================================\n\n\n");
      	iIsBetweenEqual = 0;
      }
    }
  }
  if(bHasFoundArgOne == 0)
  {
    printf("ClientID match not found\n");
    return -3;
  }
  return 0;
}
