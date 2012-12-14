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

int main()
{
  int i,j,t;
  int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
  scanf("%d",&t);

  while(t--){

    scanf("%d %d %d %d %d %d %d %d %d %d", &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, &x10);

    printf("%d\n",(x1 || x2)^(x1 || x3)^(x1 || x4)^(x1 || x5)^(x1 || x6)^(x1 || x7)^(x1 || x8)^(x1 || x9)^(x1 || x10)^(x2 || x3)^(x2 || x4)^(x2 || x5)^(x2 || x6)^(x2 || x7)^(x2 || x8)^(x2 || x9)^(x2 || x10)^(x3 || x4)^(x3 || x5)^(x3 || x6)^(x3 || x7)^(x3 || x8)^(x3 || x9)^(x3 || x10)^(x4 || x5)^(x4 || x6)^(x4 || x7)^(x4 || x8)^(x4 || x9)^(x4 || x10)^(x5 || x6)^(x5 || x7)^(x5 || x8)^(x5 || x9)^(x5 || x10)^(x6 || x7)^(x6 || x8)^(x6 || x9)^(x6 || x10)^(x7 || x8)^(x7 || x9)^(x7 || x10)^(x8 || x9) ^ (x8 || x10) ^ (x9 || x10) ^ (x1 || x2 || x3) ^ (x1 || x2 || x4) ^ (x1 || x2 || x5) ^ (x1 || x2 || x6) ^(x1 || x2 || x7) ^ (x1 || x2 || x8) ^ (x1 || x2 || x9) ^ (x1 || x2 || x10) ^ (x1 || x3 || x4) ^ (x1 || x3 || x5) ^(x1 || x3 || x6) ^ (x1 || x3 || x7) ^ (x1 || x3 || x8) ^ (x1 || x3 || x9) ^ (x1 || x3 || x10) ^ (x1 || x4 || x5) ^(x1 || x4 || x6) ^ (x1 || x4 || x7) ^ (x1 || x4 || x8) ^ (x1 || x4 || x9) ^ (x1 || x4 || x10) ^ (x1 || x5 || x6) ^(x1 || x5 || x7) ^ (x1 || x5 || x8) ^ (x1 || x5 || x9) ^ (x1 || x5 || x10) ^ (x1 || x6 || x7) ^ (x1 || x6 || x8) ^(x1 || x6 || x9) ^ (x1 || x6 || x10) ^ (x1 || x7 || x8) ^ (x1 || x7 || x9) ^ (x1 || x7 || x10) ^ (x1 || x8 || x9) ^(x1 || x8 || x10) ^ (x1 || x9 || x10) ^ (x2 || x3 || x4) ^ (x2 || x3 || x5) ^ (x2 || x3 || x6) ^ (x2 || x3 || x7) ^(x2 || x3 || x8) ^ (x2 || x3 || x9) ^ (x2 || x3 || x10) ^ (x2 || x4 || x5) ^ (x2 || x4 || x6) ^ (x2 || x4 || x7) ^(x2 || x4 || x8) ^ (x2 || x4 || x9) ^ (x2 || x4 || x10) ^ (x2 || x5 || x6) ^ (x2 || x5 || x7) ^ (x2 || x5 || x8) ^(x2 || x5 || x9) ^ (x2 || x5 || x10) ^ (x2 || x6 || x7) ^ (x2 || x6 || x8) ^ (x2 || x6 || x9) ^ (x2 || x6 || x10) ^(x2 || x7 || x8) ^ (x2 || x7 || x9) ^ (x2 || x7 || x10) ^ (x2 || x8 || x9) ^ (x2 || x8 || x10) ^ (x2 || x9 || x10) ^(x3 || x4 || x5) ^ (x3 || x4 || x6) ^ (x3 || x4 || x7) ^ (x3 || x4 || x8) ^ (x3 || x4 || x9) ^ (x3 || x4 || x10) ^(x3 || x5 || x6) ^ (x3 || x5 || x7) ^ (x3 || x5 || x8) ^ (x3 || x5 || x9) ^ (x3 || x5 || x10) ^ (x3 || x6 || x7) ^(x3 || x6 || x8) ^ (x3 || x6 || x9) ^ (x3 || x6 || x10) ^ (x3 || x7 || x8) ^ (x3 || x7 || x9) ^ (x3 || x7 || x10) ^(x3 || x8 || x9) ^ (x3 || x8 || x10) ^ (x3 || x9 || x10) ^ (x4 || x5 || x6) ^ (x4 || x5 || x7) ^ (x4 || x5 || x8) ^(x4 || x5 || x9) ^ (x4 || x5 || x10) ^ (x4 || x6 || x7) ^ (x4 || x6 || x8) ^ (x4 || x6 || x9) ^ (x4 || x6 || x10) ^(x4 || x7 || x8) ^ (x4 || x7 || x9) ^ (x4 || x7 || x10) ^ (x4 || x8 || x9) ^ (x4 || x8 || x10) ^ (x4 || x9 || x10) ^(x5 || x6 || x7) ^ (x5 || x6 || x8) ^ (x5 || x6 || x9) ^ (x5 || x6 || x10) ^ (x5 || x7 || x8) ^ (x5 || x7 || x9) ^(x5 || x7 || x10) ^ (x5 || x8 || x9) ^ (x5 || x8 || x10) ^ (x5 || x9 || x10) ^ (x6 || x7 || x8) ^ (x6 || x7 || x9) ^(x6 || x7 || x10) ^ (x6 || x8 || x9) ^ (x6 || x8 || x10) ^ (x6 || x9 || x10) ^ (x7 || x8 || x9) ^ (x7 || x8 || x10) ^(x7 || x9 || x10) ^ (x8 || x9 || x10));


    
  }
  return 0;
}

// AC
