#include <stdio.h>
#include <stdlib.h>

int main() {
	int k;
	scanf("%d", &k);

	int stack[150000], stack_len=0;
	int i;
	for (i=0; i<k; i++) {
		int n;
		scanf("%d", &n);
		if (n != 0) stack[stack_len++] = n;
		else if (stack_len != 0) stack_len--;
	}
	int sum = 0;
	for (i=0; i<stack_len; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
	return 0;
}
