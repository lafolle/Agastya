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

bool checkfor(char M[3][3],char p)
{
  bool win;
  int i,j;
  // horizontal
  for(i=0;i<3;i++){
    win=true;
    for(j=0;j<3;j++)
      win=win&(M[i][j]==p?true:false);
    if(win) return true;
  }
  // vertical
  for(i=0;i<3;i++){
    win=true;
    for(j=0;j<3;j++)
      win=win&(M[i][j]==p?true:false);
    if(win) return true;
  }

  // diagnols
  win=(M[0][0]==p&&M[1][1]==p&&M[2][2]==p ||
       M[2][2]==p&&M[1][1]==p&&M[0][0]==p)?true:false;
  return win;
}

char winner(char M[3][3])
{
  bool w,o;
  w=checkfor(M,'X');
  o=checkfor(M,'O');
  if(w&&o) return 'B';
  if(w&&!o) return 'X';
  if(!w&&o) return 'O';
  if(!w&&!o) return 'N';
}

int main()
{
  char M[3][3],w;
  int i,j,k,oc,xc,t;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    for(i=0;i<3;i++) scanf("%s",M[i]);
    w=winner(M);
    cout<<w<<endl;
  }
  
  return 0;
}

