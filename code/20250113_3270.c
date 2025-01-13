#include <stdio.h>
#include <stdlib.h>

int graph[1500][1500], alley_name[1500];

int dfs(int curr_id, int min_name, int n) {
	alley_name[curr_id] = min_name;
	int i;
	for(i=0; i<n; i++) {
		if (graph[curr_id][i] == 0) continue;
		if (alley_name[i] != 0) continue;
		dfs(i, min_name, n);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (i=0; i<m; i++) {
		int from_name, to_name;
		scanf(" %d %d", &from_name, &to_name);
		int from_id = from_name - 1;
		int to_id = to_name - 1;
		graph[from_id][to_id] = 1;
		graph[to_id][from_id] = 1;
	}

	for (i=0; i<n; i++) {
		if (alley_name[i] == 0) dfs(i, i+1, n);
	}
	for (i=0; i<n; i++) {
		printf("%d ", alley_name[i]);
	}
}
