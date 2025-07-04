#include <stdio.h>

// Explicacao do exercicio: https://www.hackerrank.com/contests/monitoria-ip/challenges/pointer-in-c/problem

void update(int *a,int *b) {
    int sum = *a + *b;
    int diff = (*a > *b) ? (*a - *b) : (*b - *a);
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}