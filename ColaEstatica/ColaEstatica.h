#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MINIMO(X,Y) ((X)>(Y)? (Y) : (X))
#define TAM_COLA 5000

typedef struct
{
    char vCola[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisponible;
} Cola;

void crearCola (Cola* pc);
bool encolar (Cola* pc, const void* elem, size_t tamElem);
bool desencolar (Cola* pc, void* elem, size_t tamElem);
bool frenteDeCola (const Cola* pc, void* elem, size_t tamElem);
bool colaVacia (const Cola* pc);
bool colaLlena (const Cola* pc, size_t tamElem);
void vaciarCola (Cola* pc);

void copiarDatoEnCola (Cola* pc, const void* dato, size_t tamDato);
void copiarDatoDeCola (Cola* pc, void* dato, size_t tamDato);

#endif // COLAESTATICA_H_INCLUDED
