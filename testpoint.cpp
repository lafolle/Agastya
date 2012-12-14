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
  int x;
  int y;
  Point(){}
  Point(int a,int b){x=a;y=b;}
  Point operator-(const Point &a){
    return Point(this->x-a.x,this->y-a.y);
  }

  // comparision by Manhattan distance with 0,0 as base
  bool operator<(Point &p) const {
    return x+y < p.x+p.y;
  }
  bool operator>(Point &p){
    if(*this<p) return false;
    return true;
  }
};

Point BP;
int cross_prod(Point P1, Point P2)
{
  int res= (P1.x-BP.x)*(P2.y-BP.y)-(P2.x-BP.x)*(P1.y-BP.y);
  return res;
}

bool nonleftturn(const Point &t, const Point &nt, const Point &pp)
{
  BP=nt;
  int res= cross_prod(t,pp);
  return (res<0||res==0)?true:false;
}


int main()
{
  Point p1(5,0),p2(1,1),p3(0,5);
  cout<<nonleftturn(p2,p1,p3)<<endl;
  return 0;
}

