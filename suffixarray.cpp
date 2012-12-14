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

int suffix_array[250000];
vs suffixes;

struct cmp{
  bool operator()(int i, int j){
    return suffixes[i]<suffixes[j];
  }
};

int main()
{
  string s;
  int len;
  int i,j,k;

  while(1){

    double t0=clock();
    
    suffixes.clear();
    
    cin>>s;
    len=s.length();

    for(i=0;i<len;i++){
      suffixes.push_back(s.substr(i,len-i));
      suffix_array[i]=i;
    }

    cerr<<(clock()-t0)*0.001<<endl;
    
    sort(suffix_array, suffix_array+len,cmp());

    for(i=0;i<len;i++)
      printf("%d %s\n",suffix_array[i], suffixes[suffix_array[i]].c_str());

    cerr<<(clock()-t0)*0.001<<endl;
    
  }
  return 0;
}

