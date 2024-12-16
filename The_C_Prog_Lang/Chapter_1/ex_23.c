//needs fix
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
  char str[1000];
  int bHasEntered = 0;
  int bInsideStar = 0;
  int numberSpaces = 0;
  FILE* fpR = fopen("./chapter_1/experiment.c", "r+");
  FILE* fpTemp = fopen("./chapter_1/temp.c", "w");
  
  
  while(fgets(str, 999, fpR) != NULL)
  {    
    bHasEntered = 0;
    if(strstr(str, "/*") != NULL)
    { 
      bInsideStar = 1;
      bHasEntered = 1;
      int i = 0;
      while(str[i] != '/' && str[i+1] != '*')
      {
        i++;
      }
      str[i] = '\n';
      str[i+1] = '\0';
      fputs(str, fpTemp);
    }
    if(strstr(str, "*/") != NULL)
    {
      bHasEntered = 1;
      bInsideStar = 0;
      
      int i = 0;
      while(str[i] != '*' || str[i + 1] != '/')
      {
        if(str[i] == ' ')
        {
          numberSpaces++;
        }
        i++;
      }
      printf("%d\n", i);
      int j = 0;
      while(str[j] != '\n' && str[j] != '\0')
      {
        j++;
      }
      printf("%d\n", j);
      char strTemp[1000];
      int l = 0;
      for(l = 0; l < numberSpaces; l++)
      {
        strTemp[l] = ' ';
      }
      i++;
      int k = l;
      while(i++ != j)
      {
        strTemp[k] = str[i];
        k++;
      }
      fputs(strTemp, fpTemp);
    }
    if(strstr(str, "//") != NULL)
    {
      bHasEntered = 1;
      int i = 0;
      while(str[i] != '/' || str[i+1] != '/')
      {
        i++;
      }
      str[i] = '\n';
      str[i + 1] = '\0';
      fputs(str, fpTemp);
    }
    if(bHasEntered == 0 && bInsideStar == 0)
    {
      fputs(str, fpTemp); 
    }
  }
  fclose(fpTemp);
  fclose(fpR);
  return 0;
}
