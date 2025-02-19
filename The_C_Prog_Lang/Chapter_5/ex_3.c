//write a pointer version of strcat
//assume enough space
#include <stdio.h>
void strcatt(char *s, char *t)
{  
  while(*s++)  // find end of s
    ;
  s--;
  while((*s++ = *t++)) //copy t, *s = *t != 0 equiv *s = *t
    ;
}

int main()
{
  char s1[20] = "Hello, ";
  char *s2 = "World!";
  strcatt(s1,s2);
  printf("%s\n",s1);
  
  return 0;
}
