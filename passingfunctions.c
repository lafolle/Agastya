#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int add(int a , int b)
{
  return a+b;
}

void f(int (*fptr)(int, int), int a, int b)
{
  printf("%d\n", fptr(a,b));
}

int main()
{
  f(add, 23,112);
  
  return 0;
}

  
	 
