#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Explicacao do exercicio: https://www.hackerrank.com/contests/monitoria-ip/challenges/printing-tokens-/problem

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    char *token = strtok(s, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    free(s);
    return 0;
}