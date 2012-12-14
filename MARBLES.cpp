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
typedef vector<long long int> vlli;

double bcoff(double n,double r)
{
  double s=1,i;
  if(n-r<r)
    for(i=1;i<n-r+1;i++)
      s*=(1.0+(r/i));
  else
    for(i=1;i<r+1;i++)
      s*=(1.0+(n-r)/i);

  return s;
}

int main()
{
  int T;
  scanf("%d",&T);

  while(T--){
    long long int n,k,i;
    scanf("%lld %lld",&n,&k);
    if(n==k){
      printf("%d\n",1);
      continue;
    }
    printf("%f\n",bcoff(n-1,n-k));
  }
  return 0;
}

long long int bcoeff(int n,int r)
{
  long long int nr=1LL,dr=1LL,i;
  if(n-r<r){
    for(i=r+1;i<n+1;i++)
      nr*=i;
    for(i=1;i<n-r+1;i++)
      dr*=i;
  }
  else{
    for(i=n-r+1;i<n+1;i++)
      nr*=i;
    for(i=1;i<r+1;i++)
      dr*=i;
  }
  return nr/dr;
}


