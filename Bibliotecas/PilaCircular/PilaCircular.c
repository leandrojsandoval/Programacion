#include "PilaCircular.h"

void crearPila(Pila* pp) {
    *pp = NULL;
}

bool pilaLlena(const Pila* pp, size_t tamElem) {
    void* nue = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nue);
    free(elem);
    return !nue || !elem;
}

bool pilaVacia(const Pila* pp) {
    return !*pp;
}

bool apilar(Pila* pp, const void* elem, size_t tamElem) {
    Nodo* nue = crearNodo(elem, tamElem);
    if (!nue)
        return false;
    if (*pp)
        nue->sig = (*pp)->sig;
    else
        *pp = nue;
    (*pp)->sig = nue;
    return true;
}

bool desapilar(Pila* pp, void* elem, size_t tamElem) {
    if (!*pp)
        return false;
    Nodo* nae;
    if (*pp == (*pp)->sig) {
        nae = *pp;
        *pp = NULL;
    } else {
        nae = (*pp)->sig;
        (*pp)->sig = nae->sig;
    }
    destruirNodo(nae, elem, tamElem);
    return true;
}

void vaciarPila(Pila* pp) {
    Nodo* nae;
    while (*pp) {
        Nodo* nae = (*pp)->sig;
        if (nae->sig == nae)
            *pp = NULL;
        else
            (*pp)->sig = nae->sig;
        free(nae->elem);
        free(nae);
    }
}

bool verTope(const Pila* pp, void* elem, size_t tamElem) {
    if (!*pp)
        return false;
    Nodo* tope = (*pp)->sig;
    memcpy(elem, tope->elem, MINIMO(tamElem, tope->tamElem));
    return true;
}

Nodo* crearNodo(const void* elem, size_t tamElem) {
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);
    if (!nue || !elemNodo) {
        free(nue);
        free(elemNodo);
        return NULL;
    }
    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = NULL;
    return nue;
}

void destruirNodo(Nodo* nae, void* elem, size_t tamElem) {
    memcpy(elem, nae->elem, MINIMO(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}
