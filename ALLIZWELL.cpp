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

const char *text="ALLIZZWELL";

int r,c;
char m[101][101],visited[101][101];

bool valid(int i, int j) {return (i>=0&&i<r)&&(j>=0&&j<c);}

bool present(int i, int j, int d)
{

  if(d==10) return true;
  if(!valid(i,j)) return false;
  
  if(visited[i][j] || m[i][j]!=text[d]) return false;

  visited[i][j]=true;

  bool f=false;
  if(present(i+1,j,d+1) ||
     present(i-1,j,d+1) ||
     present(i,j+1,d+1) ||
     present(i,j-1,d+1) ||
     present(i+1,j+1,d+1) ||
     present(i-1,j+1,d+1) ||
     present(i+1,j-1,d+1) ||
     present(i-1,j-1,d+1))
    f=true;

  visited[i][j]=false;
  return f;
}

int main()
{
  int t,i,j,k;
  bool f=false;
  scanf("%d",&t);

  while(t--){
    scanf("%d %d", &r, &c);
    f=false;
    for(i=0;i<r;i++)scanf("%s",m[i]);
    //    for(i=0;i<r;i++)for(j=0;j<c;j++)visited[i][j]=false;
    memset(visited,0,sizeof(bool)*101*101);

    for(i=0;i<r;i++)
      for(j=0;j<c;j++)
	if(m[i][j]=='A' && present(i,j,0)){
	  f=true;
	  goto there;
	}
  there:
    if(f)printf("YES\n");
    else printf("NO\n");
  }
    
  return 0;
}

// AC
