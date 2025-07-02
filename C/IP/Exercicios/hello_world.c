#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Explicação do exercício: https://www.hackerrank.com/contests/monitoria-ip/challenges/hello-world-c

int main()
{
    char s[100];
    scanf("%[^\n]%*c", &s);
    printf("Hello, World!\n%s", s);
    return 0;
}