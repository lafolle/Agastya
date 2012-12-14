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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
  int t,i,j,k,n,transfer;
  double p;
  scanf("%d",&t);
  while(t--){
    transfer=0;
    scanf("%d",&n);
    vector<pair<int,double> > give,take;
    double ave,m;
    vi spent(n);
    for(i=0;i<n;i++) scanf("%d",&spent[i]);
    int s=0;
    s=accumulate(all(spent),0);
    ave=(double)s/n;
    for(i=0;i<n;i++){
      m=spent[i]-ave;
      if(m<0){
	give.push_back(make_pair(i,abs(m)));
	++transfer;
      }
      else if(m>0) take.push_back(make_pair(i,m));
      else if(!m) give.push_back(make_pair(i,0));
    }
    //    sort(all(give));
    //    sort(all(take));
    }
    
  }
  return 0;
}

