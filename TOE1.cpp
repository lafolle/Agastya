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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;

vs M(3);

bool checkfor(char p)
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
      win=win&(M[j][i]==p?true:false);
    if(win) return true;
  }

  // diagnols
  win=(M[0][0]==p&&M[1][1]==p&&M[2][2]==p ||
       M[2][2]==p&&M[1][1]==p&&M[0][0]==p)?true:false;
  return win;
}

char winner()
{
  bool w,o;
  w=checkfor('X');
  o=checkfor('O');
  if(w&&o) return 'B';
  if(w&&!o) return 'X';
  if(!w&&o) return 'O';
  if(!w&&!o) return 'N';
}

int main()
{
  int i,j,k,t;
  int xc,oc;
  char w,ch,line[3];

  scanf("%d",&t);
  
  while(t--){
    xc=0;oc=0;j=0;
    for(i=0;i<3;i++){
      scanf("%s",line);
      M[i]=string(line);
    }
    
    for(i=0;i<3;i++)
      for(j=0;j<3;j++){
	if(M[i][j]=='X') ++xc;
	if(M[i][j]=='O') ++oc;
      }

    // condition 1
    if(oc>xc){
      printf("no\n");
      continue;
    }

    // condition 2
    w=winner();
    if(w=='X'){
      if(xc==3&&oc==2||xc==4&&oc==3||xc==5&&oc==4)
	printf("yes\n");
      else printf("no\n");
    }
    else if(w=='O'){
      if(xc==3&&oc==3||xc==4&&oc==4)
	printf("yes\n");
      else printf("no\n");
    }
    else if(w=='B')
      printf("no\n");
    else printf("yes\n");
  }
  return 0;
}

/* Had problem in vertical win check. silly...
   2.4M */
