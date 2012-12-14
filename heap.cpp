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

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;

#define LEFT(i)  (i<<1)+1
#define RIGHT(i) (i<<1)+2
#define PARENT(i) (i%2?i>>1:(i>>1)-1) // doubt here

int n;
int hs;
vi v(SENTINEL);

void minify_heap(int i, int n)
{
  int ri=RIGHT(i),li=LEFT(i),smallest;

  if(ri>=n||ri>=n)return;
  
  if(v[li]<v[i]) smallest=li;
  else smallest=i;
  if(v[ri]<v[smallest]) smallest=ri;
  if(smallest!=i){
    swap(v[i],v[smallest]);
    minify_heap(smallest,n);
  }
}

void build_heap(int n)
{
  int i;
  for(i=(n/2)-1;i>=0;i--)
    minify_heap(i,n);
}

int getmin(){return v[0];}

int mintop(){return v[0];}
void poptop()
{
  if(hs==0){
    cout<<"Heap size is 1\n";
    return;
  }
  swap(v[0],v[hs]);
  minify_heap(0,hs-1);
  hs-=1;
}

// change key of an element
void changekey(int k, int i)
{
  if(k==v[i]) return;
  if(k<v[i]){
    v[i]=k;
    while(i>0&&v[PARENT(i)]>v[i]){
      swap(v[i],v[PARENT(i)]);
      i=PARENT(i);
    }
  }
  else{
    v[i]=k;
    minify_heap(i,n);
  }
}

void insertkey(int key)
{
  hs+=1;
  v[hs]=SENTINEL;
  changekey(key,hs);
}

int main()
{
  int i,j,k;
  cin>>n;
  hs=n-1;
  for(i=0;i<n;i++) scanf("%d",&v[i]);cin.clear();
  copy(v.begin(),v.begin()+n,ostream_iterator<int>(cout," "));pl;
  
  build_heap(n);
  copy(v.begin(),v.begin()+hs+1,ostream_iterator<int>(cout," "));pl;

  changekey(1,6);
  //  insertkey(1);
  copy(v.begin(),v.begin()+hs+1,ostream_iterator<int>(cout," "));pl;  
  
  return 0;
}

  
