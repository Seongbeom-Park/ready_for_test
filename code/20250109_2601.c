// 2601 : 피보나치 수열
// https://codeup.kr/problem.php?id=2601
#include <stdio.h>
#include <stdlib.h>

int fib(int index, int memo[500]) {
	if (index == 0) return 1;
	if (index == 1) return 1;
	return memo[index-1] + memo[index-2];
}

int main() {
	int n;
	scanf("%d", &n);

	int memo[500], i;
	for (i=0; i<n; i++) {
		memo[i] = fib(i, memo);
	}
	printf("%d", memo[n-1]);
	return 0;
}
