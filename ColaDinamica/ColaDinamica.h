#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ((X) > (Y) ? (Y) : (X))

typedef struct sNodo {
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef struct
{
    Nodo* frente;
    Nodo* fondo;
} Cola;

void crearCola(Cola* pc);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc, size_t tamElem);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool frenteDeCola(const Cola* pc, void* elem, size_t tamElem);
void vaciarCola(Cola* pc);

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

#endif  // COLADINAMICA_H_INCLUDED
