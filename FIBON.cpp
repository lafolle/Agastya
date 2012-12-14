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

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef vector<lli> vlli;


int main()
{
  int t,n,i;
  lli j,k,c;
  vlli v(72);
  scanf("%d",&t);
  
  j=0LL;k=1LL;
  v[0]=j;
  v[1]=k;
  for(i=2;i<73;i++){
    c=j+k;
    v[i]=c;
    j=k;
    k=c;
  }
  while(t--){
    scanf("%d",&n);
    printf("%lld\n",v[n]);
  }
  return 0;
}

