#include "Ocurrencia.h"

/*********************************** Ocurrencias de caracteres ***********************************/

int cmpOcurrenciasLetra(const void* info1, const void* info2) {
    const OcurrenciasLetra* i1 = (const OcurrenciasLetra*)info1;
    const OcurrenciasLetra* i2 = (const OcurrenciasLetra*)info2;
    int res = i1->letra - i2->letra;
    return res ? res : i1->contador - i2->contador;
}

void cargarCadenaEnVectorOcurrenciasLetra(OcurrenciasLetra* vector, int* cantElem, int capacidad, const char* s) {
    *cantElem = 0;
    while (*s && *cantElem < capacidad) {
        if (ES_LETRA(*s))
            insertarLetrasSinDuplicados(vector, MI_TOLOWER(toSinTilde(*s)), cantElem, capacidad);
        s++;
    }
}

void insertarLetrasSinDuplicados(OcurrenciasLetra* vector, char dato, int* cantElem, int capacidad) {
    if (*cantElem > capacidad)
        return;
    int cont = 0;
    while (cont < *cantElem && vector->letra != dato) {
        vector++;
        cont++;
    }
    if (vector->letra != dato || cont > *cantElem) {
        vector->letra = dato;
        vector->contador = 1;
        (*cantElem)++;
    } else
        vector->contador++;
}

void mostrarOcurrenciasLetra(const void* vector) {
    const OcurrenciasLetra* vec = (const OcurrenciasLetra*)vector;
    printf("[%c | %d]\n", vec->letra, vec->contador);
}

/*********************************** Ocurrencias de palabras ***********************************/

void insertarPalabrasSinDuplicados(OcurrenciasPalabra* vector, Palabra* pal, int* cantElem, int capacidad) {
    if (*cantElem > capacidad)
        return;
    int cont = 0;
    int res;
    char* copiaPal = PalToStr(pal);
    while (cont < *cantElem && (res = miStrcmpi(vector->palabra, copiaPal))) {
        vector++;
        cont++;
    }
    if (res || cont > *cantElem) {
        miStrcpy(vector->palabra, copiaPal);
        vector->contador = 1;
        (*cantElem)++;
    } else {
        vector->contador++;
    }
    free(copiaPal);
}

void cargarCadenaEnVectorOcurrenciasPalabra(OcurrenciasPalabra* vector, int* cantElem, int capacidad, const char* s) {
    *cantElem = 0;

    SecuenciaPalabras secLect;
    crearSecuenciaPalabras(&secLect, s);

    Palabra pal;

    while (leerPalabra(&secLect, &pal) && *cantElem < capacidad)
        insertarPalabrasSinDuplicados(vector, &pal, cantElem, capacidad);
}

void mostrarOcurrenciasPalabras(const void* vector) {
    const OcurrenciasPalabra* vec = (const OcurrenciasPalabra*)vector;
    printf("[%15s | %5d]\n", vec->palabra, vec->contador);
}

int cmpOcurrenciasPalabra(const void* info1, const void* info2) {
    const OcurrenciasPalabra* i1 = (const OcurrenciasPalabra*)info1;
    const OcurrenciasPalabra* i2 = (const OcurrenciasPalabra*)info2;
    return i1->contador - i2->contador;
}
