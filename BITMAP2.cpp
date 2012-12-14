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
typedef pair<int,int> pi;
typedef vector<pair<int, int> > vpii;

// manhattan distance
bool mdis(const pi &a,  const pi &b){ return abs(a.first-b.first)+abs(a.second-b.second); };

struct cmp{
  int operator()(const pi &a, const pi &b){
    return mdis(a,make_pair(0,0))>mdis(b,make_pair(0,0));
  }
};

int main()
{
  int t,n,m,i,j,k;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    char bmp[n][m];
    vpii z,w;
    int zcount=0;
    for(i=0;i<n;i++) scanf("%s",bmp[i]);
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	if(bmp[i][j]=='1') w.push_back(make_pair(i,j));
	else{
	  z.push_back(make_pair(i,j));
	  zcount+=1;
	}
      }
    }

    sort(all(w),cmp());

    vpii::iterator it=w.begin();
    while(it!=w.end()){
      cout<<(*it).first<<' '<<(*it).second<<endl;
      ++it;
    }
    pi p;
    int ind;
    vvi d(n,vi(m,0));
    for(i=0;i<zcount;i++){
      it=lower_bound(all(w),z[i],cmp());
      ind=it-w.begin();
      if(ind) p=mdis(z[i],w[ind])<mdis(z[i],w[ind-1])?w[ind]:w[ind-1];
      else p=w[0];
      d[z[i].first][z[i].second]=abs(z[i].first-p.first)+abs(z[i].second-p.second);
    }

    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
	printf("%d ",d[i][j]);
      pl;
    }
  }
  return 0;
}

