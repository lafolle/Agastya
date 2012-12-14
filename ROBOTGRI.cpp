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

char grid[1000][1000];
bool visited[1000][1000];
int n;

bool valid(int x,int y)
{
  return (x>=0&&x<n) && (y>=0&&y<n);
}

int rbdfs(int x,int y,long long int pc)
{
  if(x==n-1&&y==n-1){return 1LL;}
  visited[x][y]=1;
  long long int lpc=0;
  
  if(valid(x+1,y)&&!visited[x+1][y]&&grid[x+1][y]=='.')
    lpc+=rbdfs(x+1,y,pc);

  if(valid(x,y+1)&&!visited[x][y+1]&&grid[x][y+1]=='.')
    lpc+=rbdfs(x,y+1,pc);

  visited[x][y]=0;
  return lpc;
}

bool dfs(int x,int y)
{
  if(x==n-1&&y==n-1)return true;
  visited[x][y]=1;

  if(valid(x+1,y)&&!visited[x+1][y]&&grid[x+1][y]=='.')
    if(dfs(x+1,y))return true;
  if(valid(x,y+1)&&!visited[x][y+1]&&grid[x][y+1]=='.')
    if(dfs(x,y+1))return true;
  if(valid(x-1,y)&&!visited[x-1][y]&&grid[x-1][y]=='.')
    if(dfs(x-1,y))return true;
  if(valid(x,y-1)&&!visited[x][y-1]&&grid[x][y-1]=='.')
    if(dfs(x,y-1))return true;

  return false;
}

int main()
{
  int i,j,k;
  long long  int pc;
  while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++)scanf("%s",grid[i]);
    
    pc=rbdfs(0,0,0);assert(pc>=0);

    if(!pc){
      for(i=0;i<n;i++)memset(visited[i],0,sizeof(bool));
      if(!dfs(0,0))printf("INCONCEIVABLE\n");
      else printf("THE GAME IS A LIFE\n");
    }
    else printf("%lld\n",pc%((1LL<<31)-1));

    for(i=0;i<n;i++)memset(visited[i],0,sizeof(bool));
  }

  return 0;
}

/*
  WA
*/
