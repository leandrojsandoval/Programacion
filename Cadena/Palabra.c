#include "Palabra.h"

void crearSecuenciaPalabras (SecuenciaPalabras* sec, const char* cad)
{
    sec->cursor = (char*)cad;
    sec->finSec = false;
}

bool leerPalabra (SecuenciaPalabras* sec, Palabra* pal)
{
    char* actual = sec->cursor;
    while(*actual && !ES_LETRA(*actual))
        actual++;
    if(!*actual)
    {
        sec->finSec = true;
        return false;
    }
    pal->ini = actual;
    while(*actual && ES_LETRA(*actual))
        actual++;
    pal->fin = actual - 1;
    sec->cursor = actual;
    return true;
}

void escribirPalabra (SecuenciaPalabras* sec, Palabra* pal)
{
    char* dest = sec->cursor;
    for(char* orig= pal->ini; orig <= pal->fin; orig++, dest++)
        *dest = *orig;
    sec->cursor = dest;
}

void escribirPalabraPrimeraMayuscula (SecuenciaPalabras* sec, Palabra* pal)
{
    char* dest = sec->cursor;
    *dest = MI_TOUPPER(*pal->ini);
    dest++;
    for(char* orig = pal->ini + 1; orig <= pal->fin; orig++, dest++)
        *dest = MI_TOLOWER(*orig);
    sec->cursor = dest;
}

void escribirPalabraMinuscula (SecuenciaPalabras* sec, Palabra* pal)
{
    char* dest = sec->cursor;
    for(char* orig = pal->ini; orig <= pal->fin; orig++, dest++)
        *dest = MI_TOLOWER(*orig);
    sec->cursor = dest;
}

void escribirPalabraMayuscula (SecuenciaPalabras* sec, Palabra* pal)
{
    char* dest = sec->cursor;
    for(char* orig = pal->ini; orig <= pal->fin; orig++, dest++)
        *dest = MI_TOUPPER(*orig);
    sec->cursor = dest;
}

void escribirCaracter (SecuenciaPalabras* sec, char caracter)
{
    *sec->cursor = caracter;
    sec->cursor++;
}

void cerrarSecuenciaPalabras (SecuenciaPalabras* sec)
{
    *sec->cursor = '\0';
}

void reposicionarCursor (SecuenciaPalabras* sec, int desplazamiento)
{
    sec->cursor += desplazamiento;
}

int miStrlenPal (const Palabra* pal)
{
    return pal->fin - pal->ini + 1;
}

char* PalToStr (Palabra* pal)
{
    char* copiaPal = (char*)malloc(miStrlenPal(pal) + 1);
    SecuenciaPalabras secEscr;
    crearSecuenciaPalabras(&secEscr, copiaPal);
    escribirPalabra(&secEscr, pal);
    cerrarSecuenciaPalabras(&secEscr);
    return copiaPal;
}

