#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[60000];
	scanf("%s", str);

	char stack[30000], stack_len = 0;
	int flag = 1;
	int i;
	for (i=0; str[i] != 0; i++) {
		if (str[i] == '(') {
			stack[stack_len++] = str[i];
		} else {
			if (stack_len == 0) {
				flag = 0;
				break;
			}
			stack_len--;
		}
	}
	if (stack_len > 0) flag = 0;
	printf("%s", flag?"good":"bad");
	return 0;
}
