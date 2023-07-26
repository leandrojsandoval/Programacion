#include "Generico.h"

void ordenamientoSeleccionAscendente(void* vector, int ce, size_t tamElem, Cmp cmp) {
    void* dirMenor;
    void* ult = vector + (ce - 1) * tamElem;
    for (void* i = vector; i < ult; i += tamElem) {
        dirMenor = buscarDirMenor(i, ult, tamElem, cmp);
        if (dirMenor != i)
            intercambiarInformacion(dirMenor, i, tamElem);
    }
}

void* buscarDirMenor(void* inicio, void* fin, size_t tamElem, Cmp cmp) {
    void* dirMenor = inicio;
    for (void* actual = inicio + tamElem; actual <= fin; actual += tamElem) {
        if (cmp(actual, dirMenor) < 0) {
            dirMenor = actual;
        }
    }
    return dirMenor;
}

void intercambiarInformacion(void* info1, void* info2, size_t tamElem) {
    void* temp = malloc(tamElem);
    memcpy(temp, info1, tamElem);
    memcpy(info1, info2, tamElem);
    memcpy(info2, temp, tamElem);
    free(temp);
}

void mostrarVector(const void* vector, int ce, size_t tamElem, Mostrar mostrar) {
    const void* ult = vector + (ce - 1) * tamElem;
    for (const void* i = vector; i <= ult; i += tamElem) {
        mostrar(i);
    }
    putchar('\n');
}

void ordenamientoSeleccionDescendente(void* vector, int ce, size_t tamElem, Cmp cmp) {
    void* dirMayor;
    void* ult = vector + (ce - 1) * tamElem;
    for (void* i = vector; i < ult; i += tamElem) {
        dirMayor = buscarDirMayor(i, ult, tamElem, cmp);
        if (dirMayor != i)
            intercambiarInformacion(dirMayor, i, tamElem);
    }
}

void* buscarDirMayor(void* inicio, void* fin, size_t tamElem, Cmp cmp) {
    void* dirMayor = inicio;
    for (void* actual = inicio + tamElem; actual <= fin; actual += tamElem) {
        if (cmp(actual, dirMayor) > 0) {
            dirMayor = actual;
        }
    }
    return dirMayor;
}

/*************************** Funciones de ordenamiento ***************************/

void ordenamientoInsercionAscendente(void* vector, int ce, size_t tamElem, Cmp cmp) {
    void* dirIni = vector;
    const void* dirFin = dirIni + (ce - 1) * tamElem;
    while (vector < dirFin) {
        void* dirSig = vector + tamElem;
        void* datoAInsertar = malloc(tamElem);
        if (!datoAInsertar)
            return;
        memcpy(datoAInsertar, dirSig, tamElem);
        insertarYDesplazarAscendente(dirIni, vector, tamElem, dirSig, datoAInsertar, cmp);
        free(datoAInsertar);
        vector += tamElem;
    }
}

void insertarYDesplazarAscendente(void* dirIni, void* vector, size_t tamElem, void* dirSig, void* dato, Cmp cmp) {
    while (dirIni <= vector && cmp(vector, dato) > 0) {
        memcpy(dirSig, vector, tamElem);
        dirSig -= tamElem;
        vector -= tamElem;
    }
    memcpy(vector < dirIni ? dirIni : vector + tamElem, dato, tamElem);
}
