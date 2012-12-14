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
typedef vector<char *> vcs;
typedef pair<int,string> pis;
typedef   multimap<int,string,greater<int> > mm;

struct cmp_str{
  bool operator()(char const *a, char const *b){
    return strcmp(a,b)<0;
  }
};
//typedef map<const char *, vcs,cmp_str> Tree;
typedef map<string,vs > Tree;

Tree tree;
int n,d;

void displaytree()
{
  Tree::iterator it=tree.begin();
  int i;
  pair<string, vs> p;
  while(it!=tree.end()){
    p=*it;
    cout<<p.first<<endl;cout<<'\t';
    for(i=0;i<(p.second).size();i++)cout<<(p.second)[i]<<' ';pl;
    it++;
  }
}


Tree::iterator tor;

int finddesc(string pa,int x)
{
  if(x==d)return 1;
  tor=tree.find(pa);
  if(tor==tree.end())return 0;
  vs cvec=(*tor).second;
  int i,k=0,s=sz(cvec);
  for(i=0;i<s;i++)
    k+=finddesc(cvec[i],x+1);
  return k;
}

int zfinddesc(string pa)
{
  tor=tree.find(pa);
  if(tor==tree.end())return 1;
  return 0;
}


int main()
{
  int t,i,j,k=1,cc,caseID=1;
  char name[10],parent[10];
  Tree::iterator it;
  mm S;
  string  pa;
  vs chld;
  
  scanf("%d",&t);
  while(t--){

    printf("Tree %d: \n",caseID++);
    scanf("%d %d",&n,&d);

    for(i=0;i<n;i++){
      scanf("%s %d",parent,&cc);
      for(j=0;j<cc;j++){
	scanf("%s",name);
	chld.push_back(string(name));
      }
      tree.insert(make_pair(string(parent),chld));
      chld.clear();
    }

    it=tree.begin();

    while(it!=tree.end()){
      pa=(*it).first;
      k=finddesc(pa,0);
      if(k)S.insert(make_pair(k,pa));
      it++;
    }

    //    displaytree();exit(1);
    mm::iterator mit=S.begin();
    pis elem;
    int c=0,pval;

    while(mit!=S.end()){
      elem=*mit;
      if(!elem.first)break;
      if(c<3){
	printf("%s %d\n",(elem.second).c_str(),elem.first);
	pval=elem.first;
	++c;
      }
      else if(elem.first==pval)
	printf("%s %d\n",(elem.second).c_str(),elem.first);	
      else break;
      mit++;
    }pl;

    tree.clear();
    S.clear();
  }


  return 0;
}

// WA
