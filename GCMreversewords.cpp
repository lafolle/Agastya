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

void clearstream()
{
  while(!cin.eof()&&cin.get()=='\n') ;  
}

int main()
{
  int i,j,k,t;
  string s;
  scanf("%d",&t);
  while(!cin.eof()&&cin.get()=='\n') ;
  char line[1000];
  while(t>0){
    cin.getline(line,1000);    
    istringstream iss(string(line));
    vs v;int l=0;
    while(iss>>s){l+=1;v.push_back(s);}
    for(i=0;i<l;i++) cout<<v[i]<<' ';
    cout<<endl;
    
    printf("%s\n",line);
  }

  return 0;
}

