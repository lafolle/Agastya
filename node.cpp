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

struct Node{
  int d;
  int u;
  Node(){
    d=0;
    u=0;
  }
  Node(int ind, int dist){
    d=dist;
    u=ind;
  }
  bool operator<(const Node &a){
    return this->d<a.d;
  }
  bool operator>(const Node &a){
    return this->d>a.d;
  }
  Node operator=(const Node &a){
    Node t;
    t.d=a.d;
    t.u=a.u;
    return t;
  }
  bool operator==(const Node &a){
    return this->d==a.d;
  }
};

ostream& operator<<(ostream& os, const Node &a){
  os<<a.u<<' '<<a.d<<endl;
  return os;
}

int main()
{
  vector<Node> v;
  int i,j,n=23;
  for(i=0;i<23;i++)v.push_back(Node(i,rand()%100));

  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if(v[i]==v[j]){
	cout<<"Duplicate found at "<<i<<' '<<j<<endl;
	break;
      }

  copy(all(v),ostream_iterator<Node>(cout,""));
  
  return 0;
}

