#include <stdio.h>
#include <stdlib.h>

struct Data{
	int value;
	int index;
	int position;
};

int compare(const void *a, const void *b) {
	return (*(struct Data*)a).value > (*(struct Data*)b).value;
}

int r_compare(const void *a, const void *b) {
	return (*(struct Data*)a).index > (*(struct Data*)b).index;
}


int main() {
	int n;
	scanf("%d", &n);

	struct Data data[51000];
	int i;
	for (i=0; i<n; i++) {
		int value;
		scanf("%d", &value);
		data[i].value = value;
		data[i].index = i;
	}
	qsort(data, n, sizeof(struct Data), compare);

	for (i=0; i<n; i++) {
		data[i].position = i;
	}
	qsort(data, n, sizeof(struct Data), r_compare);
	for (i=0; i<n; i++) {
		printf("%d ", data[i].position);
	}
}
