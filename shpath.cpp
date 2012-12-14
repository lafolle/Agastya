#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <cassert>

#define SENTINEL 1000000
#define pl printf("\n")
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef vector<vector<int> > vvi; // use vi [] instead
typedef vector<int> vi;
typedef vector<vector<pair<int, int> > > vvpii; 
typedef vector<pair<int, int> > vpii;
typedef vector<pair<string, string> > vpss;
typedef vector<long long int> vlli;
typedef map<string,int> msi;
typedef pair<int,int> pii;


#define LIMIT 10001

int n;
vi d(LIMIT); // need to be used
vi adjcnt(LIMIT);
vector<string> cities(LIMIT),srcq(100),dstq(100);
bool visited[LIMIT];
char input[10]={'\0'},src[10]={'\0'},dst[10]={'\0'};
vector<pair<int, int> > AL[LIMIT];

vector<pii> nodes(LIMIT);
typedef priority_queue<pii,vector<pii>,greater<pii> > Priority_queue;

int solve(int srci, int dsti)
{
  int i,k,min_cost=0,al_size,neigh,cost,p;
  Priority_queue Q;
  fill(visited,visited+1+n,false);
  fill(d.begin(),d.begin()+1+n,SENTINEL);
  nodes[srci].first=0;
  d[srci]=0;
  Q.push(nodes[srci]);
  
  pii node;
  // each node is visited only once
  while(!Q.empty()){
    node=Q.top();Q.pop();
    k=node.second;
    p=node.first;
    
    if(visited[k])continue;
    visited[k]=true;
    if(k==dsti)return d[k];
    
    al_size=adjcnt[k];
    if(p<=d[k]){
      for(i=0;i<al_size;i++){
	neigh=AL[k][i].first;
	cost=AL[k][i].second;
	if(!visited[neigh]&&d[neigh]>d[k]+cost){
	  d[neigh]=d[k]+cost;
	  Q.push(make_pair(d[neigh],neigh));
	}
      }
    }
    
  }
}

int main()
{
  int t,r,p,i,j,k,m,nr,cost;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);

    for(i=0;i<n;i++){
      scanf("%s",input);
      cities[i+1]=string(input);
      nodes[i+1]=make_pair(SENTINEL,i+1);
      scanf("%d",&p);
      adjcnt[i+1]=p;
      for(j=0;j<p;j++){
	scanf("%d %d",&nr,&cost);
	AL[i+1].push_back(make_pair(nr,cost));
      }
    }

    scanf("%d",&r);
    for(j=0;j<r;j++){
      scanf("%s %s",src,dst);
      srcq[j]=string(src);
      dstq[j]=string(dst);
    }    

    // solve
    int min_cost=0;
    for(j=0;j<r;j++){
      k=find(cities.begin(),cities.begin()+n+1,srcq[j])-cities.begin();
      m=find(cities.begin(),cities.begin()+n+1,dstq[j])-cities.begin();
      min_cost=solve(k,m);
      printf("%d\n",min_cost);
    }
  }
}

