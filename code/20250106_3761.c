// 3761 : 평면 분할하기
// https://codeup.kr/problem.php?id=3761
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (1 + (n%137)*((n+1)%137)/2) % 137);
    return 0;
}
