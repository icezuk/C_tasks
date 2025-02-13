//Write version of the library functions strncpy, strncat and strncmp, which operate on at most the first n characters of their argument strings. 
//For example, strncpy(s, t, n) copies at most n characters of t to s. 
#include <stdio.h>

void strncpy2(char *s, char *t, int n)
{
  while(n-- && (*s++ = *t++))
  ;
}

void strncat2(char *s, char *t, int n)
{
  while(*s++)
  ;
  s--;
  while(n-- && (*s++ = *t++))
  ;
}

int strncmp2(char *s, char *t, int n)
{
  while(n-- && *s++ == *t++)//precedence of == higher than &&
  ;
  s--;
  t--;
  if(!(*s))
  return 0; 
  if(*s<*t)
  return -1;
  else
  return 1;
}

int main()
{
  char s[] = "s string";
  char t[] = "s string";
  printf("%d\n",strncmp2(s,t,3));
  return 0;
  
  
}
  
