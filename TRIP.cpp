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
#define pb push_back


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

int c[81][81],con[81][81];
char s1[80],s2[80];
int l1,l2;

void lcs()
{
  int i,j,k,t;

  for(i=1;i<=l1;i++){ // corresponds to s1
    for(j=1;j<=l2;j++){ // corresponds to s2
      if(s1[i-1]==s2[j-1]){
	c[i][j]=c[i-1][j-1]+1;
	con[i][j]=3; // LCS character
      }
      else if(c[i][j-1]>c[i-1][j]){ 
	c[i][j]=c[i][j-1];
	con[i][j]=2; // left
      }
      else if(c[i][j-1]<c[i-1][j]){
	c[i][j]=c[i-1][j];
	con[i][j]=1; // up
      }
      else{
	c[i][j]=c[i-1][j];
	con[i][j]=5;  // left || up
      }
    }
  }
}

//set<string> allcs;
set<string> p;

string rev(string &s)
{
  int l=s.length(),i,j;
  string ret="";
  for(i=l-1;i>=0;i--)
    ret+=s[i];
  return ret;
}

void printall(int i,int j,string s)
{
  if(!i||!j){
    p.insert(rev(s));
    return;
  }

  if(con[i][j]==3)
    printall(i-1,j-1,s+s1[i-1]);
  else if(con[i][j]==2)
    printall(i,j-1,s);
  else if(con[i][j]==1)
    printall(i-1,j,s);
  else if(con[i][j]==5){
    printall(i,j-1,s);
    printall(i-1,j,s);
  }
}

void printlcs(int i,int j)
{
  if(i==0||j==0)return;
  if(con[i][j]==3){
    printlcs(i-1,j-1);    
    printf("%c",s1[i-1]);
  }
  else if(con[i][j]==2)printlcs(i,j-1);
  else printlcs(i-1,j);
}

int main()
{
  int i,j,k,t;
  scanf("%d",&t);

  for(i=0;i<=l1;i++)c[i][0]=0;
  for(i=0;i<=l2;i++)c[0][i]=0;
  for(i=0;i<=l1;i++)for(j=0;j<=l2;j++)con[i][j]=0;

  set<string>::iterator it;
  
  while(t--){
    scanf("%s",s1);
    scanf("%s",s2);
    l1=strlen(s1);l2=strlen(s2);

    lcs();
    //printf("%d\n",c[l1][l2]);

    printall(l1,l2,"");

    //    copy(all(p),ostream_iterator<string>(cout,"\n"));

    it=p.begin();
    while(it!=p.end()){
      printf("%s\n",(*it).c_str());
      it++;
    }

    pl;
    
    p.clear();
    bzero(s1,'\0');
    bzero(s2,'\0');
  }
  return 0;
}

