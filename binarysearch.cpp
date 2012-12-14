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

int bs(int pivot, int low, int up, vi &v, int key)
{
  if(v[pivot]==key) return pivot;

  if(low<up){
    if(key<v[pivot]) up=pivot-1;
    else low=pivot+1;
    return bs((up+low)/2, low, up, v, key);
  }
  return -1;
}

int main()
{
  int a[10] = {1,4,5,7,8,3,4,0,9,6};
  vi v(a,a+10);
  sort(all(v));


  int res,i;

  for(i=0;i<10;i++){
    res=bs(4,0,9,v,a[i]);
    //    copy(all(v), ostream_iterator<int>(cout," "));pl;
    cout<<(a[i]==v[res]?"Success":"Failure")<<endl;
  }

  res=bs(4,0,9,v,23);
  cout<<res<<endl;

  
  return 0;
}

