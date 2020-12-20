/* COGNOM1: HUAYLLAS COGNOM2: CHOQUE NOM: MIGUEL VICTOR DNI / NIUB : 17510710 */
/* COGNOM1: XING COGNOM2 : NOM: RONG DNI / NIUB :  20274962*/

#include "pracFuns.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* 
La funcio gauss retorna:
0 si ha trobat la solucio, i aquesta s'ha guardat en v.
1 si en algun moment sha aturat el proces.
 */

int gauss(double **A, double *v, double tol, int n) {
    double *t, c; // t = v luego de ahcer gauss , c valor que los pivotes se resten y den 0
    t = (double *) malloc(n * sizeof (double));


    for (int cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = v[cont1];
    }

    for (int i = 0; i < n - 1; i++) {
        if (A[i][i] == 0.0) {
            printf("\nLa diagonal de la matriz principal tiene 0 trate gauss con pivote\n");
            return 1;
        }
        for (int k = i + 1; k < n; k++) {
            //Comprobamos la tolerancia
            if (!(fabsf(A[k][i]) >= tol)) {
                printf("\nEl valor %f no cumple con la tolerancai dada en la pos A[%d][%d]\n", A[k][i], k, i);
                return (1);
            }

            // Calcumos el valor que iguala a ambas filas
            c = A[k][i] / A[i][i];
            for (int j = 0; j < n; j++) {
                // Calculamos las filas
                A[k][j] = A[k][j] - c * A[i][j];
            }
            // Calculamos b con gauss
            t[k] = t[k] - c * t[i];
        }

    }

    resolTS(n, A, t, v, tol);
    free(t);
    return 0;
}

int gausspivot(double **A, double *v, double tol, int n) {
    double *t;
    t = (double *) malloc(n * sizeof (double));


    for (int cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = v[cont1];
    }

    for (int i = 0; i < n - 1; i++) {
        //Pivote parcial
        for (int k = i + 1; k < n; k++) {
            //Comprobamos la tolerancia
            if (!(fabsf(A[k][i]) >= tol)) {
                printf("El valor %f no cumple con la tolerancai dada en la pos A[%d][%d]", A[k][i], k, i);
                return (1);
            }
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if (fabs(A[i][i]) < fabs(A[k][i])) {
                //Cambiamos filas
                double tempb;
                for (int j = 0; j < n; j++) {
                    double temp;
                    temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
                tempb = t[i];
                t[i] = t[k];
                t[k] = tempb;
            }
        }
        //Gauss luego de pivote
        for (int k = i + 1; k < n; k++) {
            double term = A[k][i] / A[i][i];
            for (int j = 0; j < n; j++) {
                A[k][j] = A[k][j] - term * A[i][j];
            }
            t[k] = t[k] - term * t[i];
        }
    }

    // Calculado Gauss llamamos a resolTS

    resolTS(n, A, t, v, tol);
    free(t);
    return 0;
}

float horner(float z, float a[], int g) {
    int i;
    float sum;
    sum = a[g];

    for (i = g - 1; i >= 0; i--) {
        sum = sum * z + a[i];
    }
    return sum;
}
