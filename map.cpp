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

int main()
{
  int a[7] = {2,1,4,5,1,3,3};
  vi v(a,a+7);
  vector<pair<int, int> > vp;
  int i;
  for(i=0;i<7;i++)
    vp.push_back(make_pair(v[i],i));

  sort(all(vp));

  for(i=0;i<7;i++)
    cout<<vp[i].first<< ' '<<vp[i].second<<endl;
  
  return 0;
}

