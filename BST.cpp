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

vi v(300000);
int n,r,ri;


int main()
{
  int i,j,s;

  while(scanf("%d",&n)!=EOF){

    fr(i,n)scanf("%d", &v[i]);
    
    r=v[0];
    vi u(v.begin(),v.begin()+n);
    sort(v.begin(),v.begin()+n);
    ri=lower_bound(v.begin(),v.begin()+n,r)-v.begin();
    copy(v.begin(),v.begin()+n,ostream_iterator<int>(cout, " "));pl;
    //    cout<<"Root : "<<r<<'\t'<<"Index : "<<ri<<endl;

    s=0;

    printf("%d\n",0);
    for(j=1;j<n;j++){
      int k=lower_bound(v.begin(),v.begin()+n,u[j])-v.begin();
      s+=abs(k-ri);
      printf("%d\n",s);
    }
  }
  return 0;
}

