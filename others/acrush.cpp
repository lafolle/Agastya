#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define LENGTH(X) ((int)(X.length()))

int A[10000],B[10000],C[10000];
int R[100];

int main()
{
//	freopen("..\\input.txt","r",stdin);
//	freopen("./small.in","r",stdin);
//	freopen("./small.out","w",stdout);
	string s="52360679774997896964091736687313";
	int L=LENGTH(s);
	memset(A,0,sizeof(A));
	for (int i=0;i<LENGTH(s);i++) A[i]=s[L-1-i]-'0';
	memcpy(B,A,sizeof(B));
	int D=L-1;
	for (int n=2;n<=30;n++)
	{
		memset(C,0,sizeof(C));
		for (int i=0;i<10000;i++) if (B[i]!=0)
			for (int j=0;j<10000;j++) if (A[j]!=0)
				C[i+j]+=B[i]*A[j];
		for (int i=0;i<10000;i++)
			if (C[i]>=10)
			{
				C[i+1]+=C[i]/10;
				C[i]%=10;
			}
		memcpy(A,C,sizeof(A));
		R[n]=A[D*n]+A[D*n+1]*10+A[D*n+2]*100;
	}
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
	  int n;
	  scanf("%d",&n);
	  printf("Case #%d: %03d\n",caseId,R[n]);
	}
	return 0;
}

