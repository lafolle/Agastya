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
typedef long long int lli;

lli gcd(lli a, lli b)
{
  if(!b) return a;
  return gcd(b, a%b);
}

lli lcm(lli a, lli b)
{
  return (a*b)/gcd(a,b);
}

int main()
{
  int t,i,j,k;
  long long int a,b;
  cin>>t;

  while(t--){

    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    
  }
  
  return 0;
}

