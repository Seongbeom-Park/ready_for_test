// 3215 : 최단 경로 1
// https://codeup.kr/problem.php?id=3215
#include <stdio.h>
#include <stdlib.h>

int dfs(int curr_id, int graph[50][50], int memo[50], int distance, int n, int end_id) { // DFS는 재귀로 짜는게 쉬움
	if (memo[curr_id] != -1 && distance > memo[curr_id]) return 0; // 조건 안맞는 경우 빠르게 종료 (early termination)
	memo[curr_id] = distance; // 방문한 노드는 표시해두기
	if (curr_id == end_id) return 0; // 조건 안맞는 경우 빠르게 종료 (early termination)
	int i;
	for (i=0; i<n; i++) {
		if (graph[curr_id][i] == -1) continue;
		dfs(i, graph, memo, distance + graph[curr_id][i], n, end_id); // DFS 주요 코드
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int graph[50][50]; // vertex(또는 node)가 많지 않은 경우 2D 배열로 관계를 표현 (시험 특성 상 그래프 표현 방식은 이 방법만 알면 충분할 듯)
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			graph[i][j] = -1;
		}
	}

	for (i=0; i<m; i++) {
		char from_name, to_name; // edge의 양 끝단은 from, to로 표현하면 보기 좋음
		int distance;
		scanf(" %c %c %d", &from_name, &to_name, &distance);

		int from_id = from_name - 'A'; // 입력과 코드는 최대한 빨리 분리하기
		int to_id = to_name - 'A';
		graph[from_id][to_id] = distance;
		graph[to_id][from_id] = distance;
	}

	char start_name, end_name;
	scanf(" %c %c", &start_name, &end_name);

	int start_id = start_name - 'A';
	int end_id = end_name - 'A';

	int memo[50]; // DFS 필수 코드. 방문한 노드 표시 용. 문제에 맞게 표시 방식을 변경하기
	for (i=0; i<n; i++) {
		memo[i] = -1;
	}
	
	dfs(start_id, graph, memo, 0, n, end_id);
	printf("%d", memo[end_id]);

	return 0;
}
