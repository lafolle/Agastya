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
#define pb(x) push_back(x)

typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;

vi AL[10000];
vb visited(10000);
int allvol=0;

int dfs(int r)
{
  int i,adjcnt=sz(AL[r]),chvol=0,rvol,c=0;
  visited[r]=true;  
  if(adjcnt==1&&visited[AL[r][0]]){
    allvol+=1;
    return 1;
  }
  
  for(i=0;i<adjcnt;i++){
    if(!visited[AL[r][i]]){
      chvol+=dfs(AL[r][i]);
      ++c;
    }
  }
  
  rvol=chvol+c+1;
  allvol+=rvol;
  return rvol;
}

int main()
{
  int t,i,j,k,n;
  int n1,n2;

  scanf("%d",&t);

  while(t--){
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
      scanf("%d %d",&n1,&n2);
      AL[n1].pb(n2);

      AL[n2].pb(n1);      
    }
    dfs(0);    
    printf("%d\n",allvol);

    for(i=0;i<n;i++)AL[i].clear();
    fill(visited.begin(),visited.begin()+n,false);
    allvol=0;
  }
  return 0;
}

/*
  AC at 0.22
  Rank - 3401
*/
