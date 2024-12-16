//write a function htoi which converts hexadecimal to int
//include
#include <stdio.h>
#include <errno.h>

int powe(int base, int exponent)
{
  int temp = base;
  int i = 0;
  for(i = 0; i < exponent; i++)
  {
    temp *= temp;
  }
  return temp;
}

int main(void)
{
  unsigned int iMaxInputSize = 1000;
  unsigned int iCounterInput = 0;
  unsigned int iCountConv = 0;
  unsigned int iFinalNum = 0;
  char strInput[iMaxInputSize];
  while((strInput[iCounterInput] = getchar()) != '\n')
  {
    iCounterInput++;
  }
  for(iCountConv = 0; iCountConv < iCounterInput; iCountConv++)
  {
    if((strInput[iCounterInput - 1 - iCountConv] >= '0') && (strInput[iCounterInput - 1 - iCountConv] <= '9'))
    {
      iFinalNum += (strInput[iCounterInput - 1 - iCountConv] - '0') * (powe(16,iCountConv));
    }
    else if((strInput[iCounterInput - 1 - iCountConv] >= 'a') && (strInput[iCounterInput - 1 - iCountConv] <= 'f'))
    {
      iFinalNum += ((strInput[iCounterInput - 1 - iCountConv]) - 87) * (powe(16,iCountConv));
    }
    else if((strInput[iCounterInput - 1 - iCountConv] >= 'A') && (strInput[iCounterInput - 1 - iCountConv] <= 'F'))
    {
      iFinalNum += ((strInput[iCounterInput - 1 - iCountConv]) - 55) * (powe(16,iCountConv));
    }
    else
    {
      printf("Wrong Input\n");
      return -1;
    }
  }
  printf("%u\n", iFinalNum);
  
  return 0;
}
