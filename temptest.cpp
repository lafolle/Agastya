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


class Node{
  int u;
  int d;
public:
  Node(){}
  Node(int a){d=a;}
  bool operator<(const Node &a){
    return this->d<a.d;
  }
};
  
template<class T>
class Person{
public:  
  T k;
  Person(){}
  Person(T m){k=m;}
  bool operator<(const T &a){
    return *this<a;
  }
};

int main()
{
  Node a(23),b(32);
  Person<Node> n(a),m(b);
  cout<<boolalpha<<(n<m)<<endl; 
  cout<<boolalpha<<(n>m)<<endl; 
  return 0;
}

