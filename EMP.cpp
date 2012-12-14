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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
  long long int m,n;
  while(scanf("%lld %lld",&m,&n)!=EOF){
    if(n==m)printf("%lld\n",n+1);
    else printf("0\n");
  }
  return 0;
}

/*

  Left.
  
  n - at most n people who work more than me.
  m - at least m people who are paid more than me.

  Lets consider an example.
  There are at most 6 people who work more than me.
  There are at least 5 people who earn  more than me.
  
*/
