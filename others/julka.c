#include<stdio.h>
#include<string.h>
int add( int [],int [], int , int []);
int divby2(int [], int [], int);
int sub(int [], int [], int, int );

int add(int iar[],int idiff[], int l1, int inar[])
{
  int i,k,tmplen;
  for(i=0;i<l1;i++)
    {
      k=iar[203-i] + idiff[203-i];
      inar[203-i]=k%10;
      if(k>9)
	iar[203-i-1]+=1;
    }
  tmplen=l1;
  if(k>=10)
    {
      inar[203-l1]=1;
      tmplen=l1+1;
    }
  return tmplen;
}

int divby2(int ia[],int inar[], int len)
{
  int tmp,i,k;
  for(i=0,k=0;i<len;i++,k++)
    {
      if(inar[i]==0)
	{
	  ia[k]=0;
	  continue;
	}
      else if(inar[i]==1)
	{
	  tmp=inar[i]*10 + inar[i+1];
	  if(i==0)
	    {
	      ia[k]=tmp/2;
	      inar[i+2]+=(tmp%2)*10;
	      i=i+1;
	    }
	  else if (i!=0)
	    {   
	      ia[k]=0;
	      inar[i+1]+=inar[i]*10;
	    }
	}
      else
	{
	  ia[k]=inar[i]/2;
	  inar[i+1]+=(inar[i]%2)*10;
	}
    }
  return 0;
}

int sub(int iar[], int ia[], int j, int l1)
{
  int i,k;
  for(i=l1-1;j>=0;i--,j--)
    {
      if(i==0 && iar[i]==0)
	break;
      if(iar[i]>=ia[j])
	iar[i]=iar[i]-ia[j];
      else
	{
	  iar[i]=iar[i] + 10 -ia[j];
	  k=i-1;
	  while((iar[k]==0) && i>=1)
	    {
	      iar[k]=9;
	      k--;
	    }
	  iar[k]=iar[k]-1;
	}
    }
  return 0;
}

int main()
{

  char ar[101],diff[101];
  int t=10;
  while(t--)
    {
      scanf("%s\n%s",ar,diff);
      int i,j,k,len,b,l1,l2,la;
      int iar[204]={0},ia[204]={0},idiff[204]={0},inar[204]={0};
      b=0;
      l1=strlen(ar);
      l2=strlen(diff);
      //right alignment
      for(i=0;i<l1;i++)
	iar[204-l1+i]=ar[i]-48;
      for(i=0;i<l2;i++)
	idiff[204-l2+i]=diff[i]-48;
      // Addition
      len=add(iar,idiff,l1,inar);
      // Divison by 2...(A+B) + (A-B)..gives 2A
      //left alignment of inar[] for divison
      for(i=0;i<len;i++)
	inar[i]=inar[204-len+i];
      //if Odd..then
      i=inar[len-1];
      if(i%2)
	b=1;
      if(len==1)
	{
	  i=ar[0]-48;
	  j=diff[0]-48;
	  if((i+j)%2==1)
	    {
	      k=i+j-1;
	      k/=2;
	      printf("%d\n%d\n",k,i-k-1);
	    }
	  else
	    {
	      k=(i+j)/2;
	      printf("%d\n%d\n",k,i-k);
	    }
	}
      if(len==1)
	continue;
      //divison by 2
      divby2(ia,inar,len);
      if(inar[204-len]==1)
	len--;
      la=len;

      //printing A
      for(k=0;k<la;k++)
	printf("%d",ia[k]);
      printf("\n");

      //left alignment of ia[]=A+B
      for(i=0;i<l1;i++)
	iar[i]=ar[i]-48;
      ////if Odd

      if(b==1)
	iar[l1-1]--;

      j=la-1;
                 
      sub(iar,ia,j,l1);                 //subtraction-->(A+B)-A=B...iar[]-ia
      //printing B
      i=0;
      if(iar[0]==0)
	i=1;
      for(;i<l1;i++)
	printf("%d",iar[i]);   
      printf("\n");
    }
  return 0;
}
