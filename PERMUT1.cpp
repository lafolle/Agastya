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

long long int invcnt;

void merge(vi &v,int l, int p, int h)
{
  int i,r,j,k=l,m=p-l+1,n=h-p;
  vi L(v.begin()+l,v.begin()+p+1),R(v.begin()+p+1,v.begin()+h+1);

  for(l=0,r=0;l<m&&r<n;k++){
    if(L[l]<R[r]||L[l]==R[r]){
      v[k]=L[l];
      ++l;
    }
    else{
      invcnt+=m-l;
      v[k]=R[r];
      ++r;
    }
  }

  
  if(l==m&&r!=n){
    for(i=r;i<n&&k<h+1;i++,k++)
      v[k]=R[i];
  }
  if(l!=m&&r==n){
    for(i=l;i<m&&k<h+1;i++,k++){
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
  int n,p,ans;
  scanf("%d",&t);
  while(t--){
    //    scanf("%d &d",&n,&m);
    cin>>n>>p;
    vi v(n),tmpv;
    for(i=0;i<n;i++) v[i]=i;
    ans=0;
    do{
      invcnt=0;
      tmpv=v;
      mergesort(tmpv,0,n-1);
      if(invcnt==p)++ans;
    }while(next_permutation(all(v)));
    printf("%d\n",ans);
  }
  return 0;
}


/*
  No, brute force wont work...
*/
