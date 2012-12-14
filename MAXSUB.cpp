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
typedef long long int lli;
typedef vector<lli> vlli;

void binrep(lli n, vi &bn)
{
  int i,k;
  lli j=1LL<<63;
  for(i=0;i<64;i++)if(((n<<i)&j)==j)break;
  k=63-i;
  for(i=0;i<=k;i++)bn.push_back((n>>i)&1);
  // copy(all(bn),ostream_iterator<int>(cout,""));pl;
}

lli modexp(lli a,lli b,lli n)
{
  lli c=0,d=1;
  int i,k;
  vi bn;
  binrep(b,bn);
  k=sz(bn);
  for(i=k-1;i>=0;i--){
    c=2*c;
    d=(d*d)%n;
    if(bn[i]){
      c+=1;
      d=(d*a)%n;
    }
  }
  return d;
}


#define MN 1000000009

int main()
{
  
  int t,i,j,zc,n;
  lli sum,k;
  vlli v;
  scanf("%d",&t);
  while(t--){
    v.clear();
    sum=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%lld",&k);
      v.push_back(k);
    }

    sort(all(v));
    zc=count(all(v),0LL);

    if(v[0]==0&&v[n-1]>0){
      sum=accumulate(all(v),(lli)0);
      printf("%lld %lld\n",sum,(modexp(2,zc,MN)));
    }
    else if(v[0]==0 && v[n-1]==0){
      printf("%d %lld\n",0, modexp(2,zc,MN)-1);
    }
    else if(v[0]>0){
      sum=accumulate(all(v),(lli)0);
      printf("%lld %d\n",sum,1);
    }
    else if(v[0]<0&&v[n-1]>0){ // - 0 +
      for(i=n-1;i>=0&&v[i]>0;i--)sum+=v[i];
      if(zc)
	printf("%lld %lld\n",sum,(modexp(2,zc,MN)));
      else printf("%lld %d\n",sum,1);
    }
    else if(v[0]<0&&v[n-1]<0){ // all -
      lli lc=(lli)count(all(v),v[n-1]);
      printf("%lld %lld\n",v[n-1],lc);
    }
    else if(v[0]<0&&v[n-1]==0){
      printf("%d %lld\n",0,modexp(2,zc,MN)-1);
    }
    
  }
  return 0;
}


// AC at 0.74

