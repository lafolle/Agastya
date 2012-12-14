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
typedef vector<long long int> vlli;
typedef vector<double> vd;

//vi v(10000);


int  v[100000];
struct cmp{
  bool operator()(int x,int y){
    if(x==1) return true;
    if(y==1) return false;
    if(x==2) return y==3;
    if(y==2) return !(x==3);
    return x>y;
  }
};

int main()
{
  int t,n,i,j,k;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&v[i]);
    sort(v,v+n,cmp());
    for(i=0;i<n;i++)printf("%d ",v[i]);
    pl;
  }
  return 0;
}

