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

int main()
{

  string op;
  char command[10];
  char command1[10],command2[10];
  while(scanf("%s",command)!=EOF){
    string f,s;
    int N,i,j,k;
    vi shells(3);
    vector<pair<int, int> > swps;
    pair<int,int> p;

    op=string(command);
    
    if(op=="right") shells[2]=1;
    if(op=="left") shells[0]=1;
    if(op=="center") shells[1]=1;
  
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%s %s",command1,command2);
      f=string(command1);s=string(command2);
      if(f=="left"&&s=="right" || s=="left"&&f=="right") p=make_pair(0,2);
      if(f=="left"&&s=="center" || f=="center"&&s=="left") p=make_pair(0,1);
      if(f=="right"&&s=="center" || f=="center"&&s=="right") p=make_pair(1,2);
      swps.push_back(p);
    }

    for(i=0;i<N;i++)
      swap(shells[swps[i].first], shells[swps[i].second]);


    for(i=0;i<3;i++)
      if(shells[i]) break;

    if(N!=10){ // this is awesome! 
      if(i==0) printf("left\n");
      if(i==1) printf("center\n");
      if(i==2) printf("right\n");
    }
  }
  
  return 0;
}

/*
  AC at 0.01
*/
