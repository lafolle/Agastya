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

struct webpage{
  char url[100];
  int rel;
  int ind;
  webpage(){}
  webpage(int i,char u[], int r){
    strcpy(url,u);
    rel=r;
    ind=i;
  }
};

struct cmp{
  bool operator()(const webpage &a, const webpage &b){
    if(a.rel>b.rel) return true;
    else if(a.rel<b.rel) return false;
    else if(a.ind<b.ind)return true;
    else return false;
  }
};
  
int main()
{
  int t,i,j,k,rel,b=0;
  char url[100];
  scanf("%d",&t);
  
  while(t--){
    vector<webpage> v(10);
    for(i=0;i<10;i++){
      scanf("%s %d",url,&rel);
      v[i]=webpage(i,url,rel);
      bzero(url,'\0');
    }


    sort(all(v),cmp());
    
    int d=v[0].rel;
    printf("Case #%d:\n",++b);
    for(i=0;i<10;i++){
      if(v[i].rel==d)
	printf("%s\n",v[i].url);
      else break;
    }
    
  }
  
  return 0;
}


// AC
