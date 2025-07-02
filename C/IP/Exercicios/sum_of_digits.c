#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Explicação do exercício: https://www.hackerrank.com/contests/monitoria-ip/challenges/sum-of-digits-of-a-five-digit-number/problem

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i=1; i <= 5; i++){
        sum += n%10;
        n = n/10;
    }
    printf("%d", sum);
    return 0;
}