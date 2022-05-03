#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define TAM 5

void mostrarMatriz(int mat[][TAM]);
void sumElemTSupDP(int mat[][TAM], int ord);
void sumElemTSupDS(int mat[][TAM], int ord);
void sumElemTSupConDP(int mat[][TAM], int ord);
void sumElemTSupConDS(int mat[][TAM], int ord);
void sumElemTInfDP(int mat[][TAM], int ord);
void sumElemTInfDS(int mat[][TAM], int ord);
void sumElemTInfConDP(int mat[][TAM], int ord);
void sumElemTInfConDS(int mat[][TAM], int ord);

#endif // FUNCTIONS_H_INCLUDED
