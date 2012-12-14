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

int n,C;
int value[105], cost[105];
int table[105][505];

void compute()
{
  int i,j,k;

  for(i=0;i<=C;i++)table[0][i]=0;
  
  for(i=1;i<=n;i++)
    for(j=0;j<=C;j++)
      table[i][j]=j<cost[i] ? table[i-1][j]:max(table[i-1][j],
						value[i]+table[i-1][j-cost[i]]);
}

int main()
{
  int i,j,k,t;

  int t_val;

  scanf("%d %d", &C, &n);

  while(n!=0 && C!=0){

    for(i=1;i<=n;i++) scanf("%d %d", &cost[i], &value[i]);
    
    compute();

    int t_cost=0,cst,item;

    for(i=C;i>=0&&table[n][i]==table[n][C];i--);
    
    printf("%d %d\n",i+1, table[n][C]);
    
    scanf("%d %d", &C, &n);
    
  }
  
  return 0;
}

// AC
