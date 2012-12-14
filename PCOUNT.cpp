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
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;

vb v(10000000,true);
vi primes;

void precompute(int n)
{
  int i,j,k,p,q,m,cnt;
  cnt=0;
  m=1;
  fill(v.begin(),v.begin()+n+1,true);
  v[0]=false;v[1]=false;
  q=sqrt(n);
  for(i=2;i<q+1;i++){
    if(!v[i]) continue;
    k=!(m/i)?2:(m/i)+1;
    p=i*k;
    for(j=k;p<n+1;j++,p=i*j)
      v[p]=false;
  }
    
  for(i=m;i<n+1;i++)
    if(v[i]){
      ++cnt;
      primes.pb(i);
    }


  printf("Precomputed.\n");
}

int main()
{
  int t,n;
  precompute(5000000);
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",primes[n-1]);
  }
  return 0;
}

