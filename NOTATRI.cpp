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

bool tri(int a,int b,int c)
{
  vi T(3);
  T[0]=a;T[1]=b;T[2]=c;
  sort(all(T));

  return T[0]+T[1]>T[2] || T[0]+T[1]==T[2];
}

int main()
{
  int N,i,j,k,c=0;
  int x,y;
  scanf("%d", &N);

  while(N!=0){
    vi l(N);
    int mc=0,ac=0;
    vi::iterator u;
    
    for(i=0;i<N;i++)
      scanf("%d", &l[i]);

    sort(all(l));
    
    for(i=0;i<N;i++){
      for(j=i+1;j<N;j++){
	u = upper_bound(l.begin()+j,l.end(),l[i]+l[j]);
	c+=l.end()-u;
      }
    }

    printf("%d\n",c);
    c=0;
    
    scanf("%d",&N);
  }
  return 0;
}

