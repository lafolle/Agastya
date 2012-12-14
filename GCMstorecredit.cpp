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
#define SENTINEL 1000000


typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

int main()
{
  int t,i,j,k=1,a,b;
  int C,I;
  
  scanf("%d",&t);
  while(t--){
    scanf("%d",&C);
    scanf("%d",&I);
    vi v(I);
    for(i=0;i<I;i++)scanf("%d",&v[i]);

    bool found=false;
    for(i=0;i<I;i++){
      for(j=i+1;j<I;j++)
	if(v[i]+v[j]==C){
	  a=i;
	  b=j;
	  found=true;
	  break;
	}
      if(found) break;
    }

    if(a<b)printf("Case #%d: %d %d\n",k,a+1,b+1);
    else printf("Case #%d: %d %d\n",k,b+1,a+1);
    ++k;
  }
  return 0;
}

