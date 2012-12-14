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
  int T;
  scanf("%d",&T);

  while(T--){
    int n1,n2,i,j,c=1000001;
    scanf("%d",&n1);
    vi v1(n1);
    
    for(i=0;i<n1;i++) scanf("%d", &v1[i]);

    scanf("%d", &n2);
    vi v2(n2);
    for(i=0;i<n2;i++) scanf("%d", &v2[i]);

    for(i=0;i<n1;i++)
      for(j=0;j<n2;j++)
	c=min(c,abs(v1[i]-v2[j]));
    printf("%d\n",c);
  }
  return 0;
}

