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
typedef vector<bool> vb;

int bs(int from_pivot,int pivot, int n, int low, int high, const vi &v, vb &marked)
{
  return -1;
}

int main()
{
  const int m = 5;
  int A[m] = {4,5,7, 3, 9};
  int n,res;
  vi v(A,A+m);
  vb marked(m, false);
  vi::iterator it,ti;
  
  sort(all(v));
  copy(all(v), ostream_iterator<int>(cout, " "));pl;
  cout<<"Enter lower limit : ";
  scanf("%d",&n);

  cout<<"Doing search in Binary Tree ... \n";
  //  res=bs(m/2, n, 0, m-1, v, marked);
  it = lower_bound(all(v), n);
  ti = upper_bound(all(v), n);
  cout<<"Number of elements less than "<<n<<" are "<<it-v.begin()<<endl;
  cout<<"Number of elements greater than "<<n<<" are "<<v.end()-ti<<endl;  
  
  return 0;
}

