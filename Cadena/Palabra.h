#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED

#include "Cadena.h"

typedef struct
{
    char* cursor;
    bool finSec;
} SecuenciaPalabras;

typedef struct
{
    char* ini;
    char* fin;
} Palabra;

void crearSecuenciaPalabras (SecuenciaPalabras* sec, const char* cad);
bool leerPalabra (SecuenciaPalabras* sec, Palabra* pal);

void escribirPalabra (SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabraPrimeraMayuscula (SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabraMinuscula (SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabraMayuscula (SecuenciaPalabras* sec, Palabra* pal);
void escribirCaracter (SecuenciaPalabras* sec, char caracter);

void reposicionarCursor (SecuenciaPalabras* sec, int desplazamiento);
void cerrarSecuenciaPalabras (SecuenciaPalabras* sec);

int miStrlenPal (const Palabra* pal);
char* PalToStr (Palabra* pal);

#endif // PALABRA_H_INCLUDED
