#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 6
#define NO_CUADRADA 0
#define TODO_OK 1

int menuMatrices ();
int menuMostrarDS ();
int menuMostrarDP ();
int menuSumaDP ();
int menuSumaDS();

void cargarMatriz (int matriz[][TAM],int fila,int columna);
void mostrarMatriz (int matriz[][TAM],int fila,int columna);

void mostrarDP (int matriz[][TAM],int orden);
void mostrarElementosAbajoDP (int matriz[][TAM],int orden);
void mostrarElementosAbajoSinDP (int matriz[][TAM],int orden);
void mostrarElementosArribaDP (int matriz[][TAM],int orden);
void mostrarElementosArribaSinDP (int matriz[][TAM],int orden);

void mostrarDS (int matriz[][TAM],int orden);
void mostrarElementosAbajoDS (int matriz[][TAM],int orden);
void mostrarElementosAbajoSinDS (int matriz[][TAM],int orden);
void mostrarElementosArribaDS (int matriz[][TAM],int orden);
void mostrarElementosArribaSinDS (int matriz[][TAM],int orden);

int sumaDS (int matriz[][TAM],int orden);
int sumaElementosArribaDS (int matriz[][TAM],int orden);
int sumaElementosArribaSinDS (int matriz[][TAM],int orden);
int sumaElementosAbajoDS (int matriz[][TAM],int orden);
int sumaElementosAbajoSinDS (int matriz[][TAM],int orden);

int sumaDP (int matriz[][TAM],int orden);
int sumaElementosAbajoDP (int matriz[][TAM],int orden);
int sumaElementosAbajoSinDP (int matriz[][TAM],int orden);
int sumaElementosArribaDP (int matriz[][TAM],int orden);
int sumaElementosArribaSinDP (int matriz[][TAM],int orden);

int esDiagonal (int matriz[][TAM], int filas, int columnas);
int esIdentidad (int matriz[][TAM], int filas, int columnas);
int esSimetrica (int matriz[][TAM], int filas, int columnas);
void trasponerMatriz (int matriz[][TAM], int orden);
void copiarYTrasponerMatriz (int matriz[][TAM], int auxMatriz[][TAM],int orden);
void productoMatrices (int matriz1[][TAM],int fila1, int columna1,int matriz2[][TAM],int fila2,int columna2);

void* reservarMemMatriz(int fila, int columna, size_t tamanio);
void liberarMatriz(void** matriz, int fila);

int trasponerRespectoDS (int matriz[][TAM], int fila, int columna);

#endif // MATRIZ_H_INCLUDED
