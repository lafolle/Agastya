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
  int T,N,i,c=0,S,k=1;
  scanf("%d",&T);
  while(T--){
    c=0;
    scanf("%d",&S);
    scanf("%d",&N);
    vi lend(N);
    for(i=0;i<N;i++) scanf("%d",&lend[i]);
    sort(all(lend), greater<int>());

    i=0;
    while(c<S&&c!=S&&i<N){
      c+=lend[i];
      ++i;
    }

    printf("Scenario #%d:\n",k);
    if(c==S||c>S)
      printf("%d\n\n",i);
    else printf("impossible\n\n");
    ++k;
  }
  return 0;
}

