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
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;

int main()
{
  int n,i,j,h;
  int hmin,sz,l,r,A;
  stack<pair<int, int> > S;
  
  scanf("%d",&n);
  while(n--){
    vpii vp;
    for(i=0;i<n;i++){
      scanf("%d",&h);
      vp.push_back(make_pair(h,i));
    }
    sort(all(vp));

    // for the tim being...
    reverse(all(vp));
    
    pii p;
    p=vp[0];
    S.push(p);
    l=p.second;
    r=l;
    hmin=p.first;
    A=-1;
    ins_sz=1;
    for(i=1;i<n;i++){
      p=vp[i];
      if(p.second==l-1 || p.second==r+1){
	S.push(p);
	++ins_size;
	hmin=min(hmin,p.first);
	if(p.second==l-1) l-=1;
	if(p.second==r+1) ++r;
      }
      else{
	for(i=0;i<ins_size;i++) S.pop();
	S.push(p);
	l=p.second;
	r=p.second;
	hmin=p.first;
	ins_size=1;
      }
      A=max(A,hmin*ins_size);
    }

  }
  return 0;
}

