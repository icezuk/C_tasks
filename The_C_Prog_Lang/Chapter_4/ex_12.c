//recursive itoa
#include <stdio.h>

#define MAX_RESULT_SIZE 1000

void itoa(int num, char* result);

int main()
{
  char result[MAX_RESULT_SIZE];
  itoa(233123, result);
  printf("%s\n", result);
  return 0; 
}

void itoa(int num, char *result)
{
  static int counter = 0;
  if(num/10)
  {
    itoa(num/10, result);
  }
  result[counter++] = (num%10 + '0');
  result[counter] = '\0';
}
