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
#define SENTINEL 1000000


typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;

int main()
{
  int t,i,j,k=1,n,m,x,y,p;
  cin>>p;
  while(p--){
    cin>>n; // milkshake flavours
    cin>>m; // no. of customers
    vpii CP[m];    
    vb malted(n+1,false);
    vi adjcnt(m),satisfied(m);
    for(i=0;i<m;i++){
      cin>>t;adjcnt[i]=t;
      for(j=0;j<t;j++){
	cin>>x;
	cin>>y;
	CP[i].push_back(make_pair(x,y));
      }
    }

    // for those who only like malted
    for(i=0;i<m;i++){
      if(adjcnt[i]==1&&CP[i][0].second==1){
	malted[CP[i][0].first]=true;
	satisfied[i]=true;
      }
    }

    for(i=0;i<m;i++){
      if(adjcnt[i]==1&&CP[i][0].second==0)
    }
    
  }
  return 0;
}

