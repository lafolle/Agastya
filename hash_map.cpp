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
#include <hash_set>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx; // important for hash_map

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


struct eqstr{
  bool operator()(const char *a, const char * b) const{
    return strcmp(a,b)==0;
  }
};

int main()
{
  hash_map<const char *, int, hash<const char *>, eqstr> hm;

  int i,j,k;
  char input[20];

  while(scanf("%s", input)!=EOF){
    if(!strcmp(input, "kidding"))break;
    if(hm.find(input)==hm.end())
      hm[input]=strlen(input);
    else printf("%s is already there!\n",input);
  }

  while(scanf("%s",input)!=EOF){
    if(hm.find(input)==hm.end())
      printf("%s is not present\n",input);
    else printf("%s : %d\n",input, hm[input]);
  }
  
  return 0;
}

