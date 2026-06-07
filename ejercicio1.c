#include <stdio.h>
#include <stdlib.h>

void allocateMatrix(int **matrix, int size, int *result) {
 
}

void fillMatrix(int ***matrix, int size){
    *matrix = malloc(size * sizeof(int *));

    for(int i = 0; i < size; i++){
        *((*matrix) + i) = malloc(size * sizeof(int));
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
    int size, largestLine;
    int **matrix = NULL;


    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

    return 0;
}