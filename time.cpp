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
using namespace __gnu_cxx;

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define alln(v,n) v.begin()+1,v.begin()+n
#define sz(v) v.size()
#define INF 1000001
#define pb push_back
#define PI 3.141592653589793


typedef unsigned int uint;
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

inline void unsetbit(unsigned int &n, int k) {n=n&(~(1<<k));}
inline void setbit(unsigned int &n, int k) {n=n|(1<<k);}
inline void toggle(unsigned int &n, int k) {n=n^(1<<k);}
inline uint gcd(uint a, uint b) {return !b?a:gcd(b,a%b);}
struct eqstr{bool operator()(const char* s1, const char* s2) const{return !strcmp(s1, s2);}};

const int mp[12]={31,28,31,30,31,30,31,30,31,30,31,30};
const int sind = 24*60*60; // seconds in a day
const int epoch_year = 1970;
const int epoch_day = 1;
const int epoch_month = 0;

bool isleap(int year){return year%4==0 && year%100!=0 || year%400;}

int daysmonth(int month, int year)
{
  if(month==1) return isleap(year) ? 29 : 28;
  else return mp[month];
}


int main()
{
  int mn, yr, hr, mnu, i, m, y;

  lli net_sec=0;

  scanf("%d %d %d %d", &mn, &yr, &hr, &mnu);


  // years
  for(y=epoch_year;y<yr;y++)
    for(m=0;m<12;m++)
      net_sec += daysmonth(m, y)*sind;


  // months
  for(i=0;i<mn%12;i++) net_sec += daysmonth(i, yr)*sind;


  // hours
  net_sec += hr*3600;

  // second
  net_sec += mnu*60;

  printf("%lld\n", net_sec);
  
  return 0;
}

