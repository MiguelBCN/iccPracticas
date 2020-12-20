#ifndef PRACFUNS_H
#define PRACFUNS_H

int resolTS(int n, double **A, double *b, double *x, double tol);
void prodMatVec(int n, double **A, double *x, double *y);
double norma2(int n, double *z);
int gauss(double **A, double *v, double tol, int n);
int gausspivot(double **A, double *v, double tol, int n);
float horner(float z, float a[], int g);

#endif /* PRACFUNS_H */

