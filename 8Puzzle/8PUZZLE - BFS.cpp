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
#define ii(x,y) (make_pair(x,y))

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
typedef pair<set<vvi>::iterator,bool> SRI;

void showmat(const vvi &mat)
{
  int i,j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

bool valid(int i, int j, int n){return (i>=0&&i<n)&&(j>=0&&j<n);}

pii endpos(int k)
{
  int i,j;
  if(k==0)return ii(2,2);
  if(!(k%3)){
    i=k/3-1;
    j=2;
  }
  else{
    i=k/3;
    j=k-3*i-1;
  }
  return ii(i,j);
}

// heuristic
int manhattan(vvi &mat)
{
  int i,j,k,s=0;
  pii p;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++){
      p=endpos(mat[i][j]);
      s+=abs(p.first-i)+abs(p.second-j);
    }
  return s;
}

pii blockpos(vvi &mat)
{
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      if(mat[i][j]==0)
	return ii(i,j);
}

queue<vvi> S;
set<vvi> closedlist;
SRI ri;

void solve(vvi &root)
{
  int i,j,k,x,y,backedcount=0;
  vvi tp(3,vi(3)),mat(3,vi(3));
  pii bp;

  S.push(root);

  while(!S.empty()){
    tp=S.front();S.pop();

    if(!manhattan(tp)){
      showmat(tp);
      printf("Found\n");
      break;
    }
    
    ri=closedlist.insert(tp);
    if(ri.second==false){
      ++backedcount;
      continue;
    }
    //    showmat(tp);
    bp=blockpos(tp);
    x=bp.first;y=bp.second;

    if(valid(x-1,y,3)){
      for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	  mat[i][j]=tp[i][j];      
      mat[x-1][y]=0;
      mat[x][y]=tp[x-1][y];
      S.push(mat);
    }
    if(valid(x+1,y,3)){
      for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	  mat[i][j]=tp[i][j];
      mat[x+1][y]=0;
      mat[x][y]=tp[x+1][y];
      S.push(mat);
    }
    if(valid(x,y-1,3)){
      for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	  mat[i][j]=tp[i][j];
      mat[x][y-1]=0;
      mat[x][y]=tp[x][y-1];
      S.push(mat);
    }
    if(valid(x,y+1,3)){
      for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	  mat[i][j]=tp[i][j];
      mat[x][y+1]=0;
      mat[x][y]=tp[x][y+1];
      S.push(mat);
    }
    
  }
  if(S.empty()) printf("\nFailed\n");

  printf("Closed list : %d\n",closedlist.size());
  printf("Backed count : %d\n",backedcount);
  printf("States unexplored : %d\n", 362880-closedlist.size());
  
}

int main()
{
  vvi mat(3,vi(3));
  int i,j,p,q;

  for(i=0;i<3;i++)
    for(j=0;j<3;j++){
      scanf("%d", &q);
      mat[i][j]=q;
    }

  showmat(mat);
  
  solve(mat);
  
  return 0;
}
