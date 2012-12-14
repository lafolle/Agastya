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

#define DLIMIT 1000000

class BigNumber{
  vi v;
public:
  BigNumber(){};
  BigNumber(string s){
    int l=s.length(),i;
    for(i=0;i<l;i++)v.push_back(s[i]-'0');
  }
  BigNumber(vi &m){
    v=m;
  }
  
  BigNumber operator+(const BigNumber &a){
    int l1=sz(v),l2=sz(a.v),i,j,carry=0,k;
    vi m;
    for(i=0;i<l1&&i<l2;i++){
      k=v[i]+a.v[i]+carry;
      m.push_back(k%10);
      carry=k/10;
    }
    if(l1==l2)
      m.push_back(carry);
    else{
      if(l1<l2){
	for(i=i;i<l2;i++){
	  k=a.v[i]+carry;
	  m.push_back(k%10);
	  carry=k/10;
	}
      }
      else{
	for(i=i;i<l1;i++){
	  k=v[i]+carry;
	  m.push_back(k%10);
	  carry=k/10;
	}
      }
    }
    return BigNumber(m);
  }

  void show(){
    copy(this->v.begin(),this->v.end(),ostream_iterator<int>(cout,""));
  }
};

int main()
{
  BigNumber a("123123123132123123123123123"),b("77980324720938093475902384752890374529034792034875932847"),c;
  a.show();
  printf(" + ");
  b.show();pl;

  
  c=a+b;

  c.show();pl;

  return 0;
}

