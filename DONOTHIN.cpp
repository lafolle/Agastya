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

int main()
{
  long long int n,i,m;

  while(true){
    scanf("%lld %lld",&n,&m);
    if(n==-1&&m==-1) break;
    vector<long long int> mem(n);
    vlli v(n);
    for(i=0;i<n;i++) scanf("%lld",&v[i]);
    mem[0]=v[0]*m;
    long long int s=0;    
    s=mem[0];
    for(i=1;i<n;i++){mem[i]=mem[i-1]+v[i]*m;s+=mem[i];}
    printf("%lld\n",s);
  }
  
  return 0;
}

