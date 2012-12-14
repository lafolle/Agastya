#include <vector>
#include <cstdio>
#include <iostream>


using namespace std;

/* Go for random element in range li, ri */
int getpivot(vector<int> &v, int li, int ri)
{
  return li;
}

int partition(vector<int> &v, int li, int ri)
{
  int i,j,k;
  k=li; i=li+1;

  for(j=li+1;j<=ri;j++)
    if(v[j]<v[li]){
      swap(v[j], v[i]);
      i+=1;
    }
  swap(v[i-1], v[li]);
  return i-1;
}

void quicksort(vector<int> &v, int li, int ri)
{
  if(li>ri) return;
  int i,j,k, pivot,p;
  pivot = getpivot(v, li, ri);

  swap(v[pivot], v[li]);
  p = partition(v, li, ri);

  quicksort(v,li, p-1);
  quicksort(v,p+1, ri);
}


int main()
{
  int M[] = {1,8,4,7,4,6,4,7,9}, i;
  int n = sizeof(M)/sizeof(M[0]);  
  vector<int> v(M,M+n);

  quicksort(v, 0, n-1);
  for(i=0;i<n;i++)cout << i << ' ' << v[i] << ' ' << M[i] << endl;

  return 0;
}
