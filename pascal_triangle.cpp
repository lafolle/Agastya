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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

#define  N 100

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

vvi P(N,vi(N,0));


// O(n^2)
void generate_pascal_triangle()
{
  int i,j;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      P[i][j]=i==0||j==0?1:P[i][j-1]+P[i-1][j];
}

int main()
{
  generate_pascal_triangle();
  
  return 0;
}

