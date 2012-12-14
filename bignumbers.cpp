#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#define all(c) c.begin(),c.end()
using namespace std;

typedef vector<int> vi;



int main()
{

  int n=50e6,i,b;
  vi v(n);
  for(i=0;i<n;i++)
    v[i]=i;
  b=accumulate(all(v),0);
  cout<<b<<endl;
  return 0;
}
