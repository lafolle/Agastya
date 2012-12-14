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

void show_parents();

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
typedef vector<vector<pair<int,int> > > vvpii;

struct Edge{
  long long int  w;
  int u,v;
  Edge(){}
  Edge(int i,int j,long long int wt){
    u=i;
    v=j;
    w=wt;
  }
};

struct sort_by_edge_weight{
  bool operator()(const Edge &a,const Edge &b){
    return a.w<b.w;
  }
};

int n;
vi rank(10001);
vi p(10001);


void create_set(int i)
{
  p[i]=i;
  rank[i]=0;
}

int find_set(int x)
{
  if(p[x]!=x) p[x]=find_set(p[x]);
  return p[x];
}

void merge_sets(int x, int y)
{
  find_set(x);
  find_set(y);
  if(rank[p[x]]<rank[p[y]])
    p[p[x]]=p[y];
  else p[p[y]]=p[x];
  if(rank[p[x]]==rank[p[y]]) rank[p[x]]+=1; 
}

int main()
{
  int i,t,cc,degree,j,k,neigh,cost,edge_count=0,m,n,a,b;
  long long int w;
  scanf("%d %d",&n,&m);

  Edge eg;
  vector<Edge> E;

  for(i=1;i<n+1;i++) create_set(i);
  
  for(i=0;i<m;i++){
    scanf("%d %d %lld",&a,&b,&w);
    E.push_back(Edge(a,b,w));
  }
  
  // Kruskal's algorithm (pg - 631)
  sort(E.begin(),E.begin()+m,sort_by_edge_weight());
  long long int  min_cost=0;
  for(i=0;i<m;i++){
    eg=E[i];
    find_set(eg.u);
    find_set(eg.v);
    if(p[eg.u]!=p[eg.v]){
      merge_sets(eg.u,eg.v);
      min_cost+=eg.w;
    }
  }
  printf("%lld\n",min_cost);

  return 0;
}

void show_parents()
{
  cout<<"\nShowing parents\n";
  int i;
  for(i=0;i<n;i++) cout<<i<<' '<<p[i]<<endl;
}



