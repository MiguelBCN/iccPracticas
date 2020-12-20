#include "pracFuns.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

<<<<<<< Updated upstream
int main(void){
    int n, i, j, a;
    double **A, *x, *z, *b, *y, total = 0;
    
    printf("Introducir el numero de ecuaciones: ");
    scanf("%d", &n);
    
    A = (double **) malloc( n*sizeof(double *) );
    x = (double *) malloc( n*sizeof(double) );
    b = (double *) malloc( n*sizeof(double) );
    y = (double *) malloc( n*sizeof(double) );

    for (i = 0; i < n; i++){
        A[i] = (double *) malloc( n*sizeof(double) );
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

gauss(A, b, 0.01, n);
printf("\nSolución del sistema x = ");
for ( i=0; i < n; i++){
    printf( "%16.7e ", b[i]);
}


//Valor residual 
printf("\n Valor residual ||Ax - b||^2 = \n");
z = (double *) malloc( n*sizeof(double) );
prodMatVec (n,A,x,z);
for (i=0; i <n; i++){
    y[i] = y[i] - b[i];
    y[i] = pow(y[i],2);
    total += y[i];
}
        
total = sqrt(total);
printf( "%16.7e ", total);
=======
int main(void) {
    double **A, *b, *x, *z, r;
    int n;

    printf("Introduir el numero de ecuaciones: ");
    scanf("%d", &n);

    A = (double **) malloc(n * sizeof (double*));
    b = (double *) malloc(n * sizeof (double));
    x = (double *) malloc(n * sizeof (double));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof (double));
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

    gauss(n, A, b, 0.01);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%02f ", A[i][j]);
        }
        printf("\n");
    }


}

int ldlt(int n, double **A, double tol) {
    int i, j, k;

    for (k = 0; k <= n - 1; k++) {

        for (j = 0; j <= k - 1; j++) {
            A[k][k] -= pow(A[k][j], 2) * A[j][j];
        }
        for (i = k + 1; i <= n - 1; i++) {
            for (j = 0; j <= k - 1; j++) {
                A[i][k] -= (A[i][j] * A[k][j] * A[j][j]);
            }
            A[i][k] = A[i][k] * (1 / A[k][k]);
            A[k][i] = A[i][k];
        }
    }

    for (k = 0; k < n; k++) {
        if (fabs(A[k][k]) < tol)
            return 1;
    }

    return 0;
>>>>>>> Stashed changes
}
