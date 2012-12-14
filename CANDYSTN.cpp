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
#define SENTINEL 1000001

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<long long int> vlli;


vlli m(10000);
int main()
{
  int t,i,j,k,N,M,c=0,coll=0;
  long long int  inbag,incollec,minin,minout;  

  scanf("%d",&t);

  while(t--){
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++)scanf("%lld",&m[i]);

    long long int minin=SENTINEL,minout=SENTINEL;
    long long int in=0,out=0;

    for(i=1;i<M;i++){
      if(m[i]>m[i-1]){
	in+=m[i]-m[i-1];
	out-=m[i]-m[i-1];
      }
      else if(m[i]<m[i-1]){
	in-=m[i-1]-m[i];
	out+=m[i-1]-m[i];
      }
      else if(m[i]==m[i-1]) in-=1;
      minin=min(minin,in);
      minout=min(minout,out);
    }

    inbag=minout<0?abs(minout):0;
    
    if(minin<0)incollec=(in==minin)?abs(minin)+1:abs(minin);
    else incollec=1;
    
    if(incollec+inbag>N)printf("-1\n");
    else printf("%lld\n",incollec);
  }

  return 0;
}

