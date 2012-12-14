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
  int T,n,k,a,i,c,j;
  scanf("%d", &T);
  
  while(T--){
    scanf("%d %d", &n, &k);
    vi v(n),res(n);
    for(i=0;i<n;i++) scanf("%d", &v[i]);

    for(j=0;j<k;j++){
      for(i=0;i<n;i++){
	if(!i) a=n-1;
	else a=i-1;
	c=(i+1)%n;
	v[i]=v[a]&v[i]&v[c];
      }
    }

    //    copy(all(v), ostream_iterator<int>(cout," "));pl;
    for(i=0;i<n;i++)
      printf("%d ",v[i]);
    pl;
  }
  return 0;
}

