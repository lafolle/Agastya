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
#define ii(x,y) make_pair(x,y)


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
typedef set<int> SI;
typedef set<int>::iterator SI_it;

int BRD[9][9];
int depth_sol;

struct State{
  int M[9][9],i,j,k,p,q;
  int depth;
  int nv_x,nv_y; // next vacant pos
  SI s,rst,cst;
  SI_it it;

  State(){}
  State(int mat[9][9],int d, int nvx,int nvy){
    for(i=0;i<9;i++)for(j=0;j<9;j++)M[i][j]=mat[i][j];
    depth=d;
    nv_x=nvx;
    nv_y=nvy;
  }
  
  bool isgoal(){
    for(p=0;p<9;p+=3)
      for(q=0;q<9;q+=3){
	for(i=p;i<p+3;i++)
	  for(j=q;j<q+3;j++)
	    if(M[i][j]!=0&&(s.insert(M[i][j])).second==false)
	      return false;
	s.clear();	
      }

    for(i=0;i<9;i++){
      s.clear();
      for(j=0;j<9;j++)
	if(M[i][j]==0||(s.insert(M[i][j])).second==false)
	  return false;
    }

    for(i=0;i<9;i++){
      s.clear();
      for(j=0;j<9;j++)
	if(M[j][i]==0||(s.insert(M[j][i])).second==false)
	  return false;
    }

    return true;
  }

  void show()
  {
    for(i=0;i<9;i++){
      for(j=0;j<9;j++)
	printf("%d ", M[i][j]);
      printf("\n");
    }
    fflush(stdout);
  }

  void spojshow(){
    for(i=0;i<9;i++)for(j=0;j<9;j++)printf("%d",M[i][j]);pl;
  }
};

bool possible(int k, int x, int y, int M[9][9])
{
  int bx=(x/3)*3,by=(y/3)*3,i,j;
  for(i=0;i<9;i++)if(M[x][i]==k)return 0;
  for(i=0;i<9;i++)if(M[i][y]==k)return 0;

  for(i=bx;i<bx+3;i++)
    for(j=by;j<by+3;j++)
      if(i!=x&&j!=y&&M[i][j]==k) return 0;

  return 1;
}

pii getnextvacant(int x,int y)
{
  int i,j;
  if(y==8&&x==8) return ii(-1,-1);
  if(y==8){
    i=x+1;
    j=0;
  }
  else{
    i=x;
    j=y+1;
  }

  for(;i<9;i++,j=0)
    for(;j<9;j++)
      if(BRD[i][j]==0)return ii(i,j);
  return ii(-1,-1);
}

bool solve(State root)
{
  int i,j,k=0,mat[9][9],x,y;
  stack<State> S;

  State ts;
  pii vp;
  S.push(root);

  while(!S.empty()){
    ts=S.top();S.pop();

    if(ts.depth==depth_sol && ts.isgoal()){
      ts.show();
      return true;
    }
    x=ts.nv_x;y=ts.nv_y;
    if(x==-1&&y==-1)continue;

    //    ts.show();
    ++k;
    for(i=0;i<9;i++)for(j=0;j<9;j++)mat[i][j]=ts.M[i][j];

    vp=getnextvacant(x,y);
    for(i=1;i<=9;i++){
      if(!possible(i,x,y,mat))continue;
      mat[x][y]=i;
      S.push(State(mat,ts.depth+1,vp.first,vp.second));
    }
    
  }
  return false;
}

int main()
{
  int M[9][9],i,j,k,t,x,y;
  
  scanf("%d",&t);
  while(t--){
    depth_sol=0;
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
	scanf("%d",&k);
	if(!k)depth_sol++;
	M[i][j]=k;
	BRD[i][j]=k;
      }
    }
	  
    // find next vacant pos
    for(i=0;i<9;i++)
      for(j=0;j<9;j++)
	if(!M[i][j]) goto haha;

    //    assert(i!=9&&j!=9);
    
  haha:
    State r(M,0,i,j);

    if(!solve(r))printf("No solution\n");
  }

  return 0;
}

// AC 0.35
