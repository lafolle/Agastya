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

#define pl printf("\n")
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long int  lli;

// without reversing
void tobinary_optimal(int n)
{
  int k=1,s=0,g=1<<30,lim=31;;
  vb bin;
  for(;!(g&n);g>>=1,--lim); // get last digit set
  while(s<lim) bin.pb(n&g>>s++);
  copy(all(bin),ostream_iterator<bool>(cout, ""));pl;
}  

void tobinary(int n)
{
  int k=1,s=0,g=1<<30,lim=31;;
  vb bin;
  for(;!(g&n);g>>=1,--lim);
  while(s<lim)
    bin.pb(n&k<<s++);
  reverse(all(bin));
  copy(all(bin),ostream_iterator<bool>(cout, ""));pl;
}  

int todecimal(int n, int b)
{
  int res=0, m=1;
  while(n){
    res=n%10*m;
    m*=b;
    n/=10;
  }
  return res;
}


void binrep(lli n, vi &bn)
{
  int i,k;
  lli j=1LL<<63;
  for(i=0;i<64;i++)if(((n<<i)&j)==j)break;
  k=63-i;
  for(i=0;i<=k;i++)bn.push_back((n>>i)&1);
  // copy(all(bn),ostream_iterator<int>(cout,""));pl;
}

lli modexp(int a,int b,int n)
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


void getline(char *line)
{
  int i=0;
  char ch;
  while((ch=getchar())!='\n')
    line[i++]=ch;
}

int main()
{
  char line[25];
  lli d=modexp(2,2,1000000009);
  cout<<d<<endl;

  return 0;
}

