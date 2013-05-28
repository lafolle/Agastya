#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
vector<string> v;
char numb[10];

int main()
{
  int i,j,k,t;
  scanf("%d", &t);

  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s",numb);
      v.push_back(string(numb));
    }
    sort(v.begin(),v.end());
    for(i=0;i<n-1;i++)
      if(v[i+1].substr(0,v[i].length())==v[i]) break;
    printf("%s\n", i==n-1 ? "YES" : "NO");
    v.clear();
  }
  return 0;
}

// AC
