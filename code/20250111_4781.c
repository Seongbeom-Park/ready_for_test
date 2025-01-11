// 4781 : 토마토(고등)
// https://codeup.kr/problem.php?id=4781

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	int info[1010][1010];	
	int i, j;
	for (i=0; i<1010; i++) {
		for(j=0; j<1010;j++) {
			info[j][i] = -1;
		}
	}
	
	int curr_x[1010 * 1010], curr_y[1010 * 1010], curr_len=0;
	int remain = 0;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			int x = j+1;
			int y = i+1;

			int status;
			scanf("%d", &status);

			info[x][y] = status;
			if (status == 1) {
				curr_x[curr_len] = x;
				curr_y[curr_len] = y;
				curr_len++;
			} else if (status == 0) {
				remain++;
			}
		}
	}

	int days=0;
	int next_x[1010 * 1010], next_y[1010 * 1010], next_len=0;
	while(curr_len > 0) {
		next_len = 0;

		int k;
		for (k=0; k<curr_len; k++) {
			int x = curr_x[k];
			int y = curr_y[k];
			if (info[x-1][y] == 0) {
				info[x-1][y] = 1;
				next_x[next_len] = x-1;
				next_y[next_len] = y;
				next_len++;
			}
			if (info[x+1][y] == 0) {
				info[x+1][y] = 1;
				next_x[next_len] = x+1;
				next_y[next_len] = y;
				next_len++;
			}
			if (info[x][y-1] == 0) {
				info[x][y-1] = 1;
				next_x[next_len] = x;
				next_y[next_len] = y-1;
				next_len++;
			}
			if (info[x][y+1] == 0) {
				info[x][y+1] = 1;
				next_x[next_len] = x;
				next_y[next_len] = y+1;
				next_len++;
			}
		}
		remain -= next_len;
		for (k=0; k<next_len; k++) {
			curr_x[k] = next_x[k];
			curr_y[k] = next_y[k];
		}
		curr_len = next_len;
		days++;
	}

	if (remain == 0) printf("%d", days - 1);
	else printf("-1");

	return 0;
}
