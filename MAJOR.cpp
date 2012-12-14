/* After spending 5-6 on the problem,
   in spite of its fucking easiness,
   I coded and tested the solution in
   less than 5 min.

   Lesson - Think less, only what is needed.
*/


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
  int T,i,j,k,n,rc,lc;
  scanf("%d",&T);

  while(T--){
    scanf("%d",&n);
    rc=0;lc=0;
    vi v(n);
    for(i=0;i<n;i++) scanf("%d", &v[i]);

    sort(all(v));

    k=v[n/2];
    for(i=n/2;i>-1;i--){
      if(v[i]==k) ++lc;
      else break;
    }

    for(i=(n/2)+1;i<n;i++){
      if(v[i]==k) ++rc;
      else break;
    }
    
    if(rc+lc>n/2) printf("YES %d\n",v[n/2]);
    else printf("NO\n");
  }
  return 0;
}

