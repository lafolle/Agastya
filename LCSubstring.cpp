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

int L[2500][2500];
char s1[2500],s2[2500];
int l1, l2;

int lcsub()
{
  int i,j;

  for(i=0;i<l1;i++)
    for(j=0;j<l2;j++){
      if(!i||!j) L[i][j]=s1[i]==s2[j]?1:0;
      L[i][j]= s1[i]==s2[j] ?  L[i-1][j-1]+1 : 0;
    }

  return L[l1-1][l2-1];
}

int main()
{
  int i,j,k;
  scanf("%s",s1);
  scanf("%s",s2);

  l1=strlen(s1);
  l2=strlen(s2);
  
  printf("%d\n",lcsub());
  
  return 0;
}

