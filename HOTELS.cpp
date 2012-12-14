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

vi v(1000000);

int main()
{
  int i,j,k;

  int n,m;
  int max_sum=0, ts=0;  

  while(scanf("%d", &n)!=EOF){

    max_sum=-INF; ts=0;
    
    scanf("%d", &m);

    for(i=0;i<n;i++)scanf("%d", &v[i]);

    for(i=0,j=0;j<n;i++){

      for(;j<n;j++){
	if(ts+v[j]>m) break;
	ts+=v[j];
      }

      max_sum=max(max_sum, ts);
      
      ts-=v[i];
    }

    printf("%d\n", max_sum);
    
  }
  
  return 0;
}

// AC
