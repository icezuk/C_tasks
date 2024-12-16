//write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
// In particular, itob(n,s,16) formats n as a hecadecimal integer in s.
#include <stdio.h>
#define BUFF_SIZE  100


void reverseBuff(char* buff, int buffLen)
{
  char buffTemp[BUFF_SIZE];
  int i = 0;
  int j = buffLen;
  for(i = 0; i <= buffLen; i++)
  {
    buffTemp[i] = buff[j--];
  }
  int k = 0;
  for(k = 0; k <= buffLen; k++)
  {
    buff[k] = buffTemp[k];
  }
}


void convertNumToLetter(char* buff, int buffSize)
{
  int i = 0;
  for(i = 0; i <= buffSize; i++)
  {
    if(buff[i] > '9')
    {
      buff[i] = (buff[i] - ('0' + 10)) + 'A';
    }
  }
  
}

void itob(int n, char* s, int b)
{
  char buff[BUFF_SIZE];
  int buffCounter = 0;
  while(n/b != 0)
  {
    buff[buffCounter++] = '0' + n%b;
    n /= b;
  }
  buff[buffCounter] = '0' + n%b;
  reverseBuff(buff, buffCounter);
  convertNumToLetter(buff, buffCounter);
  buff[buffCounter + 1] = '\0';
  int i = 0;
  while(s[i] != '\0')
  {
    s[i] = buff[i];
    i++;
  }
}


int main(void)
{
  int n = 35631;
  int b = 16;
  char s[5];
  itob(n,s,b);
  printf("%s\n", s);
  return 0;
}
