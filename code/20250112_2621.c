#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int i;
	int sum = 0;
	for (i=1; i<(n/2 + 1); i++) {
		if (n%i == 0) sum += i;
	}
	printf("%d", sum + n);
	return 0;
}
