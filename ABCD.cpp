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
typedef vector<char> vc;


const int NMAX=50000;
int N;
vc v(2*NMAX,'Z');
char u[2*NMAX];
vi C(4);

bool dfs(int i, char ch, int a, int b, int c, int d)
{
  if(i==2*N) return true;
  if(i!=0&&(u[i]==ch||v[i-1]==ch)) return false;
  if(i==0&&u[0]==ch) return false;
  int p;
  if(ch=='A') p=a;
  else if(ch=='B') p=b;
  else if(ch=='C') p=c;
  else p=d;
  if(N-C[ch-'A']<p) return false;

  // all conditions satisfied
  v[i]=ch;

  if(dfs(i+1,'A',a+1,b,c,d)||
     dfs(i+1,'B',a,b+1,c,d)||
     dfs(i+1,'C',a,b,c+1,d)||
     dfs(i+1,'D',a,b,c,d+1))
    return true;
  return false;
}


void iter_dfs()
{
  vi AC(all(C));
  int i=0,j,k;
  stack<char> S;
  char c_char;
  S.push('A');S.push('B');S.push('C');S.push('D');
  while(!S.empty()){
    c_char=S.top();
    S.pop();

    if(i==2*N) return;
    if(i==0 && u[0]==c_char) continue;
    if(i!=0 && (u[i]==c_char || v[i-1]==c_char)) continue;
    if(AC[c_char-'A']+1>N) continue;

    v[i]=c_char;
    i++;
    AC[c_char-'A']++;
    S.push('A');S.push('B');S.push('C');S.push('D');
  }
}

int main()
{
  int i,j;
  while(scanf("%d",&N)!=EOF){
    for(i=0;i<4;i++) C[i]=0;
    char ch;

    i=0;
    scanf("%s",u);
    for(i=0;i<2*N;i++){
      C[u[i]-'A']+=1;
    }

    if(dfs(0,'A',1,0,0,0)||
       dfs(0,'B',0,1,0,0)||
       dfs(0,'C',0,0,1,0)||
       dfs(0,'D',0,0,0,1)){
      for(i=0;i<2*N;i++) printf("%c",v[i]);
      pl;
    }

    /*    iter_dfs();
	  for(i=0;i<2*N;i++) printf("%c",v[i]);pl;*/
  }
  return 0;
}

/* TLE on 18th test!!! */
