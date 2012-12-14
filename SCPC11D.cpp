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
typedef vector<lli> vlli;

lli a,b,c;
vlli v(3);

int main()
{
  scanf("%lld %lld %lld", &v[0], &v[1], &v[2]);
  while(v[0] && v[1] && v[2]){

    sort(all(v));

    if(v[2]*v[2] == v[0]*v[0] + v[1]*v[1])
      printf("right\n");
    else printf("wrong\n");
    
    scanf("%lld %lld %lld", &v[0], &v[1], &v[2]);
    
  }

  return 0;
}

// AC
