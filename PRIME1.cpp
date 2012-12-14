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
typedef vector<bool> vb;

int main()
{
  int t,i,j,k,p,q;
  scanf("%d",&t);
  while(t--){
    int m,n;
    scanf("%d %d",&m,&n);
    //    m=999900000;n=1000000000;
    vb v(1000000000,true);
    v[0]=false;v[1]=false;
    q=sqrt(n);
    for(i=2;i<q+1;i++){
      if(!v[i]) continue;
      k=!(m/i)?2:(m/i)+1;
      p=i*k;
      for(j=k;p<n+1;j++,p=i*j)
	v[p]=false;
    }
    
    for(i=m;i<n+1;i++)
      if(v[i]) printf("%d\n",i);
  }
  return 0;
}

