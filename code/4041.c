#include <stdio.h>
#include <stdlib.h>

#define MAX 100
char n[MAX];

int main() {
	scanf("%s", n);
	
	// 숫자 뒤집기
	int i;
	int len = 0;
	for (i=0; n[i] != 0; i++) {
		len ++;
	}
	int sum = 0;
	int first_flag = 1;
	for (i=0; i<len; i++) {
		int index = len - i - 1;
		if (first_flag && n[index] == '0') continue;
		first_flag = 0;
		printf("%c", n[index]); // 뒤집어서 바로 출력 
		sum += n[index] - '0';
	}
	printf("\n%d", sum); // 합 출력
	
	return 0; 
}

/*
n	22\0
i	012
len	3

*/
