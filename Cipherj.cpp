#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
  int number,k,s,count1;
  while(scanf("%d",&number))
    {
      if(number==0)
	break;
      int keys[number];
      int keycom[10000][number];
      for(int i=0;i<number;i++)
	{
	  scanf("%d",&keys[i]);
	  keycom[1][i]=keys[i]-1;
	}
      int i=2;
      while(1&&number!=1)
	{
	  count1=0;
	  for(int j=0;j<number;j++)
	    {
	      s=keys[keycom[i-1][j]]-1;
	      keycom[i][j]=s;
	      if(keycom[1][j]==s)
		count1++;
	    }
	  if(count1==number)
	    {
	      count1=i;
	      count1--;
	      break;
	    }

	  i++;
	}

      while(1)
	{

	  char sent[number+1],sent1[number+1],a;
	  scanf("%d",&k);
	  if(k==0)
	    break;
	  getchar();
	  int count=0;
	  while((a=getchar())!='\n')
	    {
	      sent1[count]=a;
	      sent[count]=a;
	      count++;
	    }
	  for(int i=0;i<number-count;i++)
	    {
	      sent[length+i]=' ';
	      sent1[length+i]=' ';
	    }
	  sent[number]='\0';
	  sent1[number]='\0';
	  int num=k%count1;
	  if(num==0)
	    num=count1;
	  for(int i=0;i<strlen(sent);i++)
	    {
	      sent1[keycom[num][i]]=sent[i];
	    }
	  printf("%s\n",sent1);
	}
      printf("\n");

    }

}
