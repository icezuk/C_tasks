/* write a program to copy its input to its output replacing each tab by \t,
each backspace by \b, and each backslash by \\ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void inputString(FILE* fp, size_t len, char* str)
{
  int i = 0;
  for(i = 0; i < len; i++)
  {
    if(str[i] == '\b')
    {
      printf("\\b");
    }
    else if(str[i] == '\t')
    {
      printf("\\t");
    }
    else if(str[i] == '\\')
    {
      printf("\\\\");
    }
    else
    {
      putchar(str[i]);		
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
