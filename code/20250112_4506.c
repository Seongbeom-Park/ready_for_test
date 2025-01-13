#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a = n, b = m;
	while (a != b) {
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}
		a -= b;
	}
	printf("%d\n", a);
	printf("%d", (n/a)*m);
	return 0;
}
