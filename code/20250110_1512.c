// 1512 : 숫자 등고선
// https://codeup.kr/problem.php?id=1512
#include <stdio.h>
#include <stdlib.h>

int abs(int v) { // 간단한 수식 함수는 위에 작성하기
	if (v<0) return -v;
	return v;
}

int main() {
	int n, _x, _y; // 변수 이름에 아래 밑줄 넣을 때는 임시 변수에 넣는게 좋음
	scanf("%d %d %d", &n, &_x, &_y);
	int x = _x-1, y=_y-1;

	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			int dist = abs(i-x) + abs(j-y) + 1; // 맨해튼 거리 계산 방법: x끼리 빼고, y끼리 빼고, 각각 절대값 씌워서 더하기
			printf("%d ", dist);
		}
		printf("\n");
	}

	return 0;
}
