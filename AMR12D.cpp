#include <iostream>
#include <string>

using namespace std;

int main()
{
  int i,j,t,len;
  string s;
  cin>>t;
  while(t--){
    cin>>s;
    len = s.length();

    for(i=0;i<len;i++)
      if(!(s[i]==s[len-1-i]))break;
    cout << (i==len ? "YES" : "NO") << endl;
  }

  return 0;
}

// AC
