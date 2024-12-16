//write a program that prints its input one word per line (no arrays)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void inputString(FILE* fp, size_t len, char* str)
{
  int i = 0;
  for(i = 0; i < len; i++)
  {
    if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
    {
      putchar(str[i]);
    }
    else
    {
      printf("\n");
    }
  }
  printf("\n");
}


int main(void)
{
  char* inputStr;
  int ch;
  int sizeStr = 200;
  
  inputStr = malloc((sizeStr + 1)*(sizeof(char)));
  inputStr[sizeStr] = '\0';
  while(((ch=fgetc(stdin)) != EOF))
  {
    int i = 0;
    ungetc(ch, stdin);
    while(((ch=fgetc(stdin)) != '\n'))
    {
      if(i >= sizeStr)
      {
        inputStr = realloc(inputStr, (sizeStr * 2) * (sizeof(char)));
      }
      inputStr[i++] = ch;
    }
    inputStr[i] = '\0';
    if(strstr(inputStr, "exit") != NULL)
    {
      printf(" \n");
      exit(0);
    }
    inputString(stdin, i, inputStr);
  }
  
  free(inputStr);
  return 0;
}
