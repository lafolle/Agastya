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

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001

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

char grid[1000][1000];
bool visited[1000][1000];
int n;

pii ii(int i, int j){return make_pair(i,j);}

bool valid(int x,int y)
{
  return (x>=0&&x<n) && (y>=0&&y<n);
}

// only right and bottom movements
int rbdfs(int x,int y)
{
  stack<pii> S;
  int pc=0;
  S.push(ii(x,y));
  pii tp;
  while(!S.empty()){
    tp=S.top();S.pop();
    
    if(tp.first==n-1&&tp.second==n-1){
      ++pc;//printf("%d\n",pc);
      continue;
    }
    x=tp.first;y=tp.second;

    if(valid(x+1,y)&&!visited[x+1][y]&&grid[x+1][y]=='.')S.push(ii(x+1,y));
    if(valid(x,y+1)&&!visited[x][y+1]&&grid[x][y+1]=='.')S.push(ii(x,y+1));
    
  }
  return pc;
}

// 4 directions
bool dfs(int x,int y)
{
  stack<pii> S;
  S.push(ii(0,0));
  pii tp;

  while(!S.empty()){
    tp=S.top();S.pop();
    x=tp.first;y=tp.second;
    if(x==n-1&&y==n-1) return true;

    visited[x][y]=1;

    if(valid(x+1,y)&&!visited[x+1][y]&&grid[x+1][y]=='.')S.push(ii(x+1,y));
    if(valid(x,y+1)&&!visited[x][y+1]&&grid[x][y+1]=='.')S.push(ii(x,y+1));
    if(valid(x-1,y)&&!visited[x-1][y]&&grid[x-1][y]=='.')S.push(ii(x-1,y));
    if(valid(x,y-1)&&!visited[x][y-1]&&grid[x][y-1]=='.')S.push(ii(x,y-1));

  }

  return false;
}

int main()
{
  int i,j,k;
  long long  int pc;
  while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++)scanf("%s",grid[i]);
    pc=rbdfs(0,0);

    if(!pc){
      for(i=0;i<n;i++)for(j=0;j<n;j++)visited[i][j]=0;
      if(!dfs(0,0))printf("INCONCEIVABLE\n");
      else printf("THE GAME IS A LIFE\n");
    }
    else printf("%lld\n",pc%((1LL<<31)-1));
    for(i=0;i<n;i++)for(j=0;j<n;j++)visited[i][j]=0;

  }

  return 0;
}

