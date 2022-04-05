void divisores (int num) {
    int arr[num];
    int i = 0, aux = num;

    while (aux > 1) {
        aux--;
        if (num % aux == 0){
            arr[i] = aux;
            i++;
        }
    }

    clasificacion(arr, i, num);
}

void clasificacion(int arr[], int cant, int num){
    int j, suma = 0;

    for (j = 0; j < cant; j++)
        suma += arr[j];


    if (suma == num)
        printf("El numero es PERFECTO");
    else if (suma < num)
        printf("El numero es DEFICIENTE");
    else
        printf("El numero es ABUNDANTE");
}

