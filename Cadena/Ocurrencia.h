#ifndef OCURRENCIA_H_INCLUDED
#define OCURRENCIA_H_INCLUDED

#include "Cadena.h"

typedef struct
{
    char letra;
    int contador;
} OcurrenciasLetra;

typedef struct
{
    char palabra[100];
    int contador;
} OcurrenciasPalabra;

/************************************ Ocurrencias de caracteres ************************************/

void cargarCadenaEnVectorOcurrenciasLetra (OcurrenciasLetra* vector, int* cantElem, int capacidad, const char* s);
void insertarLetrasSinDuplicados (OcurrenciasLetra* vector, char dato, int* cantElem, int capacidad);
void mostrarOcurrenciasLetra (const void* vector);
int cmpOcurrenciasLetra (const void* info1, const void* info2);

/************************************ Ocurrencias de palabras ************************************/

void cargarCadenaEnVectorOcurrenciasPalabra (OcurrenciasPalabra* vector, int* cantElem, int capacidad, const char* s);
//void insertarPalabrasSinDuplicados (OcurrenciasPalabra* vector, Palabra* pal, int* cantElem, int capacidad);  ///Preguntar
void mostrarOcurrenciasPalabras (const void* vector);
int cmpOcurrenciasPalabra (const void* info1, const void* info2);

#endif // OCURRENCIA_H_INCLUDED
