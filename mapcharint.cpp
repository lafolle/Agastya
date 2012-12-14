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
#define print(s) cout<<s<<endl
#define SENTINEL 1000000


typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

struct cmp_str{
  bool operator()(char const *a, char const *b){
    return strcmp(a,b)<0;
  }
};

int main()
{
  char name[10],t='\0';
  map<const char *, int> m;
  map<const char *,int>::iterator mit;

  m.insert(make_pair("kcode",1));
  m.insert(make_pair("lafolle",2));

  cout<<sz(m)<<endl;
  
  scanf("%s",name);
  m.insert(make_pair(name,23));

  scanf("%s",name);
  mit=m.find(name);
  if(mit!=m.end())
    printf("Found : %s %d\n",(*mit).first,(*mit).second);
  else printf("Not found\n");

  cout<<sz(m)<<endl;

  map<const char *,int>::iterator it=m.begin();
  while(it!=m.end()){
    printf("%s %d\n",(*it).first,(*it).second);
    it++;
  }
  
  return 0;
}


/*
  So, we are good.
  Better not to use, [] operator.
  Rather use find.
*/
