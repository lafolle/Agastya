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
  char op;
  int i,j,k,x,y,z;
  //  vi tr(1235),tc(5679),rloc(1235),cloc(5679);
  int tr[1235],tc[5679],rloc[1235],cloc[5679];
  for(i=1;i<1235;i++){
    tr[i]=i;
    rloc[i]=i;
  }
  for(i=1;i<5679;i++){
    tc[i]=i;
    cloc[i]=i;
  }
  while(scanf("%c",&op)!=EOF){
    if(op=='R'){
      scanf("%d %d",&x,&y);
      rloc[tr[x]]=y;
      rloc[tr[y]]=x;
      swap(tr[x],tr[y]);
    }
    else if(op=='C'){
      scanf("%d %d",&x,&y);
      cloc[tc[x]]=y;
      cloc[tc[y]]=x;
      swap(tc[x],tc[y]);
    }
    else if(op=='Q'){
      scanf("%d %d",&x,&y);
      printf("%d\n",5678*(tr[x]-1)+tc[y]);
    }
    else if(op=='W'){ // w
      scanf("%d",&z);
      k=z%5678;
      printf("%d %d\n",rloc[!k?z/5678:z/5678+1],cloc[!k?5678:k]);      
    }
  }
  return 0;
}

/* AC at 0.08 */
