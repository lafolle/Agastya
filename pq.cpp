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
#include <queue>
#include <iterator>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{

  int a[4] =  {1,2,6,3};
  vi v(a,a+4);

  map<int, int> m(4);
  int i=0;
  map<int,int>::iterator it=m.begin();
  while(i<4){
    *iterator=make_pair(v[i],i);
    ++iterator;
    ++i;
  }

  for(i=0;i<4;i++)
    cout<<m[i]<<endl;

  return 0;
}

