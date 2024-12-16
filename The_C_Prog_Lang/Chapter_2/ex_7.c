//write a function invert(x,p,n) that returns x with the n bits that begin at 
//position p inverted, leaving the other unchanged
#include <stdio.h>


int invert(int x, int p, int n)
{
  
  int allOnes = ~0 << n;//1^i-n0^n, 111111000
  int flippedOnes = ~allOnes;//0^i-n1^n, 000000111
  int desiredPositionOnes = flippedOnes << (p+1-n);// 000111000
  int xorWithMain = desiredPositionOnes ^ x;// 100010000
  return xorWithMain;

  
}

int main(void)
{
  int x = 0b100101000;
  printf("%d\n", invert(x,5, 3)); 
  return 0;
  
}
