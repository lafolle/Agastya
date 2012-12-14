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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
  int t,i,j,k;
  scanf("%d",&t);

  char p[100],ch;
  int ind[8]={18,27,36,45,54,63,72,81};
  while(t--){
    for(i=1;i<100;i++){
      scanf("%d %c",&j,&ch);
      p[j]=ch;
    }
    ch=p[9];
    for(i=0;i<8;i++)
      if(p[ind[i]]!=ch)
	break;
    printf("%s\n",i==8?"YES":"NO");
  }
  return 0;
}

