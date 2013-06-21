#include <iomanip>
#include <cstdio>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void merge(int lower, int mid, int upper, vi &v)
{
  int i,j,k,p;
  vi m(upper-lower+1);
  for(k=0,i=lower,j=mid+1;i<=mid && j<=upper;){
    if(v[i]<v[j]){
      m[k++]=v[i];
      i++;
    }
    if(v[j]<=v[i]){
      m[k++]=v[j];
      j++;
    }
  }
  if(i==mid+1 and j==upper+1) return;
  if(i<=mid) for(p=i;p<=mid;p++) m[k++]=v[p];
  if(j<=upper) for(p=j;p<=upper;p++) m[k++]=v[p];
  for(j=0,i=lower;j<k;)v[i++]=m[j++];
}

void mergesort(int lower, int upper, vi &v,int depth)
{
  if(lower<upper){
    int mid = (lower+upper)>>1;
    mergesort(lower, mid, v,depth+1);
    mergesort(mid+1, upper, v, depth+1);
    merge(lower, mid, upper, v);
  }
}


int main()
{
  int n,i;
  int A[] = {3,5,1,6,7,9,8};
  n = sizeof(A)/sizeof(A[0]);
  vi v(A, A+n);
  mergesort(0, n-1, v,0);
  for(i=0;i<n;i++)cout<<v[i]<<endl;
}
