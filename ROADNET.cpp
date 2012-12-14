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
typedef vector<pair> vp;

int main()
{
  int t,n,i,j,k,c=0;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vvi sp(n,vi(n));
    vp neigh;
    c=0;
    
    for(i=1;i<n;i++)
      for(j=1;j<n;j++)
	scanf("%d",&sp[i][j]);

    for(i=1;i<n;i++)
      for(j=i+1;j<n;j++)
	for(k=i+1;k<j;k++)
	  if(sp[i][j]==sp[i][k]+sp[k][j]){
	    ++c;
	    neigh.push_back(make_pair(i,j));
	  }
    sort(all(neigh));
    for(i=0;i<c;i++)
      printf("%d %d",sp[i].first,sp[i].second);
  }
  return 0;
}

/* already solved! */
