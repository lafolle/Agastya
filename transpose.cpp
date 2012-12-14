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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  int m,n;
  vvi M(m,vi(n,0)), M_t(m,vi(n,0));

  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      M_t[j][i]=M[i][j];
  
  return 0;
}

