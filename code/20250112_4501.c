#include <stdio.h>
#include <stdlib.h>

int main() {
	int i=0;
	int m1=-1, m2=-1;
	for (i=0; i<7; i++) {
		int h;
		scanf("%d", &h);
		if (h > m1) {
			m2 = m1;
			m1 = h;
		} else if (h > m2) {
			m2 = h;
		}
	}
	printf("%d\n%d", m1, m2);
	return 0;
}
