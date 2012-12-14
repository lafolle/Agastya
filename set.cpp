#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>

#define pl cout<<endl;
#define all(c) c.begin(),c.end()
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;


int main()
{
  int i,j,k;
  set<int > S;
  vector<pii> v(23);

  for(i=0;i<23;i++)S.insert(i*i);

  set<int>::iterator it=S.lower_bound(16);
  cout<<it-S.end()<<endl;
  
  return 0;
}
