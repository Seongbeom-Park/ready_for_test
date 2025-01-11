// 1295 : 알파벳 대소문자 변환
// https://codeup.kr/problem.php?id=1295
#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[2000];
	scanf("%s", str);
	int i;
	for (i=0; str[i] != '\0'; i++) { // for문을 이용한 문자열 iteration
		if (str[i] >= 'a' && str[i] <= 'z') str[i] += 'A' - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
	}
	printf("%s", str);
	return 0;
}
