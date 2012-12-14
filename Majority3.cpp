#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  int T,i,j,k,n,a,b;
  scanf("%d", &T);
  
  while(T--){
    scanf("%d",&n);
    vi v(n);
    for(i=0;i<n;i++) scanf("%d",&v[i]);
    sort(all(v));

    int ub=upper_bound(all(v),v[0])-v.begin();
    if(ub>n/2){
      printf("YES %d\n",v[0]);
      continue;
    }
    
    int lb=lower_bound(all(v),v[n-1])-v.begin();
    if(n-lb>n/2){
      printf("YES %d\n",v[n-1]);
      continue;
    }
    
    printf("NO\n");
  }
    
  return 0;
}

