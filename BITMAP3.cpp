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

int n,m;
char bm[182][182];

struct manhattan{
  bool operator()(const pii &a, const pii &b){
    if(a.first+a.second > b.first+b.second)return true;
    else if(a.first+a.second < b.first+b.second)return false;
    else return true;
  }
};

int main()
{
  int t,i,j,k;
  scanf("%d",&t);
  
  while(t--){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",bm[i]);

    vpii v;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	if(bm[i][j]=='1')v.push_back(make_pair(i,j));

    sort(all(v),manhattan());

    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	
      }
    }
  }
  return 0;
}

