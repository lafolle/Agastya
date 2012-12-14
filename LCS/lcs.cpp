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

// Longeset common subsequence
// recursive approach
int lcs(string u, string v, int len)
{
  int ulen=u.length(),vlen=v.length();
  if(ulen==0 || vlen==0) return len;

  if(u[0]==v[0]) return lcs(u.substr(1,ulen), v.substr(1,vlen),len+1);


  return max( lcs(u, v.substr(1,vlen), len),
	      lcs(u.substr(1,ulen), v, len));
}


int main()
{
  string s1,s2;

  cin>>s1>>s2;


  cout<<"length(LCS) = "<<lcs(s1,s2,0)<<endl;
  
  return 0;
}

