#include <stdio.h>
#include <stdlib.h>

int memo[100010];

int main() {
	int n;
	scanf("%d", &n);
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	int i;
	for (i=0; i<n; i++) {
		memo[i+3] = (memo[i+2] + memo[i+1] + memo[i])%1000;
	}
	printf("%d", memo[n]);
	return 0;
}
