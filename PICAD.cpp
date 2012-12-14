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
#define ii(x,y) (make_pair(x,y))
#define SENTINEL 1000000001


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
typedef pair<lli ,lli > plli;
typedef vector< plli > vplli;

vplli v;

int main()
{
  int t=10;
  int in,out,n;
  lli tp,i,j,k,p,s,minp,maxp;
  
  while(t--){
    
    scanf("%lld %lld",&p, &k);
    scanf("%d",&n);
    
    if(p==k){
      maxp=0;minp=0;
      for(i=0;i<n;i++){
	scanf("%d %d",&in,&out);
	if(in==p||out==p)++minp;
      }
      maxp=minp;
    }
    else{
      for(i=0;i<n;i++){
	scanf("%d %d",&in, &out);
	v.push_back(ii(in,0));
	v.push_back(ii(out,1));
      }
      s=0;
      tp=2*n;
      
      sort(all(v));
      
      for(i=0;i<tp&&v[i].first<p;i++){
	if(v[i].second==0)++s;
	if(v[i].second==1)--s;
      }
      
      maxp=s;minp=s;
      for(j=i;j<tp&&v[j].first<=k;j++){
	if(v[j].second==0){
	  ++s;
	  maxp=max(maxp,s);
	}
	if(v[j].second==1){
	  if(v[j].first!=k){
	    --s;
	    minp=min(minp,s);
	  }
	  else{
	    minp=min(minp,s);
	    --s;
	  }
	}
      }
    }


    printf("%lld %lld\n",minp,maxp);

    v.clear();
  }
  
  return 0;
}

// ...WA
