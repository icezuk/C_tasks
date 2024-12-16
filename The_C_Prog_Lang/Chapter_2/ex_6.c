//Write a function setbits(x,p,n,y) that returns x with the n 
//bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
#include <stdio.h>


//position is counted rightside, 0 is the least significant bit
int setBits(int x, int p, int n, int y)
{
  //Right Side: set all but n rightmost bits of y to 0, then shift y so that positions match the positions at x
  //Left Side: the problem is that the above statement with | to x doesn't work with x'1 y'0 so we set all x in changed place to 0s
  
  return ((x & ~(~(~0 << n) << (p+1-n))) | ((~(~0 << n) & y) << (p+1-n)));

}

int main(void)
{
  int a = 0b0100101000;
  int b = 0b0101001010;
  printf("%d\n", setBits(a,5,3,b));
  return 0;
}
