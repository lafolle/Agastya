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

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;

int A[100],L[100];
int n;

int compute()
{
  int i,j,k;
  int ml;

  for(i=1;i<n;i++){
    ml=0;
    for(j=0;j<i;j++){  // compute max L in [0,i) such that A[j]<A[i]
      if(A[j]<A[i] && L[j]>ml)  
	ml=L[j];
    }
    L[i]=ml+1;
  }
  return L[n-1];
}

int main()
{
  int i,j,k;
  scanf("%d",&n);
  i=0;
  fr(i,n)scanf("%d",&A[i]);
  fr(i,n)L[i]=0;
  cout<<compute()<<endl;
  return 0;
}

