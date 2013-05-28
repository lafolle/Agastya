#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long int ll;

int  main()
{
  int i,j,t;
  scanf("%d", &t);
  string s;
  ll  ans,k;

  cin >>i>>j;
  cout << (i/j) << endl;
  
  while(t--){
    scanf("%lld",&ans);
    cin>>s;
    
    while(s!="="){
      scanf("%d", &k);  // get number
      if(s=="+")
	ans+=k;
      else if(s=="*")
	ans*=k;
      else if(s=="/")
	ans/=k;
      else ans-=k;
      cin>>s;  // get operator
    }
    cout<<ans<<endl;
  }

  return 0;
}

// AC
