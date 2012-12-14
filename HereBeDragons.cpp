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
#include <cstring>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  int T;
  scanf("%d",&T);

  while(T--){
    char seg[50];
    int n,i;
    bool drag=false;
    scanf("%s",seg);
    n=strlen(seg);
    for(i=0;i<n;i++)
      if(seg[i]=='D'){
	drag=true;
	break;
      }

    if(drag) printf("You shall not pass!\n");
    else printf("Possible\n");
  }
  return 0;
}

