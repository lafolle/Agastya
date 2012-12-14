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

struct Node{
  int d;
  int u;
  Node(){}
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

ostream& operator<<(ostream& os, const Node &a)
{
  os<<a.u<<' '<<a.d<<endl;
  return os;
}

/*
  Appropriate comparator of type T should be present.
*/

template<class T>
class PriorityQueue{
  int n; 
  int hs; 
  vector<T> v; // heap inner datastructure
public:
  PriorityQueue();
  PriorityQueue(int );
  PriorityQueue(vector<T>);

  void minifyheap(int , int );
  void buildheap(int );
  void changekey(T , int);
  T getmin();
  void poptop();
  void showheap();
  void insertkey(T);
};

template<class T>
void PriorityQueue<T>::insertkey(T key)
{
  ++n;
  hs+=1;
  v[hs]=Node(hs,SENTINEL);
  changekey(key,hs);
}


template<class T>
void PriorityQueue<T>::showheap()
{
  int i;
  for(i=0;i<n;i++)cout<<v[i];
}

// minify heap of type T
template<class T>
void PriorityQueue<T>::minifyheap(int i, int n)
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

// build heap of size n
template<class T>
void PriorityQueue<T>::buildheap(int n)
{
  int i;
  for(i=(n/2)-1;i>=0;i--)
    minifyheap(i,n);
}

template<class T>
void PriorityQueue<T>::changekey(T k, int i)
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

template<class T>
T PriorityQueue<T>::getmin(){return v[0];}

template<class T>
void PriorityQueue<T>::poptop()
{
  if(hs==0){
    cout<<"Heap size is 1\n";
    return;
  }
  swap(v[0],v[hs]);
  minifyheap(0,hs-1);
  hs-=1;
}

// constructors
template<class T>
PriorityQueue<T>::PriorityQueue(int s)
{
  n=s;
  v.resize(n);
}

template<class T>
PriorityQueue<T>::PriorityQueue(vector<T> m)
{
  n=sz(m);
  v=m;
  hs=n-1;
  buildheap(n);
}

template<class T>
PriorityQueue<T>::PriorityQueue(){
  hs=-1;
  n=0;
}

int main()
{
  vector<Node> v;
  int i;
  PriorityQueue<Node> Q;  
  for(i=0;i<23;i++){
    Q.insertkey(Node(i,rand()%100));
    cout<<Q.getmin();
  }

  return 0;
}
