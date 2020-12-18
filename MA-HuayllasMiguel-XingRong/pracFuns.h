#ifndef pracFuns
#define pracFuns

int resTS(int n, double **A, double *b, double *x, double tol);
void prodMatVec(int n, double **A, double *x, double *y);
double norma2(int n, double *z);
int gauss(int n, double **A, double *v, double tol);
int gaussPivot(int n, double **A, double *v, double tol);

#endif
