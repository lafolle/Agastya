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

#define pl printf("\n")
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000000

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef set<pair<int, int> > spii;
typedef vector<pair<string, string> > vpss;
typedef vector<pair<int, int> > vpii;

int n;
vi D(10001,SENTINEL),adjcnt(10001);
char input[10]={'\0'},src[10]={'\0'},dst[10]={'\0'};
vb visited(10001,false);
vpii AL[10001];
vpss query(100);
vs cities(10001);
msi names;

int dijkstra(int srci,int dsti)
{
  int i,j,k,v,cost;  
  spii S;
  pii p,top;
  fill(visited.begin(),visited.begin()+n+1,false);
  fill(D.begin(),D.begin()+n+1, SENTINEL);
  
  D[srci]=0;
  S.insert(pii(0,srci));
  
  while(!S.empty()){

    top=*(S.begin());
    S.erase(S.begin());

    int d = top.first, u = top.second;
    if(u==dsti) return D[dsti];

    for(i=0;i<adjcnt[u];i++){

      v=AL[u][i].first; cost = AL[u][i].second;
      if(D[v]>D[u]+cost){

	if(D[v]!=SENTINEL)
	  S.erase(find(all(S),make_pair(D[v],v)));
	
	D[v]=D[u]+cost;
	S.insert(make_pair(D[v],v));
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

    names.clear();
    
    for(i=1;i<=n;i++){
      scanf("%s",input);
      //      cities[i]=string(input);
      names.insert(make_pair(string(input),i));
      scanf("%d",&p);
      adjcnt[i]=p;
      for(j=0;j<p;j++){
	scanf("%d %d",&nr,&cost);
	AL[i].push_back(make_pair(nr,cost)); // add a neigh and cost
      }
    }
    
    scanf("%d",&r);
    for(j=0;j<r;j++){
      scanf("%s %s",src,dst);
      query[j]=make_pair(string(src),string(dst));
    }    

    // solve
    string s1,s2; 
    int srci,dsti;
    for(j=0;j<r;j++){
      s1=query[j].first;
      s2=query[j].second;
      srci=names[s1];dsti=names[s2];
      printf("%d\n",dijkstra(srci,dsti));
    }
    for(j=1;j<=n;j++)AL[j].clear();
  }

  return 0;
}
