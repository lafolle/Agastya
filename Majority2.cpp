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
typedef set<int> si;
typedef pair<int,int> pii;

int main()
{
  int T,i,j,k,n;
  scanf("%d",&T);
  
  while(T--){
    scanf("%d",&n);
    vi v(n);
    vi c(1000001);
    map<int,int> M;
    map<int,int>::iterator p;
    k=-2000;

    for(i=0;i<n;i++) scanf("%d",&v[i]);
    for(i=0;i<n;i++) ++M[v[i]];
    pii t=*max_element(all(M));
    if(t.second>n/2) printf("YES %d\n",t.first);
    else printf("NO\n");
  }
  return 0;
}

