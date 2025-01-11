// 2748 : 덧셈, 뺄셈으로 n만들기
// https://codeup.kr/problem.php?id=2748
#include <stdio.h>
#include <stdlib.h>

void rec(int sum, int *v, int position, int n, int m, int *answer) {
	if (n == position) {
		if (sum == m) *answer += 1;
		return;
	}
	rec(sum + v[position], v, position + 1, n, m, answer);
	rec(sum - v[position], v, position + 1, n, m, answer);
}

int main() {
	int m, n, v[50];
	scanf("%d", &m);
	scanf("%d", &n);
	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}

	int answer = 0;
	rec(0, v, 0, n, m, &answer);
	printf("%d", answer);
}
