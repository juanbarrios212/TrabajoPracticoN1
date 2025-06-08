#include <stdio.h>
#include "articulos.h"

int main(void) {
    articulos_t articulos[CANT_ARTICULOS] = {0};
    int seg = 0;

    printf("Bienvenido al final de Info 1\n\n");

    do {
        cargar_articulo(articulos);
        printf("Desea Ingresar Otro Articulo? 1-Si, 2-No: ");
        scanf("%d", &seg);
    } while (seg == 1);

    imprimir_articulos(articulos);

    ordenar_articulos(articulos);

    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n################################### \n");

    imprimir_articulos(articulos);

    return 0;
}