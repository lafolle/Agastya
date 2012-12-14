#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y)
{
  if(x<y) return x;
  return y;
}

int n,m;
int k, ix, iy;

int vx[1001],vy[1001];


int main()
{
  int i,j,k, steps_cnt=0,p,q,r;

  scanf("%d %d", &n, &m);
  scanf("%d %d", &ix, &iy);
  scanf("%d", &k);

  for(i=0;i<k;i++)scanf("%d %d", &vx[i], &vy[i]);

  for(i=0;i<k;i++){

    if(vx[i]!=0)
      p = vx[i]>0 ? (m-ix)/vx[i] : (1-ix)/vx[i];

    if(vy[i]!=0)
      q = vy[i]>0 ? (n-iy)/vy[i] : (1-iy)/vy[i];

    r=min(p,q);

    steps_cnt+=r;

    ix = ix + r*vx[i];
    iy = iy + r*vy[i];
  }

  printf("%d\n", steps_cnt);

}
