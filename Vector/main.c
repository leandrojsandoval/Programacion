#include "../Generico/Generico.h"
#include "Vector.h"

int main() {
    system("chcp 1252 >nul");
    srand(time(NULL));

    int vector[CAPACIDAD] = {};
    int cantElementos = 0, elemento, posicion;
    bool resBool;

    puts("Ingrese la cantidad de elementos: ");
    fflush(stdin);
    scanf("%d", &cantElementos);

    resBool = cargarVectorEnterosConRand(vector, cantElementos, CAPACIDAD);

    if (resBool == false)
        puts("\nLa cantidad de elementos ingresada supera el tama�o maximo\n");

    /// Ordenamiento insercion

    puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    ordenamientoInsercionAscendente(vector, cantElementos, sizeof(int), cmpInt);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    /// Insertar ordenado

    /*puts("Ingrese un valor a insertar:");
    fflush(stdin);
    scanf("%d",&elemento);

    int resInt = vecInsertarEnOrd(vector, &cantElementos, CAPACIDAD, elemento);

    switch(resInt)
    {
    case TODO_OK:
        printf("El valor %d se inserto correctamente en el vector\n",elemento);
        break;
    case DUPLICADO:
        printf("El valor %d ya se encuentra en el vector\n",elemento);
        break;
    case VECTOR_LLENO:
        printf("El vector esta lleno\n");
        break;
    }

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    ///Eliminar ordenado

    puts("Ingrese un valor a eliminar: ");
    fflush(stdin);
    scanf("%d",&elemento);

    resBool = vecEliminarOrd(vector, &cantElementos, elemento);

    if(resBool)
        printf("El elemento %d se elimino del vector\n",elemento);
    else
        printf("El elemento %d no se encuentra el vector\n",elemento);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Insertar por pos desordenado

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    puts("Ingrese un elemento: ");
    scanf("%d",&elemento);

    puts("Ingrese una posicion:");
    scanf("%d",&posicion);

    resInt = vecInsertarSegunPos(vector, &cantElementos, TAM, elemento, posicion);

    switch(resInt)
    {
    case VECTOR_LLENO:
        printf("La cantidad de elementos (%d) supera el tama�o maximo (%d)\n",cantElementos,TAM);
        break;
    case ERROR_POS:
        printf("La posicion %d supera la cantidad de elementos (%d)\n",posicion,cantElementos);
        break;
    case TODO_OK:
        printf("El elemento %d en la posicion %d se pudo ingresar correctamente\n",elemento,posicion);
        break;
    }

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Eliminar por pos desordenado

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    puts("Ingrese una posicion:");
    scanf("%d",&posicion);

    resBool = vecEliminarSegunPos(vector, &cantElementos, posicion);

    if(resBool)
        printf("El elemento de la posicion %d fue eliminado del vector\n",posicion);
    else
        puts("La posicion ingresada supera la cantidad de elementos");

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Eliminar primera aparicion

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    puts("Ingrese un elemento: ");
    scanf("%d",&elemento);

    resBool = vecEliminarPrimeraAparicion(vector, &cantElementos, elemento);

    if(resBool)
        printf("El elemento %d fue eliminado del vector\n",elemento);
    else
        printf("El elemento %d no se encuentra en el vector\n",elemento);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Eliminar todas las apariciones

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    puts("Ingrese un elemento: ");
    scanf("%d",&elemento);

    printf("El elemento %d se elimino del vector %d veces\n",elemento,vecEliminarTodasLasApariciones(vector, &cantElementos, elemento));

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Ordenar ascendente

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    ordenamientoSeleccionAscendente(vector, cantElementos, sizeof(int), cmpInt);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Ordenar descendente

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    ordenamientoSeleccionDescendente(vector, cantElementos, sizeof(int), cmpInt);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    /// Eliminar duplicados

    /*puts("Vector antes:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);

    vecEliminarDuplicados(vector, &cantElementos);

    puts("Vector despues:");
    mostrarVector(vector, cantElementos, sizeof(int), mostarDatoInt);*/

    return 0;
}
