#include <stdio.h>
#include <stdlib.h>

int memo[1000000];

int compare(const void* a, const void* b) {
	int target = *(int*)a;
	int value = *(int*)b;
	return target-value;
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &memo[i]);
	}

	int m;
	scanf("%d", &m);
	for (i=0; i<m; i++) {
		int target;
		scanf("%d", &target);
		void* result = bsearch(&target, memo, n, sizeof(int), compare);
		if (result == 0) printf("-1 ");
		else printf("%d ", ((int*)result - memo) + 1);
	}
}
