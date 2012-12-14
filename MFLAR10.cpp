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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  string s='';
  char ch,fon='',prev='';
  ch=getchar();
  prev=ch;
  
  while(true){
    ch=getchar();
    if(ch==' ') continue;
    if(prev=='\n'&&ch!='\n'&&ch!=' '){
      fon=ch;
      check(s);
    }
      
    s+=ch;
  }
  return 0;
}

