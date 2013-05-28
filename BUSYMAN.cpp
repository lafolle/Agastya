#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define pb push_back 

typedef pair<int,int> ii;
typedef vector<pair<int, int> > vii;

vii v;

struct cmp{
  bool operator()(const ii &a, const ii &b) const{
    return a.second < b.second;
  }
};

int main()
{
  int i,j,k,t,n,c=0;
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    for(i=0;i<n;i++){
      scanf("%d %d", &j, &k);
      v.pb(make_pair(j,k));
    }

    // Greedy algorithm
    sort(v.begin(),v.end(),cmp());
    c=1;
    i=0;
    while(i<n){
      for(k=i+1;k<n and v[k].first<v[i].second;++k);
      if(k==n)break;
      ++c;
      i=k;
    }

    printf("%d\n",c);
    v.clear();
  }
  
}
  
// AC
