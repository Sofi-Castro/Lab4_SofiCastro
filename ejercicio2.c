#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){
    
    FILE *fp = fopen("imagen.pgm", "r");

    fscanf(fp, "%2s", *filename);
    fscanf(fp, "%d %d", width, height);
    fscanf(fp, "%d", max_val);

    int **img = malloc(*height * sizeof(int*));

    for (int i = 0; i < *height; i++) {
        *(img + i) = malloc(*width * sizeof(int));
    }

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d", *(*(img + i) + j));
        }
    }

    fclose(fp);
}

void apply_threshold(unsigned char *pixels, int total, int threshold){

    for (int i = 0; i < total; i++){

        if (*pixels >= threshold){
            *pixels = 255;
        } else {
            *pixels = 0;
        }
        
        pixels++;

    }
}

unsigned char *make_negative(unsigned char *pixels, int total){

    for (int i = 0; i < total; i ++){
        *pixels = (255 - *pixels);
    }

}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val){

}

void print_stats(unsigned char *original, unsigned char *thresholded, int total){

}

int main(void){
    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    return 0;
}