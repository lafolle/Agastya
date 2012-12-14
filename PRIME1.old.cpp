#include <iostream>
#include <vector>
#include <math.h>

#define NO_PRIME 0
#define YES_PRIME 1

using namespace std;

vector<bool> primes(100000, YES_PRIME), lim_primes(32000, YES_PRIME);
long long int m,n;
	
void setup()
{
	int j, p, i, lim, c=0;
	lim_primes[0] = NO_PRIME;
	lim_primes[1] = NO_PRIME;
	lim = sqrt(32000);
	for (j=2; j <= lim; j++){
		if (lim_primes[j]){
			for (i=2; ;i++){
				p = j*i;
				if (p <= 31999){
					lim_primes[p] = NO_PRIME;
				}
				else break;
			}
		}
	}
	//for (j=0; j<=31999; j++) if(lim_primes[j]) cout << j << endl;
}
void undo(int j)
{
	 int k;
	 for(k=0; k<=j; k++) if(!primes[k]) primes[k] = YES_PRIME;
}

void display(int flag)
{
	long int i;
	if(flag){
		for (i=m; i<32000; i++) if(lim_primes[i]) cout << i << endl;
		for (i=0; i<=n-32000; i++) if(primes[i]) cout << 32000+i << endl;
	}
	else for (i=0; i<=n-m; i++) if(primes[i]) cout << m+i << endl;
}

int main()
{	
	bool flag;
	int k,i=0, c=0, t, offset, limit, r;
	long long int p, lower_limit;
	setup();

	for (cin >> t; i<t; i++){
		cin >> m;
		cin >> n;
		if (n <= 31999){
			for(k=m; k <=n; k++) if(lim_primes[k]) cout << k << endl;
			continue;
		}
		limit = sqrt(n);
		if (m <= 32000){
			lower_limit = 32000;
			flag = 1;
		}
		else{
			lower_limit = m;
			flag = 0;
		}
		for (k=2; k < limit; k++){
			if (lim_primes[k]){
				offset = lower_limit/k;
				p = k*offset;
				if(p < lower_limit) offset+=1;
				for (c=offset; ;c++){
					p = k*c;
					r = p-lower_limit;
					if (p <= n) primes[r] = NO_PRIME;
					else break;
				}
			}
		}
		display(flag);
		undo(n-lower_limit);
	}
	return 0;
}



