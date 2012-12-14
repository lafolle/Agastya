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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
  int i,j=0,min_cnt,len;
  char bs[10000]={'\0'};
  
  while(scanf("%s",bs)!=EOF){
    ++j;
    min_cnt=0;
    len=strlen(bs);
    for(i=0;i<len;i++){
      if(min_cnt%2==0)
	min_cnt+=bs[i]=='1'?1:0;
      else min_cnt+=bs[i]=='0'?1:0;
    }
    printf("Game #%d: %d\n",j,min_cnt);
    bzero(bs,10000);
  }
  return 0;
}

