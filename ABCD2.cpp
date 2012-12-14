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

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

char alpha[1000000]={'\0'};
char A[4]={'A','B','C','D'};
vi lft(4,50000);

struct cmp{
  bool operator()(char a, char b){
    return lft[a-'A']>lft[b-'A'];
  }
};

int main()
{
  int n,i,j,k,m;
  while(scanf("%d",&n)!=EOF){
    m=2*n;
    scanf("%s",alpha);
    fill(all(lft),n);
    vi places(4,m);
    for(i=0;i<m;i++){
      lft[alpha[i]-'A']-=1;
      places[alpha[i]-'A']-=1;
    }
    
    sort(A,A+4,cmp());
    char ch;
    k=0;
    for(i=0;i<m;i++){
      ch=alpha[i];

      for(j=0;j<4;j++){
	if(ch==A[j]||!left[A[j]-'A']) continue;

	bool exhauster=false;
	int p;
	for(k=0;k<4;k++){
	  if(A[k]==ch||A[k]==A[j]) continue;
	  p=left[A[k]-'A'];
	  if(p-1<places[A[k]-'A']){
	    exhauster=true;
	    break;
	  }
	}
	if(!exhauster) printf("%c",A[j]);
	// else try another character
      }
    }
  }

  return 0;
}


