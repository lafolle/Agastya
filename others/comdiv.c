#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
    if(!b | !a)return 1;
    if(a%b==0)return b;
    return gcd(b,a%b);
    }
int main(){
    int t=0;
    scanf("%d",&t);
    
    while(t--){
               int a,b,i;
               scanf("%d %d",&a,&b);
               if((!a&(b>1))||((a>1)&!b)){
                                  printf("2\n");
                                  break;
                                  }
               int g=gcd(a,b);
               if(g>1){
                       long nd=0;
                       int lim=g;
                       int del=1+(g%2);
                       for(i=1;i<lim;i+=del){
                                              if(g%i==0){
                                             nd+=2;
                                             lim=g/i;
                                             }
                                  }
                      printf("%ld\n",nd);
                      }
               else printf("1\n");
              }
    return 0;
    }
