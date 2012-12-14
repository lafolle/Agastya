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

typedef vector<Point> vp;
Point BP;

int cross_prod(Point P1, Point P2)
{
  int res= (P1.x-BP.x)*(P2.y-BP.y)-(P2.x-BP.x)*(P1.y-BP.y);
  return res;
}

bool dup_pred(Point P1, Point P2)
{
  return (P1.x-BP.x)*(P2.y-BP.y)-(P2.x-BP.x)*(P1.y-BP.y)==0?true:false;
}

bool nonleftturn(const Point &t, const Point &nt, const Point &pp)
{
  BP=nt;
  int res= cross_prod(t,pp);
  return (res<0||res==0)?true:false;
}

/* Before this, base point needs to be set. */
struct polar_cmp{
  bool operator()(const Point &P1, const Point &P2){
    int cp=cross_prod(P1,P2);
    if(cp>0) return true;
    if(cp<0) return false;
    //    return P1<P2?true:false;
    return P1.x+P1.y>P2.x+P2.y?true:false;
  }
};

/* Get base point */
Point minyx(vp &v,int n)
{
  int i,xmin,ymin;
  xmin=v[0].x;ymin=v[0].y;
  for(i=1;i<n;i++){
    if(v[i].y<ymin){
      ymin=v[i].y;
      xmin=v[i].x;
    }
    else if(v[i].y==ymin && v[i].x<xmin)
      xmin=v[i].x;
  }
  return Point(xmin,ymin);
}

int main()
{
  int t,n,i,a,b;
  cin>>t;
  vector<Point> v;
  
  while(t--){
    cin>>n;
    for(i=0;i<n;i++){
      cin>>a>>b;
      v.push_back(Point(a,b));
    }

    // set base_point
    BP=minyx(v,n);
    cout<<"BP : "<<BP.x<<' '<<BP.y<<endl;
    sort(all(v),polar_cmp());
    int newlast=unique(all(v),dup_pred)-v.begin();
    Point t,nt,pp;
    stack<Point> S;
    S.push(BP);
    S.push(v[0]);
    S.push(v[1]);

    cout<<"Displaying data...\n";
    for(i=0;i<newlast;i++) cout<<v[i].x<<' '<<v[i].y<<endl;
    cout<<"Done\n";
    
    for(i=2;i<newlast;i++){
      t=S.top();S.pop();
      nt=S.top();S.push(t);
      while(i<newlast && nonleftturn(t,nt,v[i])){
	cout<<S.top().x<<' '<<S.top().y<<endl;
	S.pop();
	++i;
      }
      if(i!=newlast) S.push(v[i]);
    }

    while(!S.empty()){
      t=S.top();
      S.pop();
      cout<<t.x<<' '<<t.y<<endl;
    }
  }
  return 0;
}


