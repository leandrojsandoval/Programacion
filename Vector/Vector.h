#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CAPACIDAD 100
#define TAM 5

/****************************** Macros de condiciones ******************************/

#define TODO_OK 0
#define VECTOR_LLENO 1
#define DUPLICADO 2
#define ERROR_POS 3
#define ERROR_CE -1

/************************ Funciones principales de vectores ************************/

bool cargarVectorEnterosConRand (int* vector, int ce, int capacidad);
bool cargarVecElemParesOrd (int* vector, int ce, int capacidad);
void mostarDatoInt (const void* vector);
int cmpInt (const void* info1, const void* info2);
int generarValorAleatorio(int limInf, int limSup);

/************************ Funciones para vectores ordenados ************************/

int vecInsertarEnOrd (int* vector, int* ce, int capacidad, int dato);
bool vecEliminarOrd (int* vector, int *ce, int dato);
void vecEliminarDuplicados (int* vector, int* ce);
int* buscarDirSigElemDistinto (const int* vector, const int* dirFin);
void desplazarElementos (int* vector, int* dirSigNumVal, const int* dirFin);

/********************** Funciones para vectores desordenados **********************/

int vecInsertarSegunPos (int* vector, int* ce, int capacidad, int dato, int pos);
bool vecEliminarSegunPos (int* vector, int* ce, int pos);
bool vecEliminarPrimeraAparicion (int* vector, int* ce, int dato);
int vecEliminarTodasLasApariciones (int* vector, int* ce, int dato);

/**************** Funciones para vectores ordenados y desordenados ****************/

///Si estan ordenados se pueden hacer con recursividad
bool vecBuscar (int* vector, int ce, int dato);
int vecCantOcurrencias (int* vector, int ce, int dato);

/***************************** Ordenamiento QuickSort *****************************/

void intercambio(int* vector, int i, int j);
void quickSort (int* vector, int izquierda, int derecha);

#endif // VECTOR_H_INCLUDED
