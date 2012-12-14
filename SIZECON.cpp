/* Program in minimum
   score = 116.
   Better try in some other language.
*/

#include <cstdio>
int main()
{
  int c=0,n,k;
  scanf("%d", &n);
  for(int i=0;i<n;i++,scanf("%d",&k),c+=k<0?0:k);
  printf("%d\n",c);
}

