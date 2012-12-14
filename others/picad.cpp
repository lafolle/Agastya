
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef pair<int,char>  PI;
const int inf=1<<25;
int main()
   {

      int p,k,n,x,y,l,h;
      vector<PI> V_in;
      while(scanf("%d%d",&p,&k)==2)
      {
         V_in.clear();
         scanf("%d",&n);
         for(int i=0;i<n;i++)//clip the interval
         {
            scanf("%d%d",&x,&y);
            l=max(x,p),h=min(y,k);            
            if(l<=h)V_in.push_back(PI(l,'A')),V_in.push_back(PI(h,'L'));               
         }
         sort(V_in.begin(),V_in.end());
         //cout<<"v_in\n";
         //for(int i=0;i<V_in.size();i++) cout<<V_in[i].first<<" "<<V_in[i].second<<"\n";
         //printf("\n");
         if(V_in.size()==0) { cout<<"0 0\n";continue;}//no common interval
         if(k==V_in[0].first || p==V_in[V_in.size()-1].first){cout<<"0"<<" "<<V_in.size()/2<<endl;continue;}//side overlapping of crime interval
         stack<PI> S;
         int ret_mx=-inf,ret_mn=inf;
         
         for(int i=0;i<V_in.size();i++)
          {
            if(V_in[i].first>=k)break;
            if(V_in[i].second=='A') 
             {
               S.push(V_in[i]);
               ret_mx=max(ret_mx,(int)S.size());
               ret_mn=min(ret_mn,(int)S.size());
             }
            if(V_in[i].second=='L')
            {
               if(!S.empty())S.pop();
               ret_mx=max(ret_mx,(int)S.size());
                                        ret_mn=min(ret_mn,(int)S.size());
            }
         }
         if(ret_mn==inf) ret_mn=0;
         if(ret_mx==-inf) ret_mx=0;
         cout<<ret_mn<<" "<<ret_mx<<endl;
       }
   }
