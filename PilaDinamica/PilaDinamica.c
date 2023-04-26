#include "PilaDinamica.h"

void crearPila (Pila* pp)
{
    *pp = NULL;
}

bool pilaVacia (const Pila* pp)
{
    return *pp == NULL;
}

bool pilaLlena (const Pila* pp, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nodo);
    free(elem);
    return !nodo || !elem;
}

bool apilar (Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);
    if(!nue)
        return false;
    nue->sig = *pp;
    *pp = nue;
    return true;
}

bool desapilar (Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return false;
    Nodo* nae = *pp;
    *pp = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool verTope (const Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return false;
    Nodo* tope = *pp;
    memcpy(elem, tope->elem, MINIMO(tamElem, tope->tamElem));
    return true;
}

void vaciarPila (Pila* pp)
{
    Nodo* nae;
    while(*pp)
    {
        nae = *pp;
        *pp = nae->sig;
        free(nae->elem);
        free(nae);
    }
}

void destruirNodo (Nodo* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, MINIMO(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}

Nodo* crearNodo (const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);
    if(!nue || !elemNodo)
    {
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
