#include <iostream>
#include <stdio.h>

using namespace std;

static int M[1236][5679];

int main(){
   char c; int x,y,z,i,j,cont,aux; 
   
   M[0][0] = 0;      
   for(i=1;i<=1234;i++) M[i][0] = i;         
   for(j=1;j<=5678;j++) M[0][j] = j;         
   
   cont = 1;
   for(i=1;i<=1234;i++)
      for(j=1;j<=5678;j++){
            M[i][j] = cont;
            cont++;
         }
   while(cin>>c){
      switch(c){
         case 'R': 
               cin>>x>>y;      
               M[x][0] = y;   M[y][0] = x;
         break;
         case 'C': 
               cin>>x>>y;
               M[0][x] = y;   M[0][y] = x;
         break;
         case 'Q': 
               cin>>x>>y;
               for(i=1234;i>0;i--) if(M[i][0]==x) break;
               for(j=5678;j>0;j--) if(M[0][j]==y) break;
               printf("%d\n",M[i][j]);
         break;
         case 'W': 
               cin>>z;
               i = (int)(z/5678) + 1;
               j = z%5678;
               if(j==0){ i--; j = 5678; } 
               printf("%d %d\n",M[i][0],M[0][j]);
         break;
      }
   }
   return 0;
}

// jdk
