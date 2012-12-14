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


// before I found O(1) solution
int compute_squares(int n)
{
  int i,s=0;
  for(i=1;i<n+1;i++)
    s+=(n-i+1)^2;
  return s;
}

int main()
{
  int n;
  scanf("%d",&n);
  while(n!=0){
    printf("%d\n",n*(n+1)*(2*n+1)/6);
    scanf("%d",&n);
  }

  return 0;
}

