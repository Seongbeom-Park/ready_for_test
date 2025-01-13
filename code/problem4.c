#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
int value[MAX];

int main() {
	int n;
	scanf("%d", &n);
	
	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &value[i]);
	}
	
	int curr=0, count=0;
	while (curr < n) {
		curr += value[curr];
		count++;
	}
	printf("%d", count);
	return 0;
}
