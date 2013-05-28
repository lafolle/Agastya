#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

/* code because of bad problem description
void allcomb(int i, int s)
{
  if(i==10){
    if(abs(100-s)<abs(100-sum))
      sum = s;
    else if(abs(100-s)==abs(100-sum))
      sum = max(sum, s);
    return;
  }

  allcomb(i+1, s); // ith element not taken
  allcomb(i+1, s+v[i]); // ith element taken
}
*/

int main()
{
  int i,j,k,t,s=0,sum;
  for(i=0;i<10;i++){
    scanf("%d", &k);
    v.push_back(k);
    s+=k;
  }

  sum=0;
  for(i=0;i<10;i++){
    sum+=v[i];
    if(sum<100) s=sum;
    else if(sum==100){
      s=sum;
      break;
    }
    else{
      if(abs(sum-100)==abs(s-100) and sum>s)
	s=sum;
      break;
    }
  }

  printf("%d\n", s);
}

// no way!

// python got AC. see GLJIVE.py
