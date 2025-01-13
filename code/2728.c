#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	int r;
	scanf("%d", &r);

	int i, j, memo_curr[2000], memo_next[2000];
	for (i=0; i<r; i++) {
		for (j=0; j<i + 1; j++) {
			int node;
			scanf("%d ", &node);
			if (i == 0 && j == 0) memo_next[0] = node;
			else if (j == 0) memo_next[j] = memo_curr[0] + node;
			else memo_next[j] = max(memo_curr[j-1], memo_curr[j]) + node;
		}
		for (j=0; j<i + 1; j++) {	
			memo_curr[j] = memo_next[j];
		}
	}
	int max_value = 0;
	for(i=0; i<r; i++) {
		max_value = max(max_value, memo_curr[i]);
	}
	printf("%d", max_value);
	return 0;
}
