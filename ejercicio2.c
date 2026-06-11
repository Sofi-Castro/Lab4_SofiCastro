#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){
    
    FILE *fp = fopen(*filename, "r");

    char palabra[5];

    fscanf(fp, "%2s", palabra);
    fscanf(fp, "%d %d", width, height);
    fscanf(fp, "%d", max_val);

    unsigned char *img = malloc(((*width) * (*height)) * sizeof(unsigned char));

    unsigned char *p = img;

    for (int i = 0; i < ((*width) * (*height)); i++) {
        unsigned char val; 
        fscanf(fp, "%hhu", &val);
        *p = val;
        p++;
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

    unsigned char *img = malloc(total * sizeof(unsigned char));

    unsigned char *p = img;

    for (int i = 0; i < total; i++) {
        unsigned char val;
        val = 255 - *pixels;
        *p = val;
        pixels++;
        p++;
    }

    return img;

}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val){

     FILE *fp = fopen(*filename, "w");

    fprintf(fp, "P2\n");
    fprint(fp, "%d %d\n", width, height);
    fprint(fp, "%d\n", max_val);

     for (int i = 0; i < (width * height); i++) {
        fprintf(fp, "%u ", *pixels);

        if ((i+1) % width == 0){
            fprint(fp, "\n");
        }

     }

     fclose(fp);

}

void print_stats(unsigned char *original, unsigned char *thresholded, int total){

}

int main(void){
    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    return 0;
}