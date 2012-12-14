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
#define SENTINEL 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;

class ACC{
public:
  string ctrl;
  string bankcode;
  string owner;

  ACC(){}
  ACC(string ctrld,string bc,string ow){
    ctrl=ctrld;
    bankcode=bc;
    owner=ow;
  }
  
  bool operator==(const ACC &a){
    return this->ctrl==a.ctrl&&
      this->bankcode==a.bankcode&&
      this->owner==a.owner;
  }

  void display(){
    string ow1=owner.substr(0,4);
    string ow2=owner.substr(4,8);
    string ow3=owner.substr(8,12);
    string ow4=owner.substr(12,16);    
    printf("%s %s %s %s %s %s",ctrl.c_str(),bankcode.c_str(),ow1.c_str(),ow2.c_str(),ow3.c_str(),ow4.c_str());
  }
  
};

struct cmp{
  bool operator()(const ACC &a, const ACC &b){
    cout<<"Sorting\n";
    if(a.ctrl<b.ctrl)return true;
    else if(a.ctrl>b.ctrl)return false;
    else if(a.bankcode<b.bankcode)return true;
    else if(a.bankcode>b.bankcode)return false;
    else if(a.owner<b.owner)return true;
    else return false;
  }
};

vector<ACC> v(100000);
char ctrl[2],bc[8],ow1[4],ow2[4],ow3[4],ow4[4];

int main()
{
  int t,n,i;
  scanf("%d",&t);
  
  while(t--){
    for(i=0;i<n;i++){
      scanf("%s %s %s %s %s %s",ctrl,bc,ow1,ow2,ow3,ow4);
      v[i]=ACC(string(ctrl),string(bc),string(ow1)+string(ow2)+string(ow3)+string(ow4));
    }
    sort(v.begin(),v.begin()+n,cmp());
    //  for(i=0;i<n;i++)v[i].display();
  }
  
  return 0;
}

