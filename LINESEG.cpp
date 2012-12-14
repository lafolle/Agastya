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
  void operator=(Point a){
    this->x=a.x;
    this->y=a.y;
  }
  int operator*(Point &p){
    int k;
    k=x*p.y-y*p.x;
    return k;
  }
  bool operator==(Point &p){
    return this->x==p.x&&this->y==p.y;
  }
  bool operator!=(Point &p){
    return x!=p.x||y!=p.y;
  }
  void show(){
    cout<<x<<' '<<y<<endl;
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
  int t;
  scanf("%d",&t);
  int d1,d2,d3,d4;
  while(t--){
    Point p1,p2,p3,p4;
    scanf("%d %d %d %d",&p1.x,&p1.y, &p2.x,&p2.y);
    scanf("%d %d %d %d",&p3.x,&p3.y, &p4.x,&p4.y);
    //        p1.show();p2.show();p3.show();p4.show();
    d1=direction(p3,p4,p1);
    d2=direction(p3,p4,p2);
    d3=direction(p1,p2,p3);
    d4=direction(p1,p2,p4);

    cout<<d1<<' '<<d2<<' '<<d3<<' '<<d4<<endl;
    //        exit(1);
    
    if((d1>0&&d2<0||d1<0&&d2>0)&&(d3>0&&d4<0||d3<0&&d4>0))
      printf("POINT\n");
    if(d1==0&&d2!=0&&onsegment(p3,p4,d1))
      printf("POINT\n");
    else if(d1!=0&&d2==0&&onsegment(p3,p4,d2))
      printf("POINT");
    else if(d3==0&&d4!=0&&onsegment(p1,p2,d3))
      printf("POINT");
    else if(d3!=0&&d4==0&&onsegment(p1,p2,d4))
      printf("POINT\n");
    else if(d1==0&&d2==0){
      1os=onsegment(p3,p4,p1);
      2os=onsegment(p3,p4,p2);
      if(1os2os
    }
    else if(d3==0&&d4==0){
    }
  }

  return 0;
}

/*if the two segments do not intersect at all, print "NO", and if they do,
  if they intersect at a point, print "POINT", otherwise if their intersection forms a segment,
  print "SEGMENT".

3
0 0 0 10
0 0 0 0
0 0 0 1
1 0 1 1
0 0 2 0
1 0 10 0

Chocked by the problem...boring...

*/
