// 3007 : 기억력 테스트 7
// https://codeup.kr/problem.php?id=3007
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	int i;
	int memo[10000000];
	memo[0] = 0;
	for (i=0; i<n; i++) {
		int value;
		scanf("%d", &value);

		memo[i+1] = memo[i] + value;
	}

	int j;
	for (j=0; j<m; j++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);

		int answer = memo[b] - memo[a-1];
		printf("%d\n", answer);
	}

	return 0;
}
