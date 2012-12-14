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
#define pb push_back


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

int n,cnt,sum;
int B[1000];
vi v,m(1000);

void enumerate(int k)
{
  if(k>=n){
    copy(B,B+n,ostream_iterator<int>(cout, " "));pl;
    ++cnt;
    return;
  }

  B[k]=0;
  enumerate(k+1);

  B[k]=1;
  enumerate(k+1);

}

int main()
{
  int i;

  while(scanf("%d",&n)!=EOF){
    cnt=0;
    sum=0;
    enumerate(0);
    printf("%d\n",cnt);
  }
  
  return 0;
}

