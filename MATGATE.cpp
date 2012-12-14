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

string toggle(string p)
{
  return p=="FIRST"?"SECOND":"FIRST";
}

int main()
{
  int T;
  scanf("%d", &T);

  while(T-->0){
    int n,m,i,j,s,k;
    scanf("%d %d", &n, &m);
    int M[n][m];
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	cin>>M[i][j];

    string player="FIRST";
    for(i=0;i<n;i++){
      s=0;
      for(j=0;j<m;j++) s+=M[i][j];
      player=s%2?player:toggle(player);
    }
    cout<<toggle(player)<<endl;
  }
  return 0;
}

