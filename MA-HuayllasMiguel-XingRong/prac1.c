/* COGNOM1: HUAYLLAS COGNOM2: CHOQUE NOM: MIGUEL VICTOR DNI / NIUB : 17510710 */
/* COGNOM1: XING COGNOM2 : NOM: RONG DNI / NIUB : */

#include "pracFuns.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    double **A, *b, *x;
    int n;
    
    printf("Dimensión de la matriz A: ");
    scanf_s("%d", &n);
    
    A = (double **) malloc (n * sizeof(double*));
    b = (double *) malloc (n * sizeof(double));
    x = (double *) malloc (n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc (n * sizeof(double));
    }
    
    printf("\nMatriz A\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf_s("%le", &A[i][j]);
        }
    }
    
    printf("\nVector b\n");
    
    for (int i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf_s("%le", &b[i]);
    }
    
    return 0;
}