//write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. 
//For example, 
//expr 2 3 4 + *
///evaliates 2 x (3+4)
#include<stdio.h>

#define MAXSIZE 100
#define NUMBER '0'
int stack[MAXSIZE];
int stackIndex = 0;
int resultOfGetop = 0;

void push(int);
int pop();
int getop(char*);

int main(int argc, char *argv[])
{
  for( ; --argc; )
  {
    int temp = 0;
    switch(getop(*++argv))
    {
      case NUMBER:        
        push(resultOfGetop);
        break;
      case '+':
      	push(pop() + pop());
      	break;
      case '*':
      	push(pop() * pop());
      	break;
      case '-':
      	temp = pop();
      	push(pop() - temp);
      	break;
      case '/':
      	temp = pop();
      	push(pop() / temp);
      	break;
      default:
      	printf("Unknown operand or operation\n");
      	break;
    }
  }
  return 0;
}

int getop(char *curArg)
{
  resultOfGetop = 0;
  
  if(*curArg < '0' || *curArg > '9')
    return *curArg;
  while(*curArg != '\0')
    {
      resultOfGetop = resultOfGetop*10 + (*curArg - '0');
      curArg++;
    }
  return '0';
}

void push(int num)
{
  if(stackIndex >= MAXSIZE)
  {
    printf("Stack size exceeded\n");
    return;
  }
  stack[stackIndex++] = num;
}

int pop()
{
  if(stackIndex <= 0)
  {
    printf("Stack empty\n");
    return -1;
  }
  return stack[--stackIndex];
}
