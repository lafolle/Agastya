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

bool valid(int i, int j, int n){return (i>=0&&i<n)&&(j>=0&&j<n);}

pii endpos(int k)
{
  int i,j;
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

int manhattan(int mat[3][3])
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

struct State{
  int m[3][3];
  int cost; // cost heuristic

  State(){}
  State(int mat[3][3]){
    int i,j;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
	m[i][j]=mat[i][j];
    cost=manhattan();
  }

  int manhattan()
  {
    int i,j,k,s=0;
    pii p;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++){
	p=endpos(m[i][j]);
	s+=abs(p.first-i)+abs(p.second-j);
      }
    return s;
  }

  void showmat()
  {
    int i,j;
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
	cout<<m[i][j]<<' ';
      }
      pl;
    }
  }

  bool operator==(const State &s){
    int i,j;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
	if(m[i][j]!=s.m[i][j]) return false;
    return true;
  }
};

vector<State> v;

bool checkstate(State s)
{
  int l=v.size(),i,j;
  static int c=0;
  for(i=0;i<l;i++)
    if(v[i]==s){
      cout<<"Backin up!"<<++c<<"\n";
      return true;
      //      exit(1);
    }
  return false;
}

int mincost=SENTINEL,maxcost=-SENTINEL;

void solve(State s, int step, int pi, int pj)
{printf("Step : %d\n",step);
  //  s.showmat();pl;

  if(checkstate(s))return;
  v.push_back(s);
  mincost=min(mincost,s.cost);
  maxcost=max(maxcost,s.cost);
  cout<<mincost<<endl;
  cout<<maxcost<<endl;

  if(s.cost==0){printf("Found!");exit(1);}
  int m,n,i,j,k;
  bool f=true;
  for(i=0;i<3&&f;i++)
    for(j=0;j<3&&f;j++)
      if(s.m[i][j]==0)
	{m=i;n=j;f=false;}

  int mat[3][3];
  
  // upc
  if(valid(m-1,n,3)&&m-1!=pi&&n!=pj){
    for(i=0;i<3;i++)for(j=0;j<3;j++)mat[i][j]=s.m[i][j];
    mat[m-1][n]=0;
    mat[m][n]=s.m[m-1][n];
    //    if(manhattan(mat)<=s.cost){
      solve(State(mat), step+1,m,n);
      //    }
  }
  
  // right
  if(valid(m,n+1,3)&&m!=pi&&n+1!=pj){
    for(i=0;i<3;i++)for(j=0;j<3;j++)mat[i][j]=s.m[i][j];
    mat[m][n+1]=0;
    mat[m][n]=s.m[m][n+1];
    //    if(manhattan(mat)<=s.cost){
      solve(State(mat), step+1,m,n);
      //    }
  }
  
  // bottom
  if(valid(m+1,n,3)&&m+1!=pi&&n!=pj){
    for(i=0;i<3;i++)for(j=0;j<3;j++)mat[i][j]=s.m[i][j];
    mat[m+1][n]=0;
    mat[m][n]=s.m[m+1][n];
    //    if(manhattan(mat)<=s.cost){
      solve(State(mat), step+1,m,n);
      //    }
  }
  
  // left
  if(valid(m,n-1,3)&&m!=pi&&n-1!=pj){
    for(i=0;i<3;i++)for(j=0;j<3;j++)mat[i][j]=s.m[i][j];
    mat[m][n-1]=0;
    mat[m][n]=s.m[m][n-1];  
    //    if(manhattan(mat)<=s.cost){
      solve(State(mat), step+1,m,n);
      //    }
  }
}

stack<vvi> S;

void itersolve(int r[3][3])
{
  int i,j,k;
  vvi mat(3,vi(3)),tp;

  
  S.push(mat);

  while(!S.empty()){
    tp=S.top();S.pop();
    mht=manhattan(tp);
    if(mht==0){
      printf("Goal reached.\n");
      break;
    }

    
  }
}
 
int main()
{
  int mat[3][3],i,j,k,p,m,n;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++){
      scanf("%d",&p);
      mat[i][j]=p;
      if(!p){m=i;n=j;}
    }

  State root(mat);

  solve(root,0,1,2);
  return 0;
}

