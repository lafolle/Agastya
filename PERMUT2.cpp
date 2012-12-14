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

vi v(100001);
vb visited(100001,false);

int main()
{
  int n,c;
  int i,j,k;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    for(i=1;i<=n;i++)scanf("%d",&v[i]);
    c=0;
    for(i=1;i<=n;i++){
      if(visited[i])continue;
      if(v[i]==i) visited[i]=true;
      else if(i==v[v[i]])
	visited[v[i]]=true;
      else if(i!=v[v[i]])break;
    }
    if(i>n)printf("ambiguous\n");
    else printf("not ambiguous\n");

    fill(visited.begin(),visited.begin()+n+1,false);
  }
  return 0;
}

/*
  AC
*/
