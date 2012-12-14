#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
   int t;
   scanf("%d",&t);
   int n,i,j,k;
   while(t--){
      scanf("%d",&n);
      int m[n][3];
      for(i=0;i<n;i++){
         for(j=0;j<3;j++){
            scanf("%d",&m[i][j]);
         }
      }
      int sum = 0;
      if(n==2){
         int mk = *min_element(m[0],m[0]+3);
         int mk1  = *min_element(m[1],m[1]+3);
         sum = sum + mk + mk1;
      }
      else {
      int minn = m[n-1][0];
      int index = 0,index1=0;

      for(i=1;i<3;i++){
         if(m[n-1][i]<minn){
            minn = m[n-1][i];
            index = i;
         }
      }
   //   cout<<min<<" "<<index<<endl;
      sum = sum + minn;
      for(i=n-2;i>=0;i--){
         minn = 10000000;
      //   cout<<"index = "<<index<<endl;
         j=0;
         while(j<3){
            if(j == index){
               j++;
            }
            else if(j!=index){
               if(m[i][j] < minn){
                  minn = m[i][j];
                  index1 = j;
               }
               j++;

            }
         }
         index = index1;
   //      cout<<min<<" "<<index<<endl;
         sum = sum + minn;
         
      }
      }
      cout<<sum<<endl;
   }
}





