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
#define ii(x,y) make_pair(x,y)

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

int A[100000],M[100000],n;
int maxsum;

pii compute()
{
  int i,j,k;
  int mx,cnt;

  M[0]=A[0];
  mx=A[0];

  for(i=1;i<n;i++){
    if(M[i-1]+A[i]>A[i])
      M[i]=M[i-1]+A[i];
    else
      M[i]=A[i];
  }

  mx=*max_element(M,M+n);
  int c=0;
  for(i=0;i<n;i++)
    if(M[i]==mx)++c;
  if(accumulate(A,A+n,0)==mx)++c;
  return ii(mx,c);
  
}


int main()
{
  int i,j,k,t;
  scanf("%d",&t);
  pii p;

  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    p=compute();
    printf("%d %d\n",p.first, p.second);
  }
  return 0;
}

// Wrong approach
