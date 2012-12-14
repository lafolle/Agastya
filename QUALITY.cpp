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
  vi T(3),A(3);
  int i,j,k=1,ps=0,tt=0;
  while(scanf("%d %d %d %d %d %d", &T[0],&T[1],&T[2],&A[0],&A[1],&A[2])!=EOF){
    ps=0;
    tt=0;
    for(i=0;i<3;i++)
      if(T[i]!=0){
	++ps;
	tt+=T[i]+(A[i]-1)*1200;
      }
    printf("team %d: %d, %d\n",k,ps,tt);
    ++k;
  }
  return 0;
}

