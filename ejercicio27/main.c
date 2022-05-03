#include <stdio.h>
#include <stdlib.h>

int esPalindromo(char *);

int main()
{
    char frase[] = "reconocer";

    (esPalindromo(frase))
        ? printf("Es palindromo")
        : printf("No es palindromo");

    return 0;
}

int esPalindromo(char *frase){

    char *aux = frase;

    while(*aux)
        aux++;

    aux--;

    while(frase < aux && *frase == *aux){
        frase++;
        aux--;
    }

    return frase >= aux;

}

