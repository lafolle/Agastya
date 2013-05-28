/*
  Counting Connected Components of a graph, with trick
  due to size contraints.

  See previous code.
*/

#include <map>
#include <cstdlib>
#include <stack>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
#define pb push_back
typedef vector<int> vi;

bool visited[200001]={false};
int n,m;
vector<vi > graph(200001);
set<int> S;
pair<set<int>::iterator, bool> si;
map<int,int> M;

void dfs(int r)
{
  int i,j,k,top,sz;
  stack<int> s;
  s.push(r);
  while(!s.empty()){
    top = s.top(); s.pop();
    if(visited[top])continue;
    visited[top]=true;
    sz = M[top];//graph[top].size();
    for(i=0;i<sz;i++)
      s.push(graph[top][i]);
  }
}

int connected_components()
{
  int i,j,k,c=0;
  vi v(S.begin(), S.end());
  int sz=v.size();
  for(i=0;i<sz;i++)
    if(!visited[v[i]]){
      dfs(v[i]);
      ++c;
    }
  return c+n-sz;
}


int main()
{
  int i,j,k;
  scanf("%d %d", &n, &m);
  for(i=0;i<m;i++){
    scanf("%d %d", &j, &k);
    si = S.insert(j);
    if(!si.second)M[j]+=1;
    else M[j]=1;
    si = S.insert(k);
    if(!si.second)M[k]+=1;
    else M[k]=1;
    graph[j].pb(k);
    graph[k].pb(j);
  }

  printf("%d\n", connected_components());

  return 0;
}

// AC  Amazing!!!
