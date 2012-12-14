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

void show_parents();

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


int n;
vi rank(SENTINEL);
vi p(SENTINEL);

void create_set(int i)
{
  p[i]=i;
  rank[i]=0;
}

// with union by rank heuristic
int find_set(int x)
{
  if(p[x]==x) return x;
  p[x]=find_set(x);
}

void merge_sets(int x, int y)
{
  cout<<"Merging "<<x<<" and "<<y<<endl;
  int i,px,py;
  px=find_set(x);
  py=find_set(y);
  if(rank[px]<rank[py])
    p[px]=py;
  else p[py]=px;
  if(rank[px]==rank[py]) rank[px]+=1; 
}


int main()
{
  int i;
  n=10;
  for(i=0;i<n;i++)
    create_set(i);

  show_parents();
  merge_sets(2,3);
  show_parents();

  return 0;
}

void show_parents()
{
  cout<<"\nShowing parents\n";
  int i;
  for(i=0;i<n;i++) cout<<i<<' '<<p[i]<<endl;
}

/*
  2 heuristics are :-
  1. union by rank
  2. path compression

  **path compression**
  
  Let 2 subtrees by a and b.
  
  if rank[a]<rank[b], then all members of
  find-set(a) will point to find-set(b), else
  vice-versa.
  In case of tie, ie, rand[a]==rank[b], any one
  is chosen at random and is pointed to other.

  **path compression**

  */
  
