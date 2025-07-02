#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Explicação do exercício: https://www.hackerrank.com/contests/monitoria-ip/challenges/sum-numbers-c

int main(){
    int int1, int2;
    float float1, float2;
    scanf("%d %d", &int1, &int2);
    scanf("%f %f", &float1, &float2);
    printf("%d %d\n", int1+int2, int1-int2);
    printf("%.1f %.1f", float1+float2, float1-float2);
    return 0;
}