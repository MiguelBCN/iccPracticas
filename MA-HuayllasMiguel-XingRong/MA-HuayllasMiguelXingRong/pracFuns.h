

#ifndef PRACFUNS_H
#define PRACFUNS_H

//void resTinf (int n, double **L, double *x, double *b);
void resTS (int n, double **U, double *x, double *b);
void prodMatVec (int m, int n, double **A, double *x, double *y);
//void prodMatMat (int m, int n, int p, double **A, double **B, double **C);
int gauss(int n, double **A, double *v, double tol);
int gausspivot(int n, double **A, double *v, double tol);
//gausstri
float horner(float z, float a[]);
double spline ( int n , double *x , double *M , double *h ,double *N , double *L , double z );



#endif /* PRACFUNS_H */

