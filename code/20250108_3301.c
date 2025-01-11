// 3301 : 거스름돈
// https://codeup.kr/problem.php?id=3301
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
	int count = 0;
	int i = 0;
	for (i = 0; i<8; i++) {
		count += n / money[i];
		n = n % money[i];
	}
	printf("%d", count);

	return 0;
}
