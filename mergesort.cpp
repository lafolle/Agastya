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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()


typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;


// inplace sorting of arrays
void merge(vi &v,int l, int p, int h)
{
  int i,r,j,k=l,m=p-l+1,n=h-p,e=m+n;
  vi L(v.begin()+l,v.begin()+p+1),R(v.begin()+p+1,v.begin()+h+1);

  for(l=0,r=0;l<m&&r<n;k++){
    if(L[l]<R[r]){
      v[k]=L[l];
      ++l;
    }
    else{
      v[k]=R[r];
      ++r;
    }
  }

  if(l==m&&r!=n){
    for(i=r;i<n&&k<e;i++,k++)
      v[k]=R[i];
  }
  if(l!=m&&r==n){
    for(i=l;i<m&&k<e;i++,k++){
      v[k]=L[i];
    }
  }
}

void mergesort(vi &v,int l,int h)
{
  int p;
  if(l<h){
    p=(l+h)/2;
    mergesort(v,l,p);
    mergesort(v,p+1,h);
    merge(v,l,p,h);
  }
}

int main()
{
  int t,i;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d", &n);
    vi v(n);
    for(i=0;i<n;i++) scanf("%d",&v[i]);
    mergesort(v,0,n-1);
    copy(all(v),ostream_iterator<int>(cout," "));pl;
  }
  return 0;
}

