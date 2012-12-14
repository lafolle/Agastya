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

class BigNum{

  vi v,tv(10001);
  int len;

public:
  BigNum(){
    v.resize(10000);
    len=10000;
  }
  BigNum(char u[10000]){
    len=strlen(u);
    int i;
    for(i=0;i<len;i++)v.push_back(u[i]-'0');
  }

  BigNum(vi &u){
    v=u;
    len=u.size();
  }

  BigNum operator*(BigNum &u){
    int l=u.len,i,j,k;
    
    if(l<len){
      
    }
    else{
      
    }
  }
};

int main()
{
  int n,i,t;
  char a[10000],b[10000];
  while(t--){
    scanf("%s %s",a, b);
    BigNum n1(a), n2(b);
    
  }
  return 0;
}

