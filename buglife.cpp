#include<cstdio>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<algorithm>
#include<map>

using namespace std;

int bipartite_matching(vector<list<int> > graph)
{
  int temp,i;
  vector<int> included;
  vector<bool> flag;
  queue<int> gray;
  list<int>::iterator lit;
  included.resize(graph.size(),0);
  flag.resize(graph.size(),0);
  for(int i=0;i<graph.size();i++){if(included[i]==0){
      gray.push(i);
      included[i]=1;
      flag[i]=0;
      while(!gray.empty())
	{
	  temp=gray.front();
	  gray.pop();
	  for(lit=graph[temp].begin();lit!=graph[temp].end();lit++)
	    {
	      if(included[*(lit)]==0)
		{
		  flag[*(lit)]=!flag[temp];
		  gray.push(*(lit));
		  included[*(lit)]=1;
		}
	      else
		{
		  if(flag[temp]==flag[*(lit)])
		    return 0;
		}
	    }
	}
    }
  }
  return 1;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int q=1;q<=t;q++)
    {
      int n;
      long long int m;
      scanf("%d %lld",&n,&m);
      vector<list<int> > graph(n);
      for(long long int i=0;i<m;i++)
	{
	  int x,y;
	  scanf("%d %d",&x,&y);
	  graph[x-1].push_back(y-1);
	  graph[y-1].push_back(x-1);
	}
      printf("Scenario #%d:\n",q);
      int ans=bipartite_matching(graph);
      if(ans)
	printf("No suspicious bugs found!\n");
      else
	printf("Suspicious bugs found!\n");
    }
  return 0;
}

// getting TLE
