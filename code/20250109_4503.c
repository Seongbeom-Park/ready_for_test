// 4503 : 바이러스
// https://codeup.kr/problem.php?id=4503
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPUTER 150
#define CLEAR 0
#define VIRUS 1

int main() {
	int computers, edges;
	scanf("%d %d", &computers, &edges);

	int i, j;
	int connection[MAX_COMPUTER][MAX_COMPUTER], status[MAX_COMPUTER]; // 그래프 표현 방법
	for (i=0; i<computers; i++) {
		status[i] = CLEAR;
		for(j=0; j<computers; j++) {
			connection[i][j] = 0;
		}
	}

	for (i=0; i<edges; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int id_1 = a-1;
		int id_2 = b-1;
		connection[id_1][id_2] = 1; // 양방향 그래프
		connection[id_2][id_1] = 1; // 양방향 그래프
	}

	status[0] = VIRUS;
	int curr_ids[MAX_COMPUTER] = {0}, next_ids[MAX_COMPUTER]; // BFS 중요 코드
	int curr_len = 1, next_len; // BFS 중요 코드
	int count = 0;

	while(curr_len > 0) { // BFS 중요 코드
		next_len = 0; // BFS 중요 코드
		for (i=0; i<curr_len; i++) {
			int curr_comp_id = curr_ids[i];
			for (j=0; j<computers; j++) {
				if (connection[curr_comp_id][j] == 1) {
					int next_comp_id = j;
					if (status[next_comp_id] == CLEAR) {
						next_ids[next_len++] = next_comp_id;
						status[next_comp_id] = VIRUS;
						count++;
					}
				}
			}
		}

		for (i=0; i<next_len; i++) {
			curr_ids[i] = next_ids[i]; // BFS 중요 코드
		}
		curr_len = next_len; // BFS 중요 코드
	}

	printf("%d", count);
	return 0;
}
