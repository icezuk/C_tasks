//write a program that prints its input one word per line (no arrays)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void inputString(FILE* fp, size_t len, char* str)
{
  int i = 0;
  for(i = 0; i < len; i++)
  {
    if(i >= len)
    {
      str = realloc(str, (len * 2) * (sizeof(char)));
    }
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
