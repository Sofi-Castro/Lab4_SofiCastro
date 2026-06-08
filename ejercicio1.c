#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findLargestLine(int **matrix, int size, int *resultado){

    int contador = 0;

    for (int a = 0; a < size; a++){

        int *fila = *(matrix + a);

        for (int i = 0; i < size; i++) {
            if (*(fila + i) == 1) {
                contador += 1;
                if (contador > *resultado){
                    *resultado = contador;
                }
            } else {
                contador = 0;
            }
        }
    }
}


void allocateMatrix(int ***matrix, int size) {

    *matrix = malloc(size * sizeof(int *));

    for(int i = 0; i < size; i++){
        *((*matrix) + i) = malloc(size * sizeof(int));
    }
}


void fillMatrix(int **matrix, int size){

    srand(time(NULL));

    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            *(*(matrix + i) + j) = rand() % 2;
        }
    }
    
    }

void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d): \n", size, size);
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            printf("%d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size){
    for (int i=0; i < size; i++){
        free (*(matrix + i));
    }
    free (matrix);
}

int main(void){
    int size, largestLine = 0;
    int **matrix = NULL;

    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &size);

    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    printMatrix(matrix, size);
    findLargestLine(matrix, size, &largestLine);
    freeMatrix(matrix, size);

    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

    return 0;
}