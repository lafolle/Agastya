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

struct Point{
  int x; int y;
  Point(){}
  Point(int a,int b){
    x=a;
    y=b;
  }
  void operator=(Point a){
    this->x=a.x;
    this->y=a.y;
  }
};


Point P0;

struct by_polar{
  bool operator()(const Point &a, const Point &b){
    return true;
  }
};

int main()
{
  int t,i,j,k,a,b,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vector<Point> points;
    for(i=0;i<n;i++){
      scanf("%d %d",&a,&b);
      points.push_back(Point(a,b));
    }
  }
  return 0;
}

/* In progress */
