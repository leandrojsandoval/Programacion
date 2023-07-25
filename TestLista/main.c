#include <stdio.h>
#include <stdlib.h>

#include "../ListaSimple/Lista.h"

#define PATH_NUMEROS_TXT "Numeros.txt"

int cmpEnteros(const void* elem1, const void* elem2);
void mostrarEntero(void* elem, void* datosAccion);
void imprimirEntero(void* elem, void* datosAccion);

int main() {
    Lista listaEnteros;
    crearLista(&listaEnteros);
    FILE* archNumeros = fopen(PATH_NUMEROS_TXT, "wt");
    if (!archNumeros)
        return -1;

    int vecEnterosOrd[] = {1, 1, 1, 2, 3, 3, 3, 4, 6, 7, 7, 7};
    int vecEnterosDes[] = {6, 2, 1, 7, 3, 1, 3, 4, 1, 7, 3, 7};

    puts("===================================================");

    puts("Eliminar duplicados en lista ordenada");

    for (int i = 0; i < sizeof(vecEnterosOrd) / sizeof(int); i++)
        insertarUltimoEnLista(&listaEnteros, &vecEnterosOrd[i], sizeof(int));

    puts("Lista cargada:");
    recorrerLista(&listaEnteros, mostrarEntero, NULL);
    putchar('\n');

    eliminarDuplicadosDeListaOrd(&listaEnteros, cmpEnteros);

    puts("Lista despues de eliminar duplicados");
    recorrerLista(&listaEnteros, mostrarEntero, NULL);
    putchar('\n');

    vaciarLista(&listaEnteros);

    puts("===================================================");

    puts("Eliminar duplicados en lista desordenada:");

    for (int i = 0; i < sizeof(vecEnterosDes) / sizeof(int); i++)
        insertarUltimoEnLista(&listaEnteros, &vecEnterosDes[i], sizeof(int));

    puts("Lista cargada: ");
    recorrerLista(&listaEnteros, mostrarEntero, NULL);
    putchar('\n');

    eliminarDuplicadosDeListaDes(&listaEnteros, cmpEnteros);

    puts("Lista despues de eliminar duplicados:");
    recorrerLista(&listaEnteros, mostrarEntero, NULL);
    putchar('\n');

    puts("===================================================");

    ordenarLista(&listaEnteros, cmpEnteros, 1);

    puts("Lista ordenada");
    recorrerLista(&listaEnteros, mostrarEntero, NULL);
    putchar('\n');

    recorrerLista(&listaEnteros, imprimirEntero, archNumeros);
    puts("Se cargaron los elementos de la lista al archivo");

    fclose(archNumeros);

    return 0;
}

int cmpEnteros(const void* elem1, const void* elem2) {
    int* e1 = (int*)elem1;
    int* e2 = (int*)elem2;
    return *e1 - *e2;
}

void mostrarEntero(void* elem, void* datosAccion) {
    int* e = (int*)elem;
    printf("%d ", *e);
}

void imprimirEntero(void* elem, void* datosAccion) {
    fprintf((FILE*)datosAccion, "%d ", *(int*)elem);
}
