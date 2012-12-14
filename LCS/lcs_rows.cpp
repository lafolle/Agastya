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

//int c[81][81];
char s1[80],s2[80];
int l1,l2;
int c[2][81];

void space_optimised_lcs()
{
}




int main()
{
  int i,j,k,t;
  scanf("%d",&t);

  while(t--){
    scanf("%s",s1);
    scanf("%s",s2);
    l1=strlen(s1);l2=strlen(s2);

    for(i=0;i<=l1;i++)c[i][0]=0;
    for(i=0;i<=l2;i++)c[0][i]=0;

    lcs();
    printf("%d\n",c[l1][l2]);
    
  }
  return 0;
}

