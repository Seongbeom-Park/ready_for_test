// 1418 : t를 찾아라
// https://codeup.kr/problem.php?id=1418
#include <stdio.h>
#include <stdlib.h>

int main() {
	char text[5000];
	scanf("%s", text);

	int i;
	for (i = 0; i < 5000; i++) {
		if (text[i] == 't') printf("%d ", i + 1);
		if (text[i] == 0) break;
	}
	return 0;
}
