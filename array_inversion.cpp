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
  int t;
  //  scanf("%d",&t);
  t=1;
  int i,j,k,n;
  while(t--){
    //    cin>>n;
    //    scanf("%d",&n);
    n=100000;
    vi v(n);
    for(i=0;i<n;i++) scanf("%d",&v[i]);

    cout<<"Starting process..."<<endl;
    
    int key,c=0;
    for(i=1;i<n;i++){
      key=v[i];
      j=i-1;
      while(j>-1&&v[j]>key){
	v[j+1]=v[j];
	j-=1;
	c+=1;
      }
      v[j+1]=key;
    }
    //    copy(all(v),ostream_iterator<int>(cout," "));pl;
    cout<<endl<<c<<endl;
  }
  return 0;
}

/* n=10000 : around 10 secs */
