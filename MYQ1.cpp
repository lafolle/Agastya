
#include <iostream>
#include <cstdio>

int main()
{
  int t,c,pc;
  long long int seat,r;

  scanf("%d", &t);

  while(t--){
    scanf("%lld", &seat);

    if(seat==1) printf("poor conductor\n");
    else{
      if(!((seat-1)%5)){
	r = (seat-1)/5;
	c = !(r%2) ? 1:5;
      }
      else{
	r = (seat-1)/5;
	r+=1;
	pc = (seat-1)%5;
	c = !(r%2) ? 6-pc : pc;
      }
      char pos,loc=c==1||c==2?'L':'R';
      
      if(c==2||c==3) pos='A';
      else if(c==1||c==5) pos='W';
      else pos='M';

      printf("%lld %c %c\n", r,pos, loc);
    }
  }
  return 0;  
}


// AC
