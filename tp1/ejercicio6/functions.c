double potencia(float base, int exponente) {
    int i;
    double res = base;

    for (i = 1; i < exponente; i++)
        res *= base;

    return res;
}

double factorial(int num) {
    int i, res = 1;

    for(i = num; i > 1; i--)
        res *= i;

    return res;
}

double obtenerSeno(float num, float tol){
    int i = 1, aux = 3;
    double res = num;

    do {
        (i % 2 == 0)
            ?   (res += potencia(num, aux) / factorial(aux))
            :   (res -= potencia(num, aux) / factorial(aux));
        aux += 2;
        i++;
    } while ((potencia(num, aux) / factorial(aux)) <= tol);

    return res;
}
