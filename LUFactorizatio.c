#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Pair;

// Fonction pour créer une matrice de dimensions rows x cols remplie de 0
double** createMatrix(int rows, int cols) {
    // Allouer de la mémoire pour les pointeurs des lignes
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Allouer de la mémoire pour chaque ligne et initialiser les éléments à 0
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        
        // Remplir chaque élément de la ligne avec 0
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0.0;
        }
    }

    return matrix;
}

// Fonction pour afficher une matrice
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}


int swapRows(double** matrix, int row1, int row2) {
    // Retourne 0 si on essaye de permuter les même lignes entre elles et return un autre entier sinon
    if (row1 == row2)
        return 0;
    double* temp_row = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp_row;
    return 1;
}

int swapColumns(double** matrix, int size, int col1, int col2) {
    // Retourne 0 si on essaye de permuter les même colonnes entre elles et return un autre entier sinon
    if (col1 == col2)
        return 0;
    for (int i = 0; i < size; ++i) {
        double temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
    return 1;
}


double** createPermutationMatrix(int size, int row1, int row2) {
    double** matrix = createMatrix(size, size);
    for (int i=0; i<size; ++i) {
        matrix[i][i] = 1;
    }
    double* temp_row = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp_row;

    return matrix;
}

Pair searchForMax(double** matrix, int size) {
    double max = 0;
    Pair pair;
    pair.row = 0; pair.col = 0;
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            if (matrix[i][j]*matrix[i][j]>max*max) {
                max = matrix[i][j];
                pair.row = i;
                pair.col = j;
            }
        }
    }
    return pair;
}

void gaussian_elimination(double** A, double* b, int n) {
    for (int i = 0; i < n; ++i) {

        Pair max = searchForMax(A, n);
        if (A[max.row][max.col] == 0)
            printf("System has no unique solution.");
            break;
        
        // Si on a trouver un maximum différent de 0 en valeur absolue :
        //  On swap déplace le maximum au pivot (si il y est déjà, rien ne se passe)
        swapColumns(A, n, max.col, i);
        swapRows(A, max.row, i);

        // On passe à l'élimination de gauss
        //for (int indice=0) {}
            // L2 <- L2 - factor * L1
            // On sait que factor = premier Coef de L2 / valeur du max
            //double factor = 

        // On recommence
    }
}

int main() {
    int rows = 3, cols = 3;

    // Créer une matrice de 3 lignes et 4 colonnes
    double** matrix = createMatrix(rows, cols);

    // Exemple d'initialisation
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 5; matrix[1][1] = 6; matrix[1][2] = 7;
    matrix[2][0] = 9; matrix[2][1] = 10; matrix[2][2] = 11;

    printf("Matrice originale:\n");
    printMatrix(matrix, rows, cols);

    // Échanger la colonne 1 et la colonne 3
    swapColumns(matrix, 3,1,2);

    printf("Matrice après avoir effectué les permutations\n");
    printMatrix(matrix, rows, cols);

    return 0;
}