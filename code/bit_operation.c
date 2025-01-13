#include <stdio.h>
#include <stdlib.h>

int knapsack[101][10010];

int max(int a, int b) {
	return (a>b) ? a : b;
}

int main() {
	int N, W;
	scanf("%d %d", &N, &W);

	int i;
	for(i=0; i<N; i++) {
		int w, v;
		scanf("%d %d", &w, &v);

		int item_id = i + 1;
		int j;
		for (j=0; j<w; j++) {
			knapsack[item_id][j] = knapsack[item_id-1][j];
		}
		for (j=w; j<=W; j++) {
			knapsack[item_id][j] = max(knapsack[item_id-1][j-w] + v, knapsack[item_id-1][j]);
		}
	}

	int max_value = 0;
	for(i=0; i<=W; i++) {
		max_value = max(max_value, knapsack[N][i]);
	}
	printf("%d", max_value);
	return 0;
}
