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

long long int compute_seconds(int y, int by)
{
  int i,j,d;
  long long int s=0;
  for(i=by;i<y+1;i++){
    d=((i%4==0&&i%100!=0)||i%400==0)?366:365;
    s+=d*24*60*60;
  }
  return s;
}

int main()
{
  int y,t;
  long long int seconds;
  int base_year=1970;
  cout<<"Base year : "<<base_year<<endl;
  scanf("%d",&t);
  while(t--){
    cout<<"Enter year : ";
    scanf("%d",&y);
    seconds=compute_seconds(y,base_year);
    cout<<"From "<<base_year<<" to "<<y<<" : "<<seconds<<" seconds\n";
  }
  
  return 0;
}

