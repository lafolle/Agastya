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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<vector<string> > vvs;

//vs M(3);
char M[3][3];

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
       M[0][2]==p&&M[1][1]==p&&M[2][0]==p)?true:false;
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
  int xc,oc,dot;
  char w;

  while(1){
    xc=0;oc=0;dot=0;
    char line[10]={'\0'};
    scanf("%s",line);
    if(!strcmp(line,"end")) break;
    for(k=0;k<9;k++) M[k/3][k%3]=line[k];

    for(i=0;i<3;i++)
      for(j=0;j<3;j++){
	if(M[i][j]=='X') ++xc;
	if(M[i][j]=='O') ++oc;
	if(M[i][j]=='.') ++dot;
      }

    if(oc>xc){
      printf("invalid\n");
      continue;
    }

    w=winner();
    if(w=='X'&&(xc==3&&oc==2||xc==4&&oc==3||xc==5&&oc==4)) // X wins
      printf("valid\n");
    else if(w=='O'&&(xc==3&&oc==3||xc==4&&oc==4))   // O wins
      printf("valid\n");
    else if(w=='N'&&!dot) printf("valid\n");  // draw
    else printf("invalid\n");
  }
  return 0;
}

// AC
