//#define DEBUG
#ifdef DEBUG
#define log(msg...) printf(msg)
#else
#define log(msg...)
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int repeat[MAX], repeat_len;

int print_code_to_str(int code) {
	if (code == 1) printf("도 ");
	else if (code == 10) printf("레 ");
	else if (code == 11) printf("미 ");
	else if (code == 100) printf("파 ");
	else if (code == 101) printf("솔 ");
}

int main() {
	int n;
	scanf("%d", &n);
	
	int repeat_flag = 0;
	int i;
	for (i=0; i<n; i++) {
		int code;
		scanf("%d", &code);
		log("%d\n", code);

		// 도돌이표 플레그 셋
		if (code == 0) repeat_flag = 1;
		// 도돌이표 끝났을 때 큐 2번 출력
		if (code == 111) {
			repeat_flag = 0;
			int j;
			for (j=0; j<repeat_len; j++) {
				print_code_to_str(repeat[j]);
			}
			for (j=0; j<repeat_len; j++) {
				print_code_to_str(repeat[j]);
			}
		}
		// 도돌이표 중에는 저장
		if (repeat_flag) repeat[repeat_len++] = code;
		// 이외에는 출력
		else print_code_to_str(code);
	}
	return 0;
}
