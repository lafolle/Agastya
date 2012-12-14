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
#include <iostream>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  int T,i,j,k,wc;
  scanf("%d",&T);

  while(T--){
    string line,t,eng="";
    string arab_after="", arab_before="";
    bool eng_found=false;
    char ch;
    //    scanf("%d", &wc);
    cin>>wc;
    while((ch=getchar())!='\n')
      line+=ch;

    stringstream A(line);
    while(A>>t){
      if(eng_found && t[0]=='#')
	arab_after+=t+" ";
      else if(!eng_found && t[0]=='#')
	arab_before+=t+" ";
      else{
	eng_found=true;
	eng=t;
      }
    }

    if(eng=="" || (arab_after=="" && arab_before=="")){
      cout<<line<<endl;
    }
    else{
      cout<<arab_after+eng+" "+arab_before<<endl;
    }
  }
  return 0;
}

