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
typedef vector<bool> vb;

vi v(200);
int TL=0;

/*
int rod_cut(int l,int h)
{
  int l1,r1,zc,p;
  if(l==h){
    R[l][h]=1;
    return v[l];
  }
  if(l<h){
    p=(h+l)/2;
    l1=rod_cut(l,p);
    r1=rod_cut(p+1,h);
    zc=h-l+1 - (l1+r1);
    if(l1+r1>zc) R[l][h]=h-l+1;
    return l1+r1;
  }
}
*/
vvi C(200,vi(200));
int n;

int get_max(int p)
{
  if(p>n) return 0;
  int i,j,k=p,b=0;
  for(i=p;i<n;i++){
    if(C[p][i]>b){
      b=C[p][i];
      k=i;
    }
  }
  return k==n-1?b:b+get_max(k+1);
}

int main()
{
  int T,i,j,k=-1,ans=0,zc=0,oc=0,l=0;
  scanf("%d",&T);
  
  while(T--){
    scanf("%d",&n);
    vi R(n);
    char input[200];
    scanf("%s", input);
    for(i=0;i<n&&input[i]!='\0';i++) v[i]=input[i]=='1'?1:0;
    for(i=0;i<n;i++) for(j=i;j<n;j++) C[i][j]=0;

    R[0]=v[0];
    for(i=1;i<n;i++)
      R[i]=v[i]?R[i-1]+1:R[i-1];

    for(i=0;i<n;i++){
      C[i][i]=v[i];  
      for(j=i+1;j<n;j++){
	oc=R[j]-R[i]+v[i];
	zc=j-i+1 - oc;
	if(oc>zc) C[i][j]=j-i+1;
      }
    }

    // for(i=0;i<n;i++){
    //   for(j=0;j<n;j++)
    // 	cout<<C[i][j]<<' ';
    //   pl;
    // }
    
    printf("%d\n",get_max(0));

    /*    copy(v.begin(),v.begin()+n,ostream_iterator<int>(cout,""));pl;
    copy(R.begin(),R.begin()+n,ostream_iterator<int>(cout,""));pl;

    */
  }

  return 0;
}

