#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>

#define SENTINEL 200001
#define pl printf("\n")

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<pair<int, int> > > vvpii;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<string, string> > vpss;
typedef vector<pair<char*,char*> > vpcc;
typedef map<char*,int> msi;

int n;
vi d(10001,SENTINEL);
vi adjcnt(10001);

struct cmp{
  bool operator()(const int i, const int j) const {
    return d[i]>d[j];
  }
};

char *input={'\0'},*src={'\0'},*dst={'\0'};
bool visited[10001]={false};

int solve(vvpii &AL,msi &cities)
{
  printf("%s %s\n",src,dst);
  int i,j,k,min_cost=0,al_size,neigh,cost;
  priority_queue<int,vector<int>,cmp> Q;
  for(i=1;i<=n;i++) visited[i]=false;
  int srci=cities[src],dsti=cities[dst];
  for(i=1;i<=n;i++) d[i]=SENTINEL;
  Q.push(srci);
  d[srci]=0;
  int 1st=0;  
  while(!Q.empty()){
    k=Q.top();Q.pop();
    if(visited[k])continue;
    assert(d[k] >= lst);    
    if(k==dsti) break;
    al_size=adjcnt[k];
    
    for(i=0;i<al_size;i++){
      neigh=AL[k-1][i].first;
      cost=AL[k-1][i].second;
      if(d[neigh]>d[k]+cost){ // relax
	d[neigh]=d[k]+cost;
	Q.push(neigh);
      }
    }
    
  }
  return d[dsti];
}

int main()
{
  int t,r,p,i,j,k,m,nr,cost;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);

    msi cities;
    vpcc query;
    vvpii AL;

    for(i=0;i<n;i++){
      scanf("%s",input);
      cities[input]=i+1;
      scanf("%d",&p);
      adjcnt[i+1]=p;
      vpii adjlist;
      for(j=0;j<p;j++){
	scanf("%d %d",&nr,&cost);
	adjlist.push_back(make_pair(nr,cost));
      }
      AL.push_back(adjlist);
    }

    scanf("%d",&r);
    for(j=0;j<r;j++){
      scanf("%s %s",src,dst);
      query.push_back(make_pair(src,dst));
    }    

    // solve
    for(j=0;j<r;j++){
      src=query[i].first;
      dst=query[i].second;
      printf("%d\n",solve(AL,cities));
    }
  }
}

