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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

struct Point{
  int x; int y;
  Point(){}
  Point(int a,int b){
    x=a;
    y=b;
  }
  Point operator-(const Point &p){
    Point tmp;
    tmp.x=this->x-p.x;
    tmp.y=this->y-p.y;
    return tmp;
  }
  void operator=(Point &a){
    this->x=a.x;
    this->y=a.y;
  }
  int operator*(Point &p){
    int k;
    k=x*p.y-y*p.x;
    return k;
  }
};

int direction(Point &p1,Point &p2,Point &p)
{
  Point a=p2-p1,b=p-p1;
  return a.x*b.y-a.y*b.x;
}

bool onsegment(Point p1,Point p2,Point p)
{
  int minx,maxx,miny,maxy;
  minx=min(p1.x,p2.x);
  maxx=max(p1.x,p2.x);
  miny=min(p1.y,p2.y);
  maxy=max(p1.y,p2.y);
  return (p.x>minx||p.x==minx)&&(p.x<maxx||p.x==maxx)&&(p.y>miny||p.y==miny)&&(p.y<maxy||p.y==maxy);
}


int main()
{
  cout<<"Different sides...\n";
  // different sides
  {
    Point p1(1,2),p2(3,4),p3(1,4),p4(3,0);
    cout<<direction(p1,p2,p3)<<endl;
    cout<<direction(p1,p2,p4)<<endl;
  }

  cout<<"Same sides...\n";  
  // same sides
  {
    Point p1(0,5),p2(5,5),p3(10,10),p4(0,6);
    cout<<direction(p1,p2,p3)<<endl;
    cout<<direction(p1,p2,p4)<<endl;
  }

  cout<<boolalpha;
  // on segment
  {
    Point p1(0,5),p2(5,5),p3(4,5),p4(0,6);
    cout<<onsegment(p1,p2,p3)<<endl;
    cout<<onsegment(p1,p2,p4)<<endl;    
  }

  // off segment
  {
    Point p1(0,5),p2(5,5),p3(10,10),p4(0,6);
    cout<<onsegment(p1,p2,p3)<<endl;
    cout<<onsegment(p1,p2,p4)<<endl;    
  }
  return 0;
}

