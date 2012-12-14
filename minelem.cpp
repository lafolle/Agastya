#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> v(3);
  v[0]=0;v[1]=-1;v[2]=-2;
  cout<<*min_element(v.begin(),v.end())<<endl;

  return 0;
}
