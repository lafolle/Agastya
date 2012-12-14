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
#include <hash_map>

using namespace std;

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define INF 1000001


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

using namespace __gnu_cxx;

vi v(500001);

int main()
{
  int i,j,k,n;

  while(scanf("%d",&n)!=EOF){

    hash_map<int, int, hash<int> > hm;
    
    for(i=0;i<n;i++){
      scanf("%d",&v[i]);
      if(hm.find(v[i])!=hm.end())
	hm.erase(v[i]);
      else hm[v[i]]=1;
    }
    printf("%d\n",(*(hm.begin())).first);

  }
  return 0;
}

// TLE
/* Need better algorithm.
   hash_map or bit vectors!
*/
