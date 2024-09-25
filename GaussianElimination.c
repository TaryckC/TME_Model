#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Matrix
{
    double** Matrix;
    int l;
    int c;

};

void init_matrix(struct Matrix *m) {
    m->Matrix = (double**) malloc(sizeof(double*)*m->l);
    for (int i=0; i<m->l; ++i) {
        m->Matrix[i] = (double*) malloc(sizeof(double)*m->c);
    }
}

void fillMatrix(double* tab, struct Matrix *matrix){
    int v1 = 0;
    //printf("%d", matrix->l * matrix->c);
    // (double) sizeof(tab)/sizeof(double) ==  (double) matrix->l * matrix->c
    if(true) {
        for (int i=0; i<sizeof(tab)/sizeof(double); ++i) {
            
            if (i%matrix->c == 0 && v1 != 0){
                v1++;
            }
            matrix->Matrix[v1][i%matrix->c] = tab[i];
            //printf("%d", tab[i]);
            
        }
    }
}

void printMatrix(struct Matrix *m){
    for (int i=0; i< m->l; ++i){
        for (int j=0; j< m->c; ++j){
                //printf("test");
                //printf("%s", &m.Matrix[i][j] == NULL);
                printf("%lf", (m->Matrix[i][j]));
            }
        printf("\n");
    }
}

int main() {

    struct Matrix matrix;
    matrix.c = 3;
    matrix.l = 3;

    init_matrix(&matrix);

    double tab[9] = {1,2,3,4,5,6,7,8,9};
    //printf("%d", sizeof(tab)/sizeof(double));

    fillMatrix(tab, &matrix);
    printMatrix(&matrix);
    
    return 0;
}