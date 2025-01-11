// 1512 : 숫자 등고선
// https://codeup.kr/problem.php?id=1512
#include <stdio.h>
#include <stdlib.h>

int abs(int v) {
	if (v<0) return -v;
	return v;
}

int main() {
	int n, _x, _y;
	scanf("%d %d %d", &n, &_x, &_y);
	int x = _x-1, y=_y-1;

	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			int dist = abs(i-x) + abs(j-y) + 1;
			printf("%d ", dist);
		}
		printf("\n");
	}

	return 0;
}
