#include <map>
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
#include <cassert>
#include <cstring>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

vvi M(100000,vi(100000));

int main()
{
  int i,j,k,n,q,x,y;
  long long int s=0;
  char op;
  while(scanf("%d %d",&n,&q)!=EOF){
    vector<long long int> v(n);
    for(i=0;i<n;i++)scanf("%lld",&v[i]);

    // preprocessing O(n^2)
    for(i=0;i<n;i++){
      s=-1;
      for(j=i+1;i<n;i++)
	if(v[i]+v[j]>s) s=v[i]+v[j];
      M[i][j]=s;
    }
    
    for(i=0;i<q;i++){
      scanf("%c %d %d",&op,&x,&y);
      cout<<M[x][y]<<endl;
    }
  }
  return 0;
}

