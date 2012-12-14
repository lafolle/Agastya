#include <stdio.h>
#include <stdlib.h>

int v[10001];
int n;

int b_search(long long int k, int l, int h)
{
  int mid;

  if(l<=h){
    mid = h - (h-l)/2;

    if(v[mid]==k) return mid;
    else if(k<v[mid]) return b_search(k, l, mid-1);
    else if(k>v[mid]) return b_search(k, mid+1, h);
  }

  return -1;
}

int main()
{
  int i,j,q;
  long long int k;
  while(scanf("%d %d", &n , &q)!=EOF){
    
    for(i=0;i<n;i++)scanf("%d", &v[i]);

    for(i=0;i<q;i++){
      scanf("%lld", &k);
      printf("%d\n" , b_search(k, 0, n-1));
    }
    
    
  }

  return 0;
}
