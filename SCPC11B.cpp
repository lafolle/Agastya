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

int main()
{
  int n,i,j,k,p,c;


  scanf("%d",&n);
  while(n!=0){
    vi v(n);
    for(i=0;i<n;i++)
      scanf("%d",&v[i]);

    sort(all(v));

    for(i=1;i<n;i++)
      if(v[i]-v[i-1]>200){
	printf("IMPOSSIBLE\n");
	goto there;
      }

    k=1422-v[n-1];
    if(k>100){
      printf("IMPOSSIBLE\n");
      goto there;
    }

    printf("POSSIBLE\n");


    

  there:    
    scanf("%d",&n);
  }
  return 0;
}

// AC
