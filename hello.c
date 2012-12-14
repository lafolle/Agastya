#include <stdio.h>

char* foo()
{
  return "k";
}



int main()
{
  int k;


  int A[23];

  int i=1;


  do{
    if(i*i%2==0){
      A[i]=i*i;
    }
    else{
      A[i]=i*i*i;
    }

    switch(A[i]){
    case 16:
      printf("A[i] is 16\n");
      break;
    case 27:
      printf("A[i] is 27\n");
      break;
    default:
	printf("A[i] is neither 27 nor 16\n");
    }
    
    i++;
  }while(i<23);


  return 0;
}
