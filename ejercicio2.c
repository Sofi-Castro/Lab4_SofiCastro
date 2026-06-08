#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){
    
    FILE *fp = fopen("imagen.pgm", "r");

    char palabra[3];

    fscanf(fp, "%2s", palabra);
    fscanf(fp, "%d %d", width, height);
    fscanf(fp, "%d", max_val);

    unsigned char *img = malloc(((*width) * (*height)) * sizeof(unsigned char));

    unsigned char *p = img;

    for (int i = 0; i < ((*width) * (*height)); i++, p++) {
        int val; 
        fscanf(fp, "%d", &val);
        *p = (unsigned char)val;
    }

    fclose(fp);

    return img;
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