#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int gcd(int i, int j)
{
  if(j%i==0) return i;
  return gcd(j, i%j);
}


int main()
{
  int k;
  printf("%d\n",gcd());
}
