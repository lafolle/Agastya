#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  const time_t t=1749870067;
  printf("%s",ctime(&t));
}
