#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back
typedef vector<vector<int> > vvi;

int main()
{
  int i,j,k,t,n,p;
  scanf("%d", &t);
  long long int ans=1;
	
  while(t--){
    vvi v(13);
    ans=1;
    scanf("%d %d", &n, &k);
    for(i=1;i<=k;i++){
      scanf("%d %d", &j, &p);
      if(j<k) v[j].pb(p);
      else v[p].pb(j);
    }
    for(i=1;i<=n;i++){
      int s = v[i].size();
      if(!s)continue;
      ans *= s;
    }
    printf("%lld\n", ans);
  }
	
  return 0;
}
