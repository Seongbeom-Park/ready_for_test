// 4024 : 호수의 수 구하기
// https://codeup.kr/problem.php?id=4024
#include <stdio.h>
#include <stdlib.h>

#define LIMW 1000
#define LIMH 1000

/*
int is_lake(int x, int y, int lake[LIMH][LIMW], int h, int w) {
	if (x < 0 || x >= h) return 0;
	if (y < 0 || y >= w) return 0;
 	return lake[x][y];
}
*/
int put_id(int x, int y, int id, int lake[LIMH][LIMW], int h, int w) { // DFS 중요 코드
	if (x < 0 || x >= h) return 0; // 범위 벗어날 경우 빠른 종료 (early termination)
	if (y < 0 || y >= w) return 0;
	
	lake[x][y] = id;
	if (lake[x-1][y-1] == 0) put_id(x-1, y-1, id, lake, h, w); // if (is_lake(x, y, lake, h, w) == 0) put_id(x-1, y-1, id, lake, h, w);
	if (lake[x-1][y] == 0) put_id(x-1, y, id, lake, h, w);
	if (lake[x-1][y+1] == 0) put_id(x-1, y+1, id, lake, h, w);
	if (lake[x][y-1] == 0) put_id(x, y-1, id, lake, h, w);
	if (lake[x][y+1] == 0) put_id(x, y+1, id, lake, h, w);
	if (lake[x+1][y-1] == 0) put_id(x+1, y-1, id, lake, h, w);
	if (lake[x+1][y] == 0) put_id(x+1, y, id, lake, h, w);
	if (lake[x+1][y+1] == 0) put_id(x+1, y+1, id, lake, h, w);
}

int main() {
	int w, h;
	scanf("%d %d", &w, &h);

	int i, j, lake[LIMH][LIMW];
	for (i=0; i<LIMH; i++) {
		for (j=0; j<LIMW; j++) {
			lake[i][j] = -1;
		}
	}
	
	for (i=0; i<h; i++) {
		for (j=0; j<w; j++) {
			char status;
			scanf(" %c", &status);
			if (status == 'L') lake[i][j] = 0;
			if (status == '.') lake[i][j] = -1;
		}
	}
	
	int lake_id = 0;
	for (i=0; i<h; i++) {
		for (j=0; j<w; j++) {
			if (lake[i][j] == 0) {
				lake_id++;
				put_id(i, j, lake_id, lake, h, w);
			}
		}
	}
	printf("%d", lake_id);
	return 0;
}
