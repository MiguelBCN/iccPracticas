#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//resTS, norma2, prodMatVec, gauss, gausspivot,
//gausstri, horner i spline.

//Funcion para resolver el sistema de ecuaciones Ax = b siendo A una matriz triangular superior,
// devuelve 0 si ha podido resolver el sistema i 1 en caso contrario.

int resolTS(int n, double** A, double* b, double* x, double tol) {
    // n: la dimension
    // A : la matriz, triangular superior
    // b : el vector 
    // x: solucion
    // tol : torelancia aceptada
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        if (fabsf(A[i][i]) >= tol) {
            for (int j = n - 1; j > i; j--) {
                x[i] -= (A[i][j] * x[j]);
            }
            x[i] /= A[i][i];
        }//no ha podido resolver el sistema
        else {
            return 1;
        }
    }
    return 0;
}

//Funcion para calcular y = Ax 

void prodMatVec(int n, double **A, double *x, double *y) {
    for (int i = 0; i < n; i++) {
        y[i] = 0;
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

//Funcion para calcular la norma

double norma2(int n, double *z) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += powf(z[i], 2);
    }
    return sqrtf(res);

}

<<<<<<< Updated upstream
/* 
La funcio gauss retorna:
0 si ha trobat la solucio, i aquesta s'ha guardat en v.
1 si en algun moment sha aturat el proces.
*/
int gauss(double **A, double *v, double tol, int n) {
    double *t, temp;
    t = (double *) malloc (n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        t[i] = v[i];
    }
    for (int j = 0; j < n-1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (fabsf(A[j][j]) >= tol) {
                temp = A[i][j] / A[j][j];

                for (int k = j; k < n; k++) {
                    A[i][k] -= A[j][k] + temp;
                }
            }
            else {
                return 1;
            }
            t[i] -= t[j] * temp;
        }
    }
    resolTS(n, A, t, v, tol);
    free(t);
    return 0;
}

/*
float horner(float z, float a[]){
   int i;
   float sum;
   sum = a[7];

   for (i = 6; i >= 0; i--){
      sum = sum*z+a[i];
   }
   
   return sum;
=======
int gauss(int n, double **A, double *v, double tol) {

    double *t; //Variable que soluciones b que se pasara a resolTS
    double temp;

    t = (double *) malloc(n * sizeof (double));

    for (int cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = v[cont1];
    }

    for (int cont2 = 0; cont2 < n - 1; cont2++) {
        for (int i = cont2 + 1; i < n; i++) {

            if (fabsf(A[cont2][cont2]) >= tol) {
                temp = A[i][cont2] / A[cont2][cont2];

                for (int cont3 = cont2; cont3 < n; cont3++) {
                    A[i][cont3] -= A[cont2][cont3] + temp;
                }

            } else {
                return 1;
            }

            t[i] -= t[cont2] * temp;

        }
    }

    resolTS(n, A, t, v, tol);
    free(t);

    return 0;

}

int gausspivot(double **A, double *v, double tol, int n) {
    double *t; //Variable que soluciones b que se pasara a resolTS
    double temp;

    t = (double *) malloc(n * sizeof (double));

    for (int cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = v[cont1];
    }
    
    // Hacemos el calculo de GAUSS con pivot
        for (int cont2 = 0; cont2 < n - 1; cont2++) {
        for (int i = cont2 + 1; i < n; i++) {

            if (fabsf(A[cont2][cont2]) >= tol) {
                temp = A[i][cont2] / A[cont2][cont2];

                for (int cont3 = cont2; cont3 < n; cont3++) {
                    A[i][cont3] -= A[cont2][cont3] + temp;
                }

            } else {
                return 1;
            }

            t[i] -= t[cont2] * temp;

        }
    }
    //Llamamos a la funcion resolTS
    resolTS(n, A, t, v, tol);
    free(t);

    return 0;


}

float horner(float z, float a[]) {
    int i;
    float sum;
    sum = a[7];

    for (i = 6; i >= 0; i--) {
        sum = sum * z + a[i];
    }

    return sum;
>>>>>>> Stashed changes
}

