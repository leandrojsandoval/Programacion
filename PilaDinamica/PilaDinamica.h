#ifndef TDAPILADINAMICA_H_INCLUDED
#define TDAPILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MINIMO(X,Y) ((X)>(Y)? (Y) : (X))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Pila;

void crearPila (Pila* pp);
bool pilaVacia (const Pila* pp);
bool pilaLlena (const Pila* pp, size_t tamElem);
bool apilar (Pila* pp, const void* elem, size_t tamElem);
bool desapilar (Pila* pp, void* elem, size_t tamElem);
bool verTope (const Pila* pp, void* elem, size_t tamElem);
void vaciarPila (Pila* pp);

Nodo* crearNodo (const void* elem, size_t tamElem);
void destruirNodo (Nodo* nae, void* elem, size_t tamElem);

#endif // TDAPILADINAMICA_H_INCLUDED
