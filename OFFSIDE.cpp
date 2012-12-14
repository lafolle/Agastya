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

vi att(12),def(12);


int main()
{
  int A,D,a_close,d_close1,d_close2,j;
  char ans;
  scanf("%d %d",&A, &D);

  while(A!=0&&D!=0){

    fr(i,A)scanf("%d",&att[i]);
    fr(i,D)scanf("%d",&def[i]);

    sort(att.begin(),att.begin()+A);
    sort(def.begin(),def.begin()+D);    
    

    // get least 2 defenders
    d_close1=min(def[0],def[1]),d_close2=max(def[1],def[0]);    
    for(j=2;j<D-1;j++){
      if(def[j]>def[j+1]){
	d_close1=min(d_close1,def[j+1]);
	d_close2=min(d_close2,def[j]);
      }
      else{
	d_close1=min(d_close1,def[j]);
	d_close2=min(d_close2,def[j+1]);
      }
    }

    for(j=0;j<A;j++){
      if(att[j]>d_close1 && att[j]<d_close2){
	printf("Y\n");
	break;
      }
    }

    if(j==A)
      printf("N\n");

    scanf("%d %d",&A,&D);
    
  }
  
  return 0;
}

