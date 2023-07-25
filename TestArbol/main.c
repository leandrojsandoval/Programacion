#include <stdio.h>
#include <stdlib.h>

#include "../Arbol/Arbol.h"

typedef struct {
    int codigo;
    float precio;
} Producto;

#define PATH_PRODUCTOS_BIN "Productos.dat"
#define PATH_PRODUCTOS_TXT "Productos.txt"

#define CANT_ELEM_COMPL 15
#define CANT_ELEM_INCOMPL 14
#define CANT_ELEM_AVL 16
#define CANT_ELEM_NO_AVL 15
#define CANT_ELEM_BALAN 12
#define CANT_ELEM_NO_BALAN 10

int crearArchivo(const char* nombreArchivo);
void mostrarProd(const void* elem, int nivel);
void imprimirProd(void* elem, void* datosAccion);
void imprimirInt(void* elem, void* datosAccion);
int grabarArbolEnArchivoTxt(Arbol* pa, const char* nombreArchivo, Accion accion);
void grabarRegistroProd(void* elem, void* datosAccion);

int cmpInt(const void* a, const void* b);
void mostrarInt(const void* elem, int nivel);

int main() {
    Arbol arbolProductos;
    crearArbol(&arbolProductos);
    crearArchivo(PATH_PRODUCTOS_BIN);
    cargarArchivoEnArbol(&arbolProductos, PATH_PRODUCTOS_BIN, sizeof(Producto));
    puts("\n============== Arbol productos ==============\n");
    graficarArbol(&arbolProductos, mostrarProd);

    grabarArbolEnArchivoTxt(&arbolProductos, PATH_PRODUCTOS_TXT, grabarRegistroProd);

    /*
        int vElemsCompleto[CANT_ELEM_COMPL] = {10,5,20,2,7,15,30,1,3,6,8,12,18,25,50};

        int vElemsIncompleto[CANT_ELEM_INCOMPL] = {10,5,20,2,7,30,1,3,6,8,12,18,25,50};

        int vElemsAVL[CANT_ELEM_AVL] = {10, 5, 2, 1, 7, 6, 8, 9, 20, 15, 12, 18, 30, 25, 50, 100};

        int vElemsNoAVL[CANT_ELEM_NO_AVL] = {10, 5, 2, 1, 7, 8, 9, 20, 15, 12, 18, 30, 25, 50, 100};

        int vElemsBalan[CANT_ELEM_BALAN] = {10, 5, 20, 2, 7, 15, 30, 1, 3, 8, 12, 25};

        int vElemsNoBalan[CANT_ELEM_NO_BALAN] = {10, 5, 20, 2, 7, 15, 1, 3, 8, 12};

        Arbol aCompl, aIncompl, aAVL, aNoAVL, aBalan, aNoBalan;
        crearArbol(&aCompl);
        crearArbol(&aIncompl);
        crearArbol(&aAVL);
        crearArbol(&aNoAVL);
        crearArbol(&aBalan);
        crearArbol(&aNoBalan);

        for(int i = 0; i < CANT_ELEM_COMPL; i++)
            insertarOActualizarEnArbol(&aCompl, &vElemsCompleto[i], sizeof(int), cmpInt, NULL);

        for(int i = 0; i < CANT_ELEM_INCOMPL; i++)
            insertarOActualizarEnArbol(&aIncompl, &vElemsIncompleto[i], sizeof(int), cmpInt, NULL);

        for(int i = 0; i < CANT_ELEM_AVL; i++)
            insertarOActualizarEnArbol(&aAVL, &vElemsAVL[i], sizeof(int), cmpInt, NULL);

        for(int i = 0; i < CANT_ELEM_NO_AVL; i++)
            insertarOActualizarEnArbol(&aNoAVL, &vElemsNoAVL[i], sizeof(int), cmpInt, NULL);

        for(int i = 0; i < CANT_ELEM_BALAN; i++)
            insertarOActualizarEnArbol(&aBalan, &vElemsBalan[i], sizeof(int), cmpInt, NULL);

        for(int i = 0; i < CANT_ELEM_NO_BALAN; i++)
            insertarOActualizarEnArbol(&aNoBalan, &vElemsNoBalan[i], sizeof(int), cmpInt, NULL);


        puts("\n============== Arbol Completo ==============\n");
        graficarArbol(&aCompl, mostrarInt);
        printf("%s\n", esArbolCompleto(&aCompl)? "Es completo" : "No es completo");

        puts("\n============== Arbol Incompleto ==============\n");
        graficarArbol(&aIncompl, mostrarInt);
        printf("%s\n", esArbolCompleto(&aIncompl)? "Es completo" : "No es completo");

        puts("\n============== Arbol AVL ==============\n");
        graficarArbol(&aAVL, mostrarInt);
        printf("%s\n", esArbolAVL(&aAVL)? "Es AVL" : "No es AVL");

        puts("\n============== Arbol no AVL ==============\n");
        graficarArbol(&aNoAVL, mostrarInt);
        printf("%s\n", esArbolAVL(&aNoAVL)? "Es AVL" : "No es AVL");

        puts("\n============== Arbol Balanceado ==============\n");
        graficarArbol(&aBalan, mostrarInt);
        printf("%s\n", esArbolBalanceado(&aBalan)? "Es balanceado" : "No es balanceado");

        puts("\n============== Arbol No balanceado ==============\n");
        graficarArbol(&aNoBalan, mostrarInt);
        printf("%s\n", esArbolBalanceado(&aNoBalan)? "Es balanceado" : "No es balanceado");
    */
    return 0;
}

int grabarArbolEnArchivoTxt(Arbol* pa, const char* nombreArchivo, Accion accion) {
    FILE* archTxt = fopen(nombreArchivo, "wt");
    if (!archTxt)
        return ERROR_ARCHIVO;
    recorrerArbolEn(pa, accion, archTxt);
    fclose(archTxt);
    return TODO_OK;
}

void grabarRegistroProd(void* elem, void* datosAccion) {
    Producto* prod = (Producto*)elem;
    fprintf((FILE*)datosAccion, "%d\t\t%f\n", prod->codigo, prod->precio);
}

int crearArchivo(const char* nombreArchivo) {
    FILE* arch = fopen(nombreArchivo, "wb");
    if (!arch)
        return ERROR_ARCHIVO;

    Producto vProd[] =
        {
            {1, 10.5},
            {2, 20.5},
            {3, 30.5},
            {4, 40.5},
            {5, 50.5},
            {6, 60.5},
            {7, 70.5},
            {8, 80.5},
            {9, 90.5}};

    fwrite(vProd, sizeof(vProd), 1, arch);
    fclose(arch);
    return TODO_OK;
}

int cmpInt(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void imprimirProd(void* elem, void* datosAccion) {
    Producto* prod = (Producto*)elem;
    printf("[%d | %f]\n\n\n", prod->codigo, prod->precio);
}

void imprimirInt(void* elem, void* datosAccion) {
    printf("%d\n", *(int*)elem);
}

void mostrarProd(const void* elem, int nivel) {
    for (int i = 0; i < nivel; i++)
        printf("\t");
    Producto* prod = (Producto*)elem;
    printf("[%d | %f]\n\n\n", prod->codigo, prod->precio);
}

void mostrarInt(const void* elem, int nivel) {
    for (int i = 0; i < nivel; i++)
        printf("\t");
    printf("%d\n", *(int*)elem);
}
