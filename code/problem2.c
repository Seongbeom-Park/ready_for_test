#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

char number[MAX];

int max(int a, int b) {
	if (a>b) return a;
	return b;
}

int main() {
	int n;
	scanf("%d", &n);
	
	int answer = 0;
	int i;
	for (i=0; i<n; i++) {
		scanf("%s", number);
		int value = 0;
		// 뒤집었을 때 값 계산
		int j;
		for (j=0; number[j] != '\0'; j++) {
			int v = number[j] - '0';
			int k;
			for (k=0; k<j; k++) {
				v *= 10;
			}
			value += v;
		}
		// 최대 여부 판단
		answer = max(answer, value);
	}
	printf("%d", answer);
	
	return 0;
}
