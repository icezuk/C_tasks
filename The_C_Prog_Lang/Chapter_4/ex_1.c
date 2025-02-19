///write the function strrindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none
#include <stdio.h>
#define MAXLINE 1000

int ggetline(char line[], int max);
int strrindex(char source[], char searchfor[]);


int main(void)
{
  char line[MAXLINE];
  int found = 0;
  
  char pattern[] = "asd";
  pattern[3] = '\0';
  while(ggetline(line, MAXLINE) > 0)
  {
    if((found = strrindex(line, pattern)) >= 0)
    {
      printf("%d\n", found+1);
      return found;
    }
  }
  return -1;
}

int ggetline(char s[], int lim)
{
  int c, i;
  
  i = 0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int strrindex(char s[], char t[])
{
  int lenOfS = 0, lenOfT = 0;
  int i, j, k;
  while(s[lenOfS] !='\0')
  {
    lenOfS++;
  }
  while(t[lenOfT] !='\0')
  {
    lenOfT++;
  }
  for(i = lenOfS - lenOfT ; i >= 0; i--)
  {
    //int counter = 1;
    for(j = i, k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k++)
      ;
    if(k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
