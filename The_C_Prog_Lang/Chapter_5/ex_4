//write the func strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
#include <stdio.h>

int strend(char *s, char *t)
{
  while(*s++)
  ;
  *s--;
  char *temp = t;
  while(*temp++)
  {
  *s--;
  }
  while(*s++==*t++)
  {
    if(!*s)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  char *str1 = "12345";
  char *str2 = "245";
  printf("%d\n", strend(str1,str2));
  return 0;
}
