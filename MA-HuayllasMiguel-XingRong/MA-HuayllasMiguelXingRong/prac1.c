/* COGNOM1: HUAYLLAS COGNOM2: CHOQUE NOM: MIGUEL VICTOR DNI / NIUB : 17510710 */
/* COGNOM1: XING COGNOM2 : NOM: RONG DNI / NIUB :  20274962*/

#include "pracFuns.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
    double **A, *b, *x, *z, r;
    int n;
    
    printf("Introduir el numero de ecuaciones: ");
    scanf("%d", &n);
    
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
            scanf("%le", &A[i][j]);
        }
    }
    
    printf("\nVector b\n");
    
    for (int i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf("%le", &b[i]);
    }
    
    resolTS(n, A, b, x, 0.01);
    printf("\nSolución del sistema x = ");
    for (int i=0;i < n;i++){
        printf( "%16.7e ", x[i]);
    }
    
    z = (double *) malloc (n * sizeof (double));
    prodMatVec (n, A, x, z);
    for (int i=0; i < n; i++){
        z[i] = z[i] - b[i];
    }
    //calcula la norma del vector residul//
    r = norma2(n, z);
    printf("\nEl valor residual: ");
    printf( "|| Z || = %16.7e \n", r);

    
 /*   
  //Matriu trasposada
    for (i=0; i<n; i++){
        for (j=0;j<n;j++){
            T[j][i] = L[i][j];
        }
    }
    
    printf("\n Matriu L transposada = \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf(" %16.7e ", T[i][j]);
        }
        printf("\n");
    }
    
    resTS(n,T,x,b);
    
    printf("\n Vector solució x de la Transposada = \n");
    for (i=0;i<n;i++){
        printf( "%16.7e ", x[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
        free (L[i]);

    free(L);
    
    for (i=0;i<n;i++)
        free (T[i]);
    
    free(T);
    free(x);
    free(b);
    free(y);
    return 0;
*/
}
