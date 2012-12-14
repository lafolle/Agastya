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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

#define LEFT(i)  (i<<1)+1
#define RIGHT(i) (i<<1)+2
#define PARENT(i) (i%2?i>>1:(i>>1)-1) // doubt here

void PriorityQueue::minifyheap(int i, int n)
{
  int ri=RIGHT(i),li=LEFT(i),smallest;

  if(ri>=n||ri>=n)return;
  
  if(v[li]<v[i]) smallest=li;
  else smallest=i;
  if(v[ri]<v[smallest]) smallest=ri;
  if(smallest!=i){
    swap(v[i],v[smallest]);
    minifyheap(smallest,n);
  }
}

void PriorityQueue::buildheap(int n)
{
  int i;
  for(i=(n/2)-1;i>=0;i--)
    minifyheap(i,n);
}

void PriorityQueue::changekey(int k, int i)
{
  if(k==v[i]) return;
  if(k<v[i]){
    v[i]=k;
    while(i>0&&v[PARENT(i)]>v[i]){
      swap(v[i],v[PARENT(i)]);
      i=PARENT(i);
    }
  }
  else{
    v[i]=k;
    minifyheap(i,n);
  }
}

int PriorityQueue::getmin(){return v[0];}

void PriorityQueue::poptop()
{
  if(hs==0){
    cout<<"Heap size is 1\n";
    return;
  }
  swap(v[0],v[hs]);
  minifyheap(0,hs-1);
  hs-=1;
}

PriorityQueue::PriorityQueue(int s)
{
  n=s;
  v.resize(n);
}

PriorityQueue::PriorityQueue(vi m, int s)
{
  n=s;
  v=m;
  buildheap(n);
}
  
