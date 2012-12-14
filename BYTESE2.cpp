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
#define SENTINEL 1000001
#define ii(i,j) make_pair(i,j)


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

// in - 0, out - 1

vpii v;

int main()
{
  int t,i,j,k,n,s,m;
  scanf("%d",&t);
  pii p;
  
  while(t--){
    v.clear();
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d",&j,&k);
      v.push_back(ii(j,0));
      v.push_back(ii(k,1));      
    }

    sort(v.begin(),v.begin()+2*n);
    s=0,m=-SENTINEL;
    for(i=0;i<2*n;i++){
      p=v[i];
      if(p.second==0)s+=1;
      else s-=1;
      m=max(m,s);
    }
    printf("%d\n",m);
  }
  return 0;
}

