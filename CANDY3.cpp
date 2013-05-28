#include <cstdio>

using namespace std;

typedef long long int lli;

int main()
{
  int t;
  scanf("%d", &t);
  lli ans,k,n,i,sum;
  while(t--){
    sum=0; // accumulation of left overs
    scanf("%lld", &n);
    for(i=0;i<n;i++){
      scanf("%lld",&k);
      sum=(sum+k)%n;  
    }
    printf("%s\n", !sum?"YES":"NO");
  }

  return 0;
}

// AC
