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

int R[100][100],T[100][100],mR[100][100];
int n,mt;

int main()
{
  int t,i,j,k;

  scanf("%d",&t);
  
  while(t--){

    scanf("%d %d",&n,&mt);

    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	scanf("%d", T[i][j]);

    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	scanf("%d", R[i][j]);

    for(i=0;i<n;i++){
      for(j=0;j<n;j++){

	for(
    
  }
  return 0;
}

