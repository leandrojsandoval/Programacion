#include "Vector.h"

/************************ Funciones principales de vectores ************************/

int cargarVectorPorTeclado (int* vector, int ce, int capacidad)
{
    if(ce > capacidad)
        return VECTOR_LLENO;
    if(ce <= 0)
        return ERROR_CE;
    int i;
    for(i=0; i<ce; i++)
    {
        printf("\nElemento en la posicion %d: ",i);
        scanf("%d",vector);
        vector++;
    }
    return TODO_OK;
}


bool cargarVectorEnterosConRand (int* vector, int ce, int capacidad)
{
    if(ce > capacidad)
        return false;
    const int* dirFin = vector + ce - 1;
    while(vector <= dirFin)
    {
        int numeroRandom = generarValorAleatorio(1, 100);
        *vector++ = numeroRandom;
    }
    return true;
}

bool cargarVecElemParesOrd (int* vector, int ce, int capacidad)
{
    if(ce > capacidad)
        return false;
    int numero = 0;
    for(int* i = vector ; i < vector + ce; i++)
    {
        *i = numero;
        numero += 2;
    }
    return true;
}

void mostarDatoInt (const void* vector)
{
    const int* vec = (const int*)vector;
    printf("%d ", *vec);
}

int cmpInt (const void* info1, const void* info2)
{
    const int* i1 = (const int*)info1;
    const int* i2 = (const int*)info2;
    return *i1 - *i2;
}

int generarValorAleatorio(int limInf, int limSup)
{
    return rand () % (limSup - limInf + 1) + limInf;
}

/************************ Funciones para vectores ordenados ************************/

bool vecEliminarOrd (int* vector, int *ce, int dato)
{
    int i = 0;

    while(i < *ce && vector[i] < dato)
        i++;

    if(dato < vector[i] || i == *ce)
        return false;

    for(int j = i; j <= *ce - 2; j++)
        vector[j] = vector[j + 1];

    (*ce)--;
    return true;
}

void vecEliminarDuplicados (int* vector, int* ce)
{
    const int* dirIni = vector;
    const int* dirFin = vector + *ce - 1;
    while(vector < dirFin)
    {
        if(*vector == *(vector + 1))
        {
            int* dirSigNumVal = buscarDirSigElemDistinto(vector, dirFin);
            int cantDupli = dirSigNumVal - vector;
            desplazarElementos(vector, dirSigNumVal, dirFin);
            (*ce) -= cantDupli;
            dirFin = dirIni + *ce - 1;
        }
        vector++;
    }
}

int* buscarDirSigElemDistinto (const int* vector, const int* dirFin)
{
    while(vector < dirFin && *vector == *(vector + 1))
        vector++;
    return (int*)vector;
}

void desplazarElementos (int* vector, int* dirSigNumVal, const int* dirFin)
{
    while(dirSigNumVal <= dirFin)
        *vector ++ = *dirSigNumVal++;
}

/*Ejercicio 23: Desarrollar una función que inserte un elemento en un arreglo de
enteros, ordenado en forma ascendente, de forma de no alterar el orden.*/

int vecInsertarEnOrd (int* vector, int* ce, int capacidad, int dato)
{
    if(*ce >= capacidad)
        return VECTOR_LLENO;

    int i = 0;

    while(i < *ce && dato > vector[i])
        i++;

    if(dato == vector[i])
        return DUPLICADO;

    for(int j = *ce -1; j>= i; j--)
        vector[j + 1] = vector[j];

    vector[i] = dato;
    (*ce)++;
    return TODO_OK;
}

/**************** Funciones para vectores ordenados y desordenados ****************/

bool vecBuscar (int* vector, int ce, int dato)
{
    int i = 0;

    while(i < ce && vector[i] != dato)
        i++;

    return vector[i] == dato;
}

int vecCantOcurrencias (int* vector, int ce, int dato)
{
    int i = 0, ocurencias = 0;
    while(i < ce)
    {
        if(vector[i] == dato)
            ocurencias++;
        i++;
    }
    return ocurencias;
}

/********************** Funciones para vectores desordenados **********************/

/*Ejercicio 22: Desarrollar una función que inserte un elemento en un arreglo
de enteros, dada la posición de inserción.*/

int vecInsertarSegunPos (int* vector, int* ce, int capacidad, int dato, int pos)
{
    if(*ce > capacidad)
        return VECTOR_LLENO;

    if(pos > *ce)
        return ERROR_POS;

    int* dirFin = vector + *ce - 1;

    while(dirFin >= &vector[pos])
    {
        *(dirFin + 1) = *dirFin;
        dirFin--;
    }

    vector[pos] = dato;

    if(*ce < capacidad)
        (*ce)++;

    return TODO_OK;
}



/*Ejercicio 24: Desarrollar una función que elimine el elemento que ocupa una
determinada posición de un arreglo de enteros.*/

bool vecEliminarSegunPos (int* vector, int* ce, int pos)
{
    if(pos >= *ce)
        return false;

    const int* dirFin = vector + *ce - 1;
    vector += pos;

    while(vector < dirFin)
    {
        *vector = *(vector + 1);
        vector++;
    }

    (*ce)--;
    return true;
}

/*Ejercicio 25: Desarrollar una función que elimine la primera aparición de un
elemento determinado de un arreglo de enteros.*/

bool vecEliminarPrimeraAparicion (int* vector, int* ce, int dato)
{
    int* actual = vector;
    const int* dirFin = vector + *ce - 1;

    while(actual <= dirFin && *actual != dato)
        actual++;

    if(actual > dirFin)
        return false;

    vecEliminarSegunPos(actual, ce, 0);
    return true;
}

/*Ejercicio 26: Desarrollar una función que elimine todas las apariciones de un
determinado elemento de un arreglo de enteros.*/

int vecEliminarTodasLasApariciones (int* vector, int* ce, int dato)
{
    int cont = 0;
    int* actual = vector;
    const int* dirFin = vector + *ce - 1;
    while(actual <= dirFin)
    {
        if(*actual == dato)
        {
            vecEliminarPrimeraAparicion (actual, ce, dato);
            cont++;
        }
        actual++;
    }
    return cont;
}

/***************************** Ordenamiento QuickSort *****************************/

void intercambio(int* vector, int i, int j)
{
    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

void quickSort (int* vector, int izquierda, int derecha)
{
    int i, ultimo;
    if(izquierda >= derecha)
    {
        return;
    }
    intercambio(vector, izquierda, (izquierda+derecha)/2);
    ultimo = izquierda;
    for(i=izquierda+1; i<=derecha; i++)
    {
        if(vector[i]<vector[izquierda])
        {
            intercambio(vector,++ultimo,i);
        }
    }
    intercambio(vector, izquierda, ultimo);
    ///Recursividad
    quickSort(vector, izquierda, ultimo-1);
    quickSort(vector, ultimo+1, derecha);
}
