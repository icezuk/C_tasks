//write a function(s1,s2) that expnads shorthand notation like a-z in the string s1 into
//the equivalent complete list abc...xyz in s2. 
#include <stdio.h>
#include <string.h>

void expand(char* s1, char* s2, int s2Len)
{
  
  int s1Cur = 0;
  int s2Cur = 0;
  int s1Len = 0;
  while(s1[s1Len] != '\0')
  {
    s1Len++;
  }
  
  int i = 0;
  for( ; i <= s1Len; i++, s1Cur++, s2Cur++)
  {
    if(s2Len < s2Cur)
    {
      printf("Too Small s2");
      break;
    }
    
      if(s1[i] == '-') //
      {
      	if((s1[i-1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z') ||
           (s1[i-1] >= '0' && s1[i-1] < '9' && s1[i+1] > '0' && s1[i+1] <= '9'))
      	{
          int j = 1;
          for( ; j < (s1[i+1] - s1[i-1]); j++)
          {
            s2[s2Cur] = (s1[i-1] + j);
    	    s2Cur++;
          }
          s2Cur--;
        }
      }
      else
      {
        s2[s2Cur] = s1[i];
      }
  }
  s2[s2Cur] = '\0';
}

int main(void)
{
  char s1[] = "a-f-m1-3     qwe";
  char s2[50];
  expand(s1,s2, 50);
  int i = 0;
  for( ; i < ('m' - 'a' + 1) + 11; i++)
  {
    printf("%c\n", s2[i]);
  }
  return 0;
}
