#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[11];
	scanf("%s", str);

	int val = 0;
	int i;
	for (i=0; str[i] != 0; i++) {
		int num = str[i] - '0';
		if (num>3) num -= 1;
		val *= 9;
		val += num;
	}

	printf("%d", val);
	return 0;
}
