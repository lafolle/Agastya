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


char *multiply(char *a, char *b)
{
  int l1=strlen(a),l2=strlen(b);
  int i,j,k,carry,d,f=0,g;

  if(l1>l2){
    int c[2*l2+1],tmp[2*l2+1];
    for(i=l2-1;i>=0;i--){
      carry=0;
      f=0;
      for(j=l1-1;j>=0;j--){
	d=a[i]-'0'*b[j]-'0'+carry;
	carry=d/10;
	k=d%10;
	tmp[2*l2-i-f++]=k;
      }
      for(g=2*l2-i+1;g<2*l2;g++)tmp[g]=0;
      
    }
  }
  else{
  }
}


int main()
{
  int n,i,j,k;
  scanf("%d",&n);
  char a[10000],b[10000];

  while(n--){
    scanf("%s %s",a,b);
    printf("%s\n",multiply(a,b));
  }
  return 0;
}

// aborted
