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

int A[100],M[100],n;

int compute()
{
  int i,j,k,m=-1;

  M[0]=A[0];
  
  for(i=1;i<n;i++){
    M[i]=max(M[i-1]+A[i],A[i]);
    m=max(M[i],m);
  }

  return m;
}

int main()
{
  int i,j,k;
  scanf("%d", &n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  cout<<compute()<<endl;
  return 0;
}

