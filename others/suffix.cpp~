/*
Alfonso2 Peterssen(mukel)
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 17;

int N, delta;
char text[MAXN];
int sa[MAXN];
int pos[MAXN];
int tmp[MAXN];
int lcp[MAXN];

bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += delta; j += delta;
	if (i < N && j < N) return pos[i] < pos[j];
	return i > j;
}

int main()
{
	scanf( "%s", &text );
	
	// init
	N = strlen(text);
	REP(i, N) sa[i] = i, pos[i] = text[i];
	
	// suffix array
	for (delta = 1;; delta *= 2)
	{
		sort(sa, sa + N, sufCmp);
		REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		REP(i, N) pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
	
	// LCP
	for (int i = 0, k = 0; i < N; i++) if (pos[i] != N - 1)
	{
		int j = sa[ pos[i] + 1 ];
		while (text[j + k] == text[i + k]) k++;
		lcp[pos[i]] = k;
		if (k > 0) k--;
	}

	REP(i, N) printf( "%d %s\n", lcp[i], text + sa[i] );

	return 0;
}
