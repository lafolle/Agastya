/*
	Functions related to computing and printing Longest Common Subsequence,
	of given 2 strings with different space contraints, using Dynamic
	Programming. 
	
	Lower you go, more abstract you get.
	
	Also computes Longest Palindrome Subsequece of a given string. (CLRS : 15-2)

TODO:

1. Print all LCS of given strings.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define STRLEN 1001
#define DEBUG 0
#define false 0
#define true 1
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

void swap(char *a, char *b)
{
	char tmp = *a;
	*a=*b;*b=tmp;
}

typedef struct {
	int i;
	int j;
} pair;

pair stack[1000000];

int n,m;
char a[STRLEN], b[STRLEN];
int dp[STRLEN][STRLEN]={-1}, tmp[STRLEN][STRLEN];


#if DEBUG == 1
void print_table()
{
	int i,j;
	for(i=0;i<=m;i++, printf("\n"))for(j=0;j<=n;j++)printf("%d ", dp[i][j]);printf("\n");
	for(i=0;i<=m;i++, printf("\n"))for(j=0;j<=n;j++)printf("%d ", tmp[i][j]);
}
#endif

// Reverse string
void reverse_string(char *s)
{
	int len = strlen(s);
	int f=0, b=len-1;
	while(f<=b) swap(&s[f++], &s[b--]);
}



// print all lsc (This will be pretty awesome!!!)
/*
void print_all_lcs(int lcslen)
{
	char *lcs = (char *)malloc(lcslen+1);lcs[lcslen]='\0';
	int i,j,k,c=lcslen;
	pair p; int top=0;
	p.i=m;p.j=n;stack[top]=p;
	
	while(top>=0){
		p = stack[top--];
		i=p.i; j=p.j;
		if(a[i-1]!=b[j-1] && dp[i-1][j]==dp[i][j-1]){
			p.i=i-1;p.j=j;stack[++top]=p;
			p.i=i;p.j=j-1;stack[++top]=p;
		}
		else if(a[i-1]!=b[j-1] && dp[i-1][j]!=dp[i][j-1]){
			if(dp[i][j]==dp[i-1][j]
				p.i=i-1;p.j=j;stack[++top]=p;
			else p.i=i;p.j=j-1;stack[++top]=p;
		}
		else {
			p.i=i-1;p.j=j-1;stack[++top]=p;
			lcs[c--]=a[i-1];
		}
		
		if(c<0){
		printf("%s\n", lcs);
	}
}
*/


// print lcs : takes operations equal to length of the LCS
void print_any_lcs(int lcs_len)
{
	int i,j,k,c=lcs_len-1;
	i=m; j=n;
	char *ans = (char *)malloc(lcs_len+1);
	ans[lcs_len]='\0';
	
	while(i>0 && j>0){
		if(tmp[i][j]==0){ans[c--]=a[i-1];--i;--j;}
		else if(tmp[i][j]==1)i-=1;
		else j-=1;
	}
	printf("\"%s\"\n", ans);
}


/* Compute LCS of 2 strings, with memory efficiency */
int compute_lcs_less_mem(const char *p, const char *q)
{
	int i,j,k;
	m = strlen(p); n = strlen(q);
	int *b = (int *)malloc(min(m,n)*sizeof(int)), *d = (int *)malloc(min(m,n)*sizeof(int));
	short f=1; // start with b
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(!i || !j)continue;
			if(f){
				if(p[i-1]==q[j-1]) d[j]=b[j-1]+1;
				else d[j]=max(d[j-1], b[j]);	
			}
			else{
				if(p[i-1]==q[j-1]) b[j]=d[j-1]+1;
				else b[j]=max(b[j-1],d[j]);
			}
		}
		f=f?0:1; // toggle arrays
	}
	
	return f?b[n]:d[n];
}


// Return length of LCS and populate tmp and dp
int compute_lcs(const char *p, const char *q)
{
	int i,j,k;
	m = strlen(p); n = strlen(q);
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(!i || !j){dp[i][j]=0;continue;}
			if(p[i-1]==q[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				tmp[i][j]=0;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
					tmp[i][j] = 1;
				}
				else{
					dp[i][j] = dp[i][j-1];
					tmp[i][j] = 2;
				}
			}
		}
	}

	return dp[m][n];
}

// Compute Longest Palindrome Subsequence
int compute_longest_palindrome_subsequence(char *p)
{
	char *q = (char *)malloc(strlen(q));
	strcpy(q,p);
	reverse_string(q);
	m = strlen(p); n = strlen(q);
	return compute_lcs(p,q);
}


int main()
{
	int i,j,k;
	scanf("%s", a);
	int m = compute_longest_palindrome_subsequence(a);

	printf("%d\n", m);
	print_any_lcs(m);
	#if DEBUG == 1
	print_table();
	#endif
	return 0;
}
