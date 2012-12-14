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

int w[100],v[100];
int n,s;

int optimalsol(int s, int i, int val)
{
  if(s<0)return 0;
  if(i==n)return val;
 
  return max(optimalsol(s,i+1,val),
	     optimalsol(s-w[i],i+1,val+v[i]));
}

int main()
{
  int i,j,k;
  
  while(scanf("%d %d",&s,&n)!=EOF){
    for(i=0;i<n;i++)scanf("%d %d",&w[i],&v[i]);
    printf("%d\n",optimalsol(s,0,0));
  }
  
  return 0;
}

