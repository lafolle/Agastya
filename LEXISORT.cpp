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

int main()
{
  int t,n,i;
  char input[10];
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vs v;
    for(i=0;i<n;i++){
      scanf("%s",input);
      v.push_back(string(input));
      bzero(input,'\0');
    }
    sort(all(v));
    for(i=0;i<n;i++)printf("%s\n",v[i].c_str());
  }
  return 0;
}

/*
  with cout - 0.23
  with printf - 0.22
*/
