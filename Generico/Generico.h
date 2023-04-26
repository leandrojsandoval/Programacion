#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*Cmp)(const void*, const void*);
typedef void(*Mostrar)(const void*);

void ordenamientoSeleccionAscendente (void* vector, int ce, size_t tamElem, Cmp cmp);
void ordenamientoSeleccionDescendente (void* vector, int ce, size_t tamElem, Cmp cmp);

void* buscarDirMenor (void* inicio, void* fin, size_t tamElem, Cmp cmp);
void* buscarDirMayor (void* inicio, void* fin, size_t tamElem, Cmp cmp);

void intercambiarInformacion (void* info1, void* info2, size_t tamElem);

void mostrarVector (const void* vector, int ce, size_t tamElem, Mostrar mostrar);

void ordenamientoInsercionAscendente (void* vector, int ce, size_t tamElem, Cmp cmp);
void insertarYDesplazarAscendente (void* dirIni, void* vector, size_t tamElem, void* dirSig, void* dato, Cmp cmp);

#endif // GENERICO_H_INCLUDED
