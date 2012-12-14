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
#define pb push_back


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

int main()
{
  int n, b;

  while(n){
    scanf("%d",&n);
    tobinary_optimal(n);
  }
  return 0;
}

