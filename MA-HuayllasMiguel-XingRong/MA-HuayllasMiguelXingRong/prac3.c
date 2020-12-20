/* COGNOM1: HUAYLLAS COGNOM2: CHOQUE NOM: MIGUEL VICTOR DNI / NIUB : 17510710 */
/* COGNOM1: XING COGNOM2 : NOM: RONG DNI / NIUB :  20274962*/

#include "pracFuns.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    double **A, *x, *z, *b, *y, tol, total = 0;

    printf("Introducir el numero de ecuaciones: ");
    scanf("%d", &n);

    printf("Introducir la tolerancia: ");
    scanf("%lf", &tol);

    A = (double **) malloc(n * sizeof (double *));
    x = (double *) malloc(n * sizeof (double));
    b = (double *) malloc(n * sizeof (double));
    y = (double *) malloc(n * sizeof (double));

    for (i = 0; i < n; i++) {
        A[i] = (double *) malloc(n * sizeof (double));
    }

    printf("\nMatriz A\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%le", &A[i][j]);
        }
    }

    printf("\nVector b\n");

    for (int i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf("%le", &b[i]);
    }

    gausspivot(A, b, 0.01, n);

    printf("\n Matriz A luego de gauss con pivot\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n ");
    }

    printf("\nSolución del sistema x = ");
    for (i = 0; i < n; i++) {
        printf("%16.7e ", b[i]);
    }


    //Valor residual 
    printf("\n Valor residual ||Ax - b||^2 = \n");
    z = (double *) malloc(n * sizeof (double));
    prodMatVec(n, A, x, z);
    for (i = 0; i < n; i++) {
        y[i] = y[i] - b[i];
        y[i] = pow(y[i], 2);
        total += y[i];
    }

    total = sqrt(total);
    printf("%16.7e ", total);
}