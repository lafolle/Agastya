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

int n, m;
vi inter[2001],visited(2001);
int adjcnt[2001];
bool colored[2001];
bool color[2001];

bool homo()
{
  int i,j,l,tp,c,k;


  for(k=1;k<=n;k++){

    if(visited[k])continue;
  
    stack<int> st;
    st.push(k);
    color[k]=0;
    colored[k]=true;

    while(!st.empty()){

      tp=st.top();st.pop();

      visited[tp]=true;
    
      c=color[tp];
      for(i=0;i<adjcnt[tp];i++){
	if(visited[inter[tp][i]])continue;
	if(colored[inter[tp][i]]&&color[inter[tp][i]]==c) return true;
	color[inter[tp][i]]=c?0:1;
	colored[inter[tp][i]]=true;
	st.push(inter[tp][i]);
      }
    }
    
  }
  
  return false;
}
  

int main()
{
  int i,j,k=0,t,x,y;

  scanf("%d", &t);

  while(t--){

    scanf("%d %d", &n, &m);

    for(i=0;i<m;i++){
      scanf("%d %d", &x, &y);
      inter[x].push_back(y);
      inter[y].push_back(x);
      adjcnt[x]+=1;
      adjcnt[y]+=1;
    }

    fill(colored+1,colored+n+1,false);
    fill(color+1,color+n+1,false);
    fill(visited.begin()+1,visited.begin()+1+n,false);
    
    printf("Scenario #%d:\n%s\n", ++k,homo()?"Suspicious bugs found!":"No suspicious bugs found!");

    fill(adjcnt+1, adjcnt+1+n, 0);
    for(i=1;i<=n;i++)inter[i].clear();
    
  }
  
  return 0;
}

// AC
