#include <stdio.h>

// Explicação do exercicio: https://www.hackerrank.com/contests/monitoria-ip/challenges/functions-in-c/problem

int max_of_four(int a, int b, int c, int d){
    if (a > b) {
        if (a > c)
            return (a > d) ? a : d;
        else
            return (c > d) ? c : d;
    }
    else {
        if (b > c)
            return (b > d) ? b :  d;
        else
            return (c > d) ? c : d;
    }
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}