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

int main()
{
  int mat[3][3];
  int i,j,k,t=5;
  while(t--){

    for(i=0;i<3;i++)
      for(j=0;j<3;j++){
	scanf("%d",&k);
	mat[i][j]=k;
      }

    cout<<manhattan(mat)<<endl;
    
  }
  
  return 0;
}

