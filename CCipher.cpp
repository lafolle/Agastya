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

using namespace std;


class CCipher {
public:
  CCipher (){}
  string decode(string, int);
};

string CCipher::decode(string cipherText, int shift) {
  int i,k;
  string s="";

  for(i=0;i<cipherText.size();i++){

    k=cipherText[i]-shift;

    if(k>='A') s+=k;

    else s+='Z'-('A'-k)+1;
	  
  }
	
  return s;
};


int main()
{
  CCipher c;

  cout << c.decode("VQREQFGT",2) <<endl;

    cout << c.decode("ABCDEFGHIJKLMNOPQRSTUVWXYZ",10) <<endl;
}

// AC
