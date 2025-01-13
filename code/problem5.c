#include <stdio.h>
#include <stdlib.h>

int main() {
	int curr, target;
	scanf("%d %d", &curr, &target);

	// 그리디
	int count = 0;
	int diff = target - curr;

	count += diff/7;
	diff = diff%7;

	count += diff/3;
	diff = diff%3;
	
	count += diff;

	printf("%d", count);
	return 0;
}

/*
diff	cnt		how
0		0		
1				1
2				11
3				3
4				31
5				311
6				71
7				7
8				71
9				711
10				73
*/
