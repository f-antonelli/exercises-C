#include <stdio.h>
#include <stdlib.h>

void valorCharNumerico(char *);

int main()
{
    char frase[] = "aaa";

    valorCharNumerico(frase);
    return 0;
}

void valorCharNumerico(char *l) {
    int res = 0;
    while(*l){
        res += *l;
        l++;
    }

    printf("%d", res);
}
