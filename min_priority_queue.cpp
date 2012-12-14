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


struct cmp{
  bool operator()(int a,int b){
    if(a<b) false;
    return true;
  }
};

int main()
{
  priority_queue<int, vector<int>, greater<int> > Q;
  Q.push(5);Q.push(6);Q.push(1);
  Q.push(7);Q.push(3);

  cout<<Q.top()<<endl;
  return 0;
}

