#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//resTS, norma2, prodMatVec, gauss, gausspivot,
//gausstri, horner i spline.

// Función para resolver el sistema de ecuaciones Ax = b cuando A es triangular superior
int resTS(int n, double** A, double* b, double* x, double tol) {
    for (int cont1 = n-1; cont1 >= 0; cont1--) {
        x[cont1] = b[cont1];
        if (fabsf(A[cont1][cont1]) >= tol) {
            for (int cont2 = n-1; cont2 > cont1; cont2--) {
                x[cont1] -= (A[cont1][cont2] * x[cont2]);
            }
            x[cont1] /= A[cont1][cont1];
        }
        else {
            return 1;
        }
    }
    return 0;
}
// Para calcular y = Ax 
void prodMatVec(int n, double **A, double *x, double *y) {
    
    for (int i = 0; i < n; i++) {
        y[i] = 0;
        
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
        
    }
    
}
// Funcion auxiliar de proMatVec
double norma2(int n, double *z) {
    double norma = 0;
    
    for (int i = 0; i < n; i++) {
        norma += powf(z[i], 2);
    }
    return sqrtf(norma);
    
}