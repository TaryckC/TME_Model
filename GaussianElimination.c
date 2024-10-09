#include <stdio.h>
#include <stdlib.h>

void gaussian_elimination(double** A, double* b, int n) {
    for (int i = 0; i < n; ++i) {
        int j = i;

        // Trouver un pivot non nul
        while (j < n && A[j][i] == 0) {
            j++;
        }

        // Si aucun pivot n'a été trouvé, il n'y a pas de solution unique
        if (j == n) {
            printf("No unique solution\n");
            return;
        }

        // Élimination de Gauss pour rendre les éléments en dessous du pivot égaux à zéro
        for (int j = i + 1; j < n; ++j) {
            double factor = A[j][i] / A[i][i];
            b[j] -= factor * b[i];

            for (int k = i; k < n; ++k) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    // Affichage de la matrice triangulaire supérieure et du vecteur b
    printf("Upper triangular matrix A:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    printf("Vector b:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lf ", b[i]);
    }
    printf("\n");
}

int main() {
    int n = 3;

    // Allocation de la matrice A
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; ++i) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    // Initialisation de la matrice A
    A[0][0] = 2;  A[0][1] = 1;  A[0][2] = -1;
    A[1][0] = -3; A[1][1] = -1; A[1][2] = 2;
    A[2][0] = -2; A[2][1] = 1;  A[2][2] = 2;

    // Allocation et initialisation du vecteur b
    double* b = (double*)malloc(n * sizeof(double));
    b[0] = 8;
    b[1] = -11;
    b[2] = -3;

    // Appel de la fonction d'élimination de Gauss
    gaussian_elimination(A, b, n);

    // Libération de la mémoire
    for (int i = 0; i < n; ++i) {
        free(A[i]);
    }
    free(A);
    free(b);

    return 0;
}