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
#define SENTINEL 1000000

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

#define LEFT(i)  (i<<1)+1
#define RIGHT(i) (i<<1)+2
#define PARENT(i) (i%2?i>>1:(i>>1)-1) // doubt here

// min priority queue
class PriorityQueue{
  int n; 
  int hs; 
  vi v; // heap inner datastructure

public:
  PriorityQueue(int s);
  PriorityQueue(vi m, int s);

  void minifyheap(int i, int n);
  void buildheap(int n);
  void changekey(int k, int i);
  int getmin();
  void poptop();
};
  
