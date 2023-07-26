#include "ColaEstatica.h"

void crearCola(Cola* pc) {
    pc->fondo = pc->frente = 0;
    pc->tamDisponible = TAM_COLA;
}

bool encolar(Cola* pc, const void* elem, size_t tamElem) {
    if (tamElem + sizeof(size_t) > pc->tamDisponible)
        return false;
    copiarDatoEnCola(pc, &tamElem, sizeof(size_t));
    copiarDatoEnCola(pc, elem, tamElem);
    pc->tamDisponible -= tamElem + sizeof(size_t);
    return true;
}

bool desencolar(Cola* pc, void* elem, size_t tamElem) {
    if (pc->tamDisponible == TAM_COLA)
        return false;
    size_t tamElemEncolado;
    copiarDatoDeCola(pc, &tamElemEncolado, sizeof(size_t));
    copiarDatoDeCola(pc, elem, MINIMO(tamElem, tamElemEncolado));
    pc->frente += tamElemEncolado - MINIMO(tamElem, tamElemEncolado);
    pc->tamDisponible += tamElemEncolado + sizeof(size_t);
    return true;
}

bool frenteDeCola(const Cola* pc, void* elem, size_t tamElem) {
    if (pc->tamDisponible == TAM_COLA)
        return false;
    unsigned frente = pc->frente;
    size_t tamElemEncolado;
    copiarDatoDeCola((Cola*)pc, &tamElemEncolado, sizeof(size_t));
    copiarDatoDeCola((Cola*)pc, elem, MINIMO(tamElem, tamElemEncolado));
    ((Cola*)pc)->frente = frente;
    return true;
}

bool colaVacia(const Cola* pc) {
    return pc->tamDisponible == TAM_COLA;
}

bool colaLlena(const Cola* pc, size_t tamElem) {
    return tamElem + sizeof(size_t) > pc->tamDisponible;
}

void vaciarCola(Cola* pc) {
    pc->fondo = pc->frente = 0;
    pc->tamDisponible = TAM_COLA;
}

void copiarDatoEnCola(Cola* pc, const void* dato, size_t tamDato) {
    unsigned tamDispContiguo = pc->frente <= pc->fondo ? TAM_COLA - pc->fondo : pc->frente - pc->fondo;
    unsigned cantACopiar = MINIMO(tamDato, tamDispContiguo);
    memcpy(pc->vCola + pc->fondo, dato, cantACopiar);
    unsigned restoACopiar = tamDato - cantACopiar;
    if (restoACopiar > 0)
        memcpy(pc->vCola, dato + cantACopiar, restoACopiar);
    pc->fondo = (pc->fondo + tamDato) % TAM_COLA;
}

void copiarDatoDeCola(Cola* pc, void* dato, size_t tamDato) {
    size_t tamDatoContiguo = pc->frente > pc->fondo ? MINIMO(tamDato, TAM_COLA - pc->frente) : tamDato;
    memcpy(dato, pc->vCola + pc->frente, tamDatoContiguo);
    size_t cantACopiar = tamDato - tamDatoContiguo;
    if (cantACopiar > 0)
        memcpy(dato + tamDatoContiguo, pc->vCola, cantACopiar);
    pc->frente = (pc->frente + tamDato) % TAM_COLA;
}
