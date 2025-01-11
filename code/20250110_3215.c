// 3215 : 최단 경로 1
// https://codeup.kr/problem.php?id=3215
#include <stdio.h>
#include <stdlib.h>

int dfs(int curr_id, int graph[50][50], int memo[50], int distance, int n, int end_id) {
	if (memo[curr_id] != -1 && distance > memo[curr_id]) return 0;
	memo[curr_id] = distance;
	if (curr_id == end_id) return 0;
	int i;
	for (i=0; i<n; i++) {
		if (graph[curr_id][i] == -1) continue;
		dfs(i, graph, memo, distance + graph[curr_id][i], n, end_id);
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int graph[50][50];
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			graph[i][j] = -1;
		}
	}

	for (i=0; i<m; i++) {

		char from_name, to_name;
		int distance;
		scanf(" %c %c %d", &from_name, &to_name, &distance);

		int from_id = from_name - 'A';
		int to_id = to_name - 'A';
		graph[from_id][to_id] = distance;
		graph[to_id][from_id] = distance;
	}

	char start_name, end_name;
	scanf(" %c %c", &start_name, &end_name);

	int start_id = start_name - 'A';
	int end_id = end_name - 'A';

	int memo[50];
	for (i=0; i<n; i++) {
		memo[i] = -1;
	}
	
	dfs(start_id, graph, memo, 0, n, end_id);
	printf("%d", memo[end_id]);

	return 0;
}
