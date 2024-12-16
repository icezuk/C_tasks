//write a program to write a histogram of the lengths of words in its input horizontally.
#include <stdio.h>


void fnInputLogicHor(void)
{
  char c;
  while((c = getchar()) != '\n')
  {
    switch(c)
    {
      case(' '):
        printf("\n");
        break;
      case('\t'):
        printf("\n");
        break;
      default:
        printf("-");
    }
  }
  printf("\n");
}


int main(void)
{
  fnInputLogicHor();
  return 0;
}

