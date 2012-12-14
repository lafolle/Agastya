#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#define pl cout<<endl;
#define all(c) c.begin(),c.end()
using namespace std;

typedef vector<int> vi;


struct f : public unary_function<int ,int>{
  f(){cout<<"Object created!\n";}
  int operator()(int i){return 2*i; }
};

int main()
{
  f *g = new f();
  

  return 0;
}
  
