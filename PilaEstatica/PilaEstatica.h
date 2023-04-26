#ifndef TDAPILAESTATICA_H_INCLUDED
#define TDAPILAESTATICA_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_PILA 1000
#define MINIMO(X,Y) ((X) > (Y) ? (Y) : (X))

typedef struct
{
    char vPila[TAM_PILA];
    unsigned tope;
} Pila;

void crearPila (Pila* pp);
bool pilaLlena (const Pila* pp, size_t tamElem);
bool pilaVacia (const Pila* pp);
bool apilar (Pila* pp, const void* elem, size_t tamElem);
bool desapilar (Pila* pp, void* elem, size_t tamElem);
bool verTopeDePila (const Pila* pp, void* elem, size_t tamElem);
void vaciarPila (Pila* pp);

#endif // TDAPILAESTATICA_H_INCLUDED
