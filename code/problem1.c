#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	// 수열
	printf("%d", n * (n-1) / 2);
	return 0;
}

/*

n	answer
0	0
1	0
2	1
3	3
4	6
5	10
n	n * (n-1) / 2

*/
