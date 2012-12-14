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

#define ii(x,y) (make_pair(x,y))

pii getnextvacant(int x,int y)
{
  int i,j;
  if(y==15&&x==15) return ii(-1,-1);
  if(y==15){
    i=x+1;
    j=0;
  }
  else{
    i=x;
    j=y+1;
  }
  return ii(i,j);
  return ii(-1,-1);
}


int main()
{int i,x,y;
  for(i=0;i<1000000;i++);
  return 0;
}

