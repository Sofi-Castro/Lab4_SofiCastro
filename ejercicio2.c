#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val){
    
    FILE *fp = fopen(*filename, "r");

    if (fp == NULL) {
        return NULL;
    }

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

    unsigned char blanco = 0, negro = 0, suma = 0;
    int promedio = 0;

    for (int i = 0; i < total; i++){

        if (*thresholded == 255){
            blanco += 1;
        } else{
            negro += 1;
        }

        suma += *original;

        original++;
        thresholded++;

    }

    promedio = (int)suma / total;


    printf("La cantidad de pixeles blancos es %hhu y la cantidad de pixeles negros es %huu\n", blanco, negro);
    printf("El promedio de los pixeles del arreglo original es %d\n", promedio);

}

void freearray(int *pixels){
    free (pixels);
}

int main(void){
    int width, height, max_val, threshold, total;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;
    unsigned char *original = NULL;
    char *ruta = "imagen.pgm";
    char *archivo_1 = "output_threshold.pgm";
    char *archivo_2 = "output_negative.pgm";

    printf("Indice el umbral para aplicar a la foto:\n");
    scanf("%d", &threshold);

    pixels = read_pgm(ruta, &width, &height, &max_val);

    total = width * height;

    apply_threshold(pixels, total, threshold);
    negative = make_negative(pixels, width*height);

    write_pgm(archivo_1, pixels, width, height, max_val);
    write_pgm(archivo_2, negative, width, height, max_val);

    original = read_pgm(ruta, &width, &height, &max_val);

    print_stats(original, pixels, total);

    freearray(original);
    freearray(negative);
    freearray(pixels);

    return 0;
}