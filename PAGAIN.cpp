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

lli limit=1LL<<31;

vb prime(limit+1,true);

int main()
{
  lli i=0,j;

  prime[1]=false;
  prime[2]=false;
  for(j=2;j<=limit>>1LL;j++)
    if(prime[j]){cout<<"Killing by "<< j<<endl;
      for(i=2;i<=limit/j;i++){
	prime[i*j]=false;
      }
    }
  for(i=1;i<=limit;i++)
    if(prime[i])printf("%lld\n",i);
  
  return 0;
}

