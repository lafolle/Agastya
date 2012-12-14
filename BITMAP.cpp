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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int n,m;

bool valid(int i,int j){ return i>-1&&i<n&&j>-1&&j<m; }

int main()
{
  int t,i,j,k;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    char bm[n][m];
    vvi closest(n,vi(m));
    for(i=0;i<n;i++) scanf("%s",bm[i]);

    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	if(bm[i][j]=='1'){
	  closest[i][j]==0;
	  continue;
	}

	queue<pair<int,int> > Q;
	if(valid(i+1,j)) Q.push(make_pair(i+1,j));
	if(valid(i-1,j)) Q.push(make_pair(i-1,j));
	if(valid(i,j+1)) Q.push(make_pair(i,j+1));
	if(valid(i,j-1)) Q.push(make_pair(i,j-1));
	pair<int,int> cell;
	//	bool visited[n][m];
	vector<vector<bool> > visited(n,vector<bool>(m,false));
	int p,q;
	while(!Q.empty()){
	  cell=Q.front();Q.pop();
	  p=cell.first;q=cell.second;
	  if(visited[p][q]) continue;
	  if(bm[p][q]=='1') break; // ans found

	  visited[p][q]=true;
	  
	  if(valid(p+1,q)&&!visited[p+1][q]) Q.push(make_pair(p+1,q));
	  if(valid(p-1,q)&&!visited[p-1][q]) Q.push(make_pair(p-1,q));
	  if(valid(p,q+1)&&!visited[p][q+1]) Q.push(make_pair(p,q+1));
	  if(valid(p,q-1)&&!visited[p][q-1]) Q.push(make_pair(p,q-1));
	}
	
	closest[i][j]=abs(p-i)+abs(q-j);
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
	printf("%d ",closest[i][j]);
      pl;
    }
  }
  return 0;
}

/* TLE...was expecting */
