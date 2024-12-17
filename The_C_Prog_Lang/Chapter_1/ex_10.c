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
    if(i >= len)
      {
        str = realloc(str, (len * 2) * (sizeof(char)));
      }
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

void inputLogic(int* sizeStr)
{
  char* inputStr;
  int ch;
  inputStr = malloc((*sizeStr + 1)*(sizeof(char)));
  inputStr[*sizeStr] = '\0';
  while(((ch=fgetc(stdin)) != EOF))
  {
    int i = 0;
    ungetc(ch, stdin);
    while(((ch=fgetc(stdin)) != '\n'))
    {
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
}

int main(void)
{
  int sizeStr = 200;
  inputLogic(&sizeStr);
  return 0;
}
