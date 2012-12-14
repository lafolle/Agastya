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

#define  pl cout<<endl
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000000

typedef vector<vector<pair<int, int > > > vvpii;
typedef vector<pair<int, int> > vpii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

struct Node{
  int d; // distanvce from source node
  int u; // unique index of node
  int anscestor; // ancestor of node
  bool visited;
  Node(){
    d=0;
    u=0;
    visited=false;
  }
  Node(int ind, int dist){
    d=dist;
    u=ind;
    visited=false;
  }
  bool operator<(const Node &a){
    return this->d<a.d;
  }
  bool operator>(const Node &a){
    return this->d>a.d;
  }
  Node operator=(const Node &a){
    Node t;
    t.d=a.d;
    t.u=a.u;
    return t;
  }
  bool operator==(const Node &a){
    return this->d==a.d;
  }
};

int n;
vvpii  AL(100);
void dfs(int srci, const vvpii &AL, const vi &adjcnt, vb &visited, vi &ancestor, vi &dist)
{
  int i;
  for(i=0;i<adjcnt[srci];i++){
    if(visited[AL[srci][i].first]) continue;
    ancestor[AL[srci][i].first]=srci;
    dist[AL[srci][i].first]+=1;
    dfs(AL[srci][i].first, AL, adjcnt, visited,ancestor,dist);
  }
}

int main()
{
  int i,j,k,adj,ai,ac;
  cin>>n;
  vb visited(n,false);
  vi ancestor(n);

  vi adjcnt(n);

  for(i=0;i<n;i++){
    scanf("%d",&adj);
    adjcnt[i]=adj;
    for(j=0;j<adj;j++){
      scanf("%d %d",&ai,&ac);
      AL[i].push_back(make_pair(ai,ac));
    }
  }
  
  return 0;
}

/*
  Using bloody approach of CLRS. Its awesome.
  Start to code, assuming you already have
  data structures/function ready!
*/
