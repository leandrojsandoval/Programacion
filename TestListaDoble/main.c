#include <stdio.h>
#include <stdlib.h>

#include "../Bibliotecas/ListaDoble/ListaDoble.h"

void mostrarEntero(void* elem, void* datosAccion);
int cmpEnteros(const void* elem1, const void* elem2);

int main() {
    Lista listaEnteros;
    crearLista(&listaEnteros);
    int i;

    for (i = 0; i < 10; i++)
        insertarOActualizarEnListaOrd(&listaEnteros, &i, sizeof(int), cmpEnteros, NULL);

    puts("Lista de izquierda a derecha");
    recorrerListaDeIzqADer(&listaEnteros, mostrarEntero, NULL);

    vaciarLista(&listaEnteros);

    printf("%s\n", listaVacia(&listaEnteros) ? "La lista se encuentra vacia" : "La lista no esta vacia");

    int vecOrdDup[] = {1, 1, 2, 2, 7, 7, 8, 9, 9};
    Lista listaOrdDup;
    crearLista(&listaOrdDup);

    for (i = 0; i < sizeof(vecOrdDup) / sizeof(int); i++)
        insertarUltimoEnLista(&listaOrdDup, &vecOrdDup[i], sizeof(int));

    eliminarYOActualizarDuplicadosDeListaOrd(&listaOrdDup, cmpEnteros, NULL);

    puts("\nEliminar duplicados lista ordenada\n");
    puts("Lista de izquierda a derecha\n");
    recorrerListaDeIzqADer(&listaOrdDup, mostrarEntero, NULL);

    int vecDesDup[] = {1, 2, 2, 1, 3, 7, 8, 7, 9, 3, 10, 10};
    Lista listaDesDup;
    crearLista(&listaDesDup);

    for (i = 0; i < sizeof(vecDesDup) / sizeof(int); i++)
        insertarUltimoEnLista(&listaDesDup, &vecDesDup[i], sizeof(int));

    eliminarYOActualizarDuplicadosDeListaDes(&listaDesDup, cmpEnteros, NULL);

    puts("\nEliminar duplicados lista desordenada\n");
    puts("Lista de izquierda a derecha\n");
    recorrerListaDeIzqADer(&listaDesDup, mostrarEntero, NULL);

    return 0;
}

void mostrarEntero(void* elem, void* datosAccion) {
    printf("- %d -\n", *(int*)elem);
}

int cmpEnteros(const void* elem1, const void* elem2) {
    return *(int*)elem1 - *(int*)elem2;
}
