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
#define INF 1000001


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

int n;
char charlst[10001][10];

struct Node{
  char key;
  struct Node *children[10];
  Node(){}
};

Node root;

void insert_trie(int ind)
{
  int j,len;
  if(ind==0){
    Node node;
    len=strlen(charlst[ind]);
    for(j=0;j<len;j++){
      
    }
  }
}

void createtrie()
{
  int i;
  for(i=0;i<n;i++)
    insert_trie(i);
}

int main()
{
  int i,j,k=0,t;

  scanf("%d",&t);

  while(t--){

    scanf("%d",&n);

    for(i=0;i<n;i++)scanf("%s",charlst[i]);

    createtrie();
  }
}


