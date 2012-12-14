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

using namespace std;

class RedAndGreen {
public:
	int minPaints(string);
};

int RedAndGreen::minPaints(string row) {
	int i,n=row.size(),rs=0,gs=0,ans=1000;
	for(i=0;i<n;i++){
		if(row[i]=='G') ++gs;
		else ++rs;
	}
	
	int lg=0,rr=rs;
	for(i=0;i<n;i++){
	  ans=std::min(ans,rr+lg);
	  if(row[i]=='R') --rr;
	  if(row[i]=='G') ++lg;
	}
	
	return ans;
	 
}

int main()
{
  int i,j;
  string s = "RGRGR";

  RedAndGreen r;

  // Test 1
  {
    s = "RGRGR";
    cout<<r.minPaints(s)<<endl;
  }

  // Test 2
  {
    s = "RRRGGGGG";
    cout<<s<<'\n'<<r.minPaints(s)<<endl;
  }

  // Test 3
  {
    s = "GGGGRRR";
    cout<<s<<'\n'<<r.minPaints(s)<<endl;    
  }

  // Test 4
  {
    s = "RGRGRGRGRGRGRGRGR";
    cout<<s<<'\n'<<r.minPaints(s)<<endl;    
  }

  // Test 5
  {
    s = "RRRGGGRGGGRGGRRRGGRRRGR";
    cout<<s<<'\n'<<r.minPaints(s)<<endl;
  }
  
  return 0;
}

