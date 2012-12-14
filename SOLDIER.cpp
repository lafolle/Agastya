#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pair<int, int> > vpii;

vpii item[7];
vb present(7,false);
vi len(7);

int getleastq(int a,int b,int c,int d,int e,int f){
  int m=a;
  m=min(m,b);
  m=min(m,c);
  m=min(m,d);
  m=min(m,e);
  m=min(m,f);
  return m;
}

int main()
{
  int n,rub,i,j,k,a,b,c,m,s,l,p,minq;
  
  while(scanf("%d %d",&n,&rub)!=EOF){
    for(i=0;i<n;i++){
      scanf("%d %d %d",&a,&b,&c);
      item[a].push_back(make_pair(b,c));
      present[a]=true;
    }
    
    for(i=1;i<=6;i++)
      if(!present[i])break;
    
    if(i!=7){
      printf("0\n");
      continue;
    }

    for(i=1;i<=6;i++)len[i]=sz(item[i]);

    int maxq=-SENTINEL;
    int localmin;
    for(i=0;i<len[1];i++){
      for(j=0;j<len[2];j++){
	for(k=0;k<len[3];k++){
	  for(l=0;l<len[4];l++){
	    for(m=0;m<len[5];m++){
	      for(p=0;p<len[6];p++){

		s=0;
		s=item[1][i].first+item[2][j].first+item[3][k].first
		  +item[4][l].first+item[5][m].first+item[6][p].first;
		if(s<=rub){
		  localmin=getleastq(item[1][i].second,item[2][j].second,item[3][k].second,
				 item[4][l].second,item[5][m].second,item[6][p].second);
		  maxq=max(maxq,localmin);
		}
		
	      }
	    }
	  }
	}
      }
    }

    if(maxq!=SENTINEL)printf("%d\n",maxq);
    else printf("0\n");
    
    for(i=1;i<=6;i++)item[i].clear();
    fill(all(present),false);
  }
  return 0;
}

