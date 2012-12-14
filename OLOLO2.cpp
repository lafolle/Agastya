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

vi v(500001);

int main()
{
  int i,j,k,n;

  while(scanf("%d",&n)!=EOF){

    for(i=0;i<n;i++)
      scanf("%d",&v[i]);

    sort(v.begin(),v.begin()+n);

    if(v[0]!=v[1])
      printf("%d\n",v[0]);
    else{
      for(i=0;i<n-1;i+=2)
	if(v[i]!=v[i+1])
	  break;
      printf("%d\n",v[i]);
    }

    
  }
  return 0;
}

// TLE
