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
  int w;
  int u,v;
  Edge(){}
  Edge(int i,int j,int wt){
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
  int i,t,cc,degree,j,k,neigh,cost,edge_count=0;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&cc);
    ++cc;

    vector<Edge> E;
    vector<vector<Edge> > AL;
    vi epn;
    
    for(i=1;i<cc;i++){
      vector<Edge> edge_list;
      create_set(i);
      char input[10]={'\0'};
      scanf("%s",input); // just do it for the sake of ass
      scanf("%d",&degree);
      for(j=0;j<degree;j++){
	scanf("%d %d",&neigh,&cost);
	edge_list.push_back(Edge(i,neigh,cost));
      }
      AL.push_back(edge_list);
      epn.push_back(j);
    }

    Edge eg;
    // extract edges
    edge_count=0;
    for(i=1;i<cc;i++){
      int k=epn[i-1];
      for(j=0;j<k;j++){
	eg=AL[i-1][j];
	if(eg.v>i){
	  E.push_back(eg);
	  edge_count++;
	}
      }
    }

    //    cout<<"Edge count="<<edge_count<<endl;

    // Kruskal's algorithm (pg - 631)
    sort(E.begin(),E.begin()+edge_count,sort_by_edge_weight());
    //    for(i=0;i<edge_count;i++) cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<endl;

    int min_cost=0;
    for(i=0;i<edge_count;i++){
      eg=E[i];
      find_set(eg.u);
      find_set(eg.v);
      if(p[eg.u]!=p[eg.v]){
	merge_sets(eg.u,eg.v);
	min_cost+=eg.w;
      }
    }
    printf("%u\n",min_cost);
  }

  return 0;
}

void show_parents()
{
  cout<<"\nShowing parents\n";
  int i;
  for(i=0;i<n;i++) cout<<i<<' '<<p[i]<<endl;
}

/*
  2 heuristics are :-
  1. union by rank
  2. path compression

  **path compression**
  
  Let 2 subtrees by a and b.
  
  if rank[a]<rank[b], then all members of
  find-set(a) will point to find-set(b), else
  vice-versa.
  In case of tie, ie, rand[a]==rank[b], any one
  is chosen at random and is pointed to other.

  **path compression**
  Done and understood.

  **Regarding implementation**
  
  So, got SIGABRT in first submission. Using 2D
  vector of 10000*10000 size, which indeed is shit.
  So, matrix representation of graph wont work.
  So, need to go for lined-list representation.

  Changed implementation to adjacency-list.
  Got AC at 1.32

  Also see list implementation of AL with AC at
  1.95
*/


