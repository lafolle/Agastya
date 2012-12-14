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
#define SENTINEL 1000000


typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef vector<long long int> vlli;

int main()
{
  int t,n,p=1;
  cin>>t;
  while(t-->=2){
    // cin>>n;
    n=t;
    long long int k=pow(3+sqrt(5),n);cout<<k<<endl;
    vlli v(3);
    v[0]=k%10L;k/=10L;
    v[1]=k%10L;k/=10L;
    if(k==0){v[2]=0;}
    else v[2]=k%10;
    printf("Case #%d: ",p++);
    cout<<v[2]<<v[1]<<v[0]<<endl;
  }
  return 0;
}

