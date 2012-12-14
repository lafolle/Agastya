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
  int N;
  double tq_p,h_p;
  int q=0,h=0,tq=0;
  
  int n,d;

  scanf("%d", &N);

  while(N>0){
    scanf("%d/%d", &n,&d);
    if(n==1&&d==4) ++q;
    else if(n==1&&d==2) ++h;
    else ++tq;
    --N;
  }

  tq_p=tq;
  h_p=ceil(h/2.0);
  if(h_p*2>h && q>2) q-=2; // half pizzas
  q=tq_p>q?0:q-tq_p;
  if(q!=0) q=ceil(q/4.0);

  printf("%.0lf\n",tq_p+h_p+q+1);
  return 0;
}

