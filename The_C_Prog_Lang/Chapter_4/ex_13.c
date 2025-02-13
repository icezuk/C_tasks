//recursive reverse(s), reverses string in place
#include <stdio.h>
#include <string.h>

void reverse(char *s, int left, int right)
{
  if(left<right)
  {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverse(s, left+1, right-1);
  }
}

int main()
{
  char str[11] = "123asd123io";
  reverse(str, 0, strlen(str)-1);
  printf("%s\n", str);
  return 0;
}
