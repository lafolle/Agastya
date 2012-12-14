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


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;

#define even(n) (n%2==0?true:false)

int main()
{
  int t,n,m,ans;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    if(n==m)
      ans=even(n)?'L':'R';
    else{
      if(n<m) ans = even(n)?'L':'R';
      else ans = even(m)?'U':'D';
    }
    printf("%c\n",ans);
  }
  return 0;
}

// AC at 0.03
