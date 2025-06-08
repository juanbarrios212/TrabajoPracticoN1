#include <stdio.h>
#include <string.h>
#include "articulos.h"


void cargar_articulo(articulos_t articulos[]) {
    int i = 0, articulo_index, sucursal;
    char articulo[90];

    printf("Ingrese la descripcion del articulo: ");
    scanf("%s", articulo);

    while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;

    articulo_index = i;
    strcpy(articulos[articulo_index].descripcion, articulo);

    printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);

    printf("Para que sucursal va a realizar la carga? (1,2,3): ");
    scanf("%d", &sucursal);

    printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
    scanf("%d", &articulos[articulo_index].cantidad_sucursal[sucursal - 1]);

    // Recalcular el total
    articulos[articulo_index].total = 0;
    for (i = 0; i < 3; i++) 
        articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];
}

void imprimir_articulos(articulos_t articulos[]) {
    int i = 0;

    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i].descripcion[0]) {
        printf("%s\t%d\t%d\t%d\t%d\n", articulos[i].descripcion,
            articulos[i].cantidad_sucursal[SUCURSAL_1],
            articulos[i].cantidad_sucursal[SUCURSAL_2],
            articulos[i].cantidad_sucursal[SUCURSAL_3],
            articulos[i].total);
        i++;
    }
}

void ordenar_articulos(articulos_t articulos[]) {
    int i, j;
    articulos_t temp;

    for (i = 0; i < CANT_ARTICULOS - 1; i++) {
        for (j = 0; j < CANT_ARTICULOS - i - 1; j++) {
            if (articulos[j].total < articulos[j + 1].total) {
                temp = articulos[j];
                articulos[j] = articulos[j + 1];
                articulos[j + 1] = temp;
            }
        }
    }
}