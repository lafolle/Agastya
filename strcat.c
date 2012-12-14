#include <string.h>
#include <stdio.h>

int main()
{
	char fn[200]="karan";
	char *ln=" chaudhary";
	strcat(fn, ln);
	printf("%s\n", fn);
	return 0;
}
