#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *((int*)a) < (*(int*)b);
}

int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	int c;
	scanf("%d", &c);
	int d[200];
	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &d[i]);
	}

    // sort
	qsort(d, n, sizeof(int), compare);

    // greedy
	int price = a, cal = c;
	for (i=0; i<n; i++) {
		if ((cal+d[i])/(price+b) >= cal/price) {
			price += b;
			cal += d[i];
		} else break;
	}
	printf("%d", cal/price);

	return 0;
}
