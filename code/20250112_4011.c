#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[20], answer[20] = "0000/00/00 0";
	scanf("%s", str);
	if (str[7] == '1' || str[7] == '2') {
		answer[0] = '1';
		answer[1] = '9';
	} else {
		answer[0] = '2';
		answer[1] = '0';
	}
	answer[2] = str[0];
	answer[3] = str[1];
	answer[5] = str[2];
	answer[6] = str[3];
	answer[8] = str[4];
	answer[9] = str[5];
	if ((str[7] - '0') % 2 == 1) answer[11] = 'M';
	else answer[11] = 'F';

	printf("%s", answer);
	return 0;
}
