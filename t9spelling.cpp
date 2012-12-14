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
#define SENTINEL 1000000


typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

vi m(26),v(26);

void init()
{
  const char a='a';
  m['a'-a]=2;v['a'-a]=1;
  m['b'-a]=2;v['b'-a]=2;
  m['c'-a]=2;v['c'-a]=3;

  m['d'-a]=3;v['d'-a]=1;
  m['e'-a]=3;v['e'-a]=2;
  m['f'-a]=3;v['f'-a]=3;

  m['g'-a]=4;v['g'-a]=1;
  m['h'-a]=4;v['h'-a]=2;
  m['i'-a]=4;v['i'-a]=3;

  m['j'-a]=5;v['j'-a]=1;
  m['k'-a]=5;v['k'-a]=2;
  m['l'-a]=5;v['l'-a]=3;

  m['m'-a]=6;v['m'-a]=1;
  m['n'-a]=6;v['n'-a]=2;
  m['o'-a]=6;v['o'-a]=3;

  m['p'-a]=7;v['p'-a]=1;
  m['q'-a]=7;v['q'-a]=2;
  m['r'-a]=7;v['r'-a]=3;
  m['s'-a]=7;v['s'-a]=4;

  m['t'-a]=8;v['t'-a]=1;
  m['u'-a]=8;v['u'-a]=2;
  m['v'-a]=8;v['v'-a]=3;

  m['w'-a]=9;v['w'-a]=1;
  m['x'-a]=9;v['x'-a]=2;
  m['y'-a]=9;v['y'-a]=3;
  m['z'-a]=9;v['z'-a]=4;
}

#define LIMIT 1000

int main()
{
  int t,i,j,k,b=1;
  scanf("%d",&t);
  const char a='a',space=' ';
  char messg[LIMIT],prev;
  init();
  while(t--){
    //    printf("Case #%d: ",b++);
    cout<<"Case #"<<b++<<": ";
    k=read(0,messg,LIMIT);messg[--k]='\0';
    prev=messg[0];
    if(prev==' ')
      cout<<'0';
    else
      for(i=0;i<v[prev-a];i++)cout<<m[prev-a];

    for(i=1;i<k;i++){
      if(messg[i]==space){
	if(prev==space)
	  cout<<" 0";
	else cout<<'0';
	prev=space;
	continue;
      }
      if(prev!=space){
	if(m[messg[i]-a]==m[prev-a])
	  cout<<' ';
      }
      for(j=0;j<v[messg[i]-a];j++)cout<<m[messg[i]-a];
      prev=messg[i];

    }
    pl;
  }
  
  return 0;
}

