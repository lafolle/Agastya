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
#define pb push_back


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


vi AL[10001],adjcnt(10001),ts, visited(10001);
int n,m;

bool path(int i, int j)
{
  if(i==j) return true;

  int k;
  bool f=false;
  for(k=0;k<adjcnt[i];k++)
    if(path(AL[i][k], j)) return true;
  return false;
}

struct cmp{

  bool operator()(const int i,const int j){
    if(i<j && !(path(i,j) || path(j,i))) return true;
    return false;
  }
  
};

bool cycle(int root)
{
  if(visited[root]) return true;

  visited[root]=true;
  
  int i;
  for(i=0;i<adjcnt[root];i++)
    if(cycle(AL[root][i]))return true;

  return false;
}

bool dfs(int r)
{

  int i,j,k;

  if(visited[r])
    return false;

  visited[r]=true;
  bool f=true;
  for(i=0;i<adjcnt[r];i++)
    if(!dfs(AL[r][i])) break;
      
  if(!f) return false;
  ts.pb(r);
  return true;
}


int main()
{
  int i,j,k,x,y;

  while(scanf("%d %d",&n, &m)!=EOF){

    fill(adjcnt.begin()+1, adjcnt.begin()+1+n, 0);
    fill(visited.begin()+1, visited.begin()+1+n, false);
    
    for(i=0;i<m;i++){

      scanf("%d %d", &x, &y);

      AL[x].pb(y);
      adjcnt[x]+=1;

    }


    
    for(i=1;i<=n;i++)
      if(!visited[i])
	if(cycle(i))cout<<"Cycle present\n";

    exit(1);
    
    copy(all(ts), ostream_iterator<int>(cout, " "));pl;

    reverse(all(ts));
    sort(all(ts), cmp());

    copy(all(ts), ostream_iterator<int>(cout, " "));pl;

    // clean up
    ts.clear();
    for(i=1;i<=n;i++)AL[i].clear();
  }
  
  return 0;
}

