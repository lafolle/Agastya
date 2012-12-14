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

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define INF 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;


char maze[1001][1001];
bool visited[1001][1001];
int d[1001][1001];

int c,r;

bool valid(int i, int j){return (i>=0&&i<r)&&(j>=0&&j<c);}

bool isleaf(int i, int j)
{
  int d=4;
  
  if(!valid(i-1,j)) --d;
  else if(maze[i-1][j]=='#') --d;

  if(!valid(i+1,j)) --d;
  else if(maze[i+1][j]=='#') --d;

  if(!valid(i,j-1)) --d;
  else if(maze[i][j-1]=='#') --d;

  if(!valid(i,j+1)) --d;
  else if(maze[i][j+1]=='#') --d;

  return d==1;
 }
  
ppiii dfs(pii p)
{
  int i,j,k,md=-INF;
  int rx=p.first, ry=p.second;

  for(i=0;i<r;i++)
    for(j=0;j<c;j++){
      d[i][j]=0;
      visited[i][j]=false;
    }
  
  pii tp,oc;
  stack<pii> S;
  S.push(p);

  while(!S.empty()){

    tp=S.top();S.pop();

    rx=tp.first; ry=tp.second;
    if(visited[rx][ry]) continue;

    visited[rx][ry]=true;

    if(isleaf(rx,ry) && d[rx][ry]>md){
      md=d[rx][ry];
      oc=make_pair(rx,ry);
    }

    if(valid(rx-1,ry) && maze[rx-1][ry]=='.'){
      d[rx-1][ry]=d[rx][ry]+1;
      S.push(make_pair(rx-1,ry));
    }

    if(valid(rx+1, ry) && maze[rx+1][ry]=='.'){
      d[rx+1][ry]=d[rx][ry]+1;
      S.push(make_pair(rx+1, ry));
    }

    if(valid(rx, ry+1) && maze[rx][ry+1]=='.'){
      d[rx][ry+1]=d[rx][ry]+1;
      S.push(make_pair(rx,ry+1));
    }

    if(valid(rx,ry-1) && maze[rx][ry-1]=='.'){
      d[rx][ry-1]=d[rx][ry]+1;
      S.push(make_pair(rx,ry-1));
    }
    
  }

  return make_pair(oc, md);

}

int main()
{
  int i,j,k,t;

  scanf("%d",&t);

  while(t--){

    scanf("%d %d",&r, &c);

    for(i=0;i<r;i++) scanf("%s",maze[i]);
    
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){

	if(maze[i][j]=='#') continue;

	if(isleaf(i,j))
	  goto there;
	
      }
    }

  there:
    printf("%d %d\n",i,j);exit(1);
    printf("%d\n", (dfs((dfs(make_pair(i,j))).first)).second);
  }
  return 0;
}

