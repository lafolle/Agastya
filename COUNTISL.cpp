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

int n,m,cnt=0;
bool visited[201][201];
char arch[201][201];

void dfs(int i, int j)
{
  if(i<0||i>=n||j<0||j>=m||
       visited[i][j] ||
       arch[i][j]=='.')
     return;
     
     
  visited[i][j]=1;
  
  dfs(i,j+1);
  dfs(i,j-1);
  dfs(i+1,j);
  dfs(i-1,j);
  dfs(i+1,j+1);
  dfs(i+1,j-1);
  dfs(i-1,j+1);
  dfs(i-1,j-1);

}

int main()
{
  int i,j,k,t;

  scanf("%d", &t);

  while(t--){

    cnt=0;
    
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++)scanf("%s",arch[i]);
    memset(visited, 0, sizeof(bool)*201*201);
    //    for(i=0;i<n;i++)for(j=0;j<m;j++)visited[i][j]=0;

    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	if(arch[i][j]=='#' && !visited[i][j]){
	  dfs(i,j);
	  cnt+=1;
	}

    printf("%d\n", cnt);
    
  }
  return 0;
}

  // AC tutorial
