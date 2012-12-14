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
#define SENTINEL 1000000

typedef vector<long long int> vlli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

int main()
{
  int t,n,m,i,j,k=1;
  long long int s;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vlli u(n),v(n);
    for(i=0;i<n;i++)scanf("%lld",&u[i]);
    for(i=0;i<n;i++)scanf("%lld",&v[i]);

    sort(all(u),greater<int>());
    sort(all(v));
    s=0;
    for(i=0;i<n;i++)s+=v[i]*u[i];
    printf("Case #%d: %lld\n",k++,s);
  }
  return 0;
}

