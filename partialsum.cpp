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

int main()
{
  const int N = 10;
  int A[N];

  fill(A, A+N, 1);
  cout << "A:                 ";
  copy(A, A+N, ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Partial sums of A: ";
  partial_sum(A, A+N, ostream_iterator<int>(cout, " "));
  cout << endl;
}  
