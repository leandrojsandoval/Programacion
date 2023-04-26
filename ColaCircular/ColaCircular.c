#include "ColaCircular.h"

void crearCola (Cola* pc)
{
    *pc = NULL;
}

bool colaVacia (const Cola* pc)
{
    return !*pc;
}

bool colaLlena (const Cola* pc, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nue);
    free(elem);
    return !nue || !elem;
}

bool encolar (Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);
    if(!nue)
        return false;
    if(*pc)
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }
    else
        nue->sig = nue;
    *pc = nue;
    return true;
}

bool desencolar (Cola* pc, void* elem, size_t tamElem)
{
    if(!*pc)
        return false;
    Nodo* nae = (*pc)->sig;
    if(*pc == nae)
        *pc = NULL;
    else
        (*pc)->sig = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

void vaciarCola (Cola* pc)
{
    Nodo* nae;
    while(*pc)
    {
        nae = (*pc)->sig;
        if(nae == nae->sig)
            *pc = NULL;
        else
            (*pc)->sig = nae->sig;
        free(nae->elem);
        free(nae);
    }
}

bool frenteDeCola (const Cola* pc, void* elem, size_t tamElem)
{
    if(!*pc)
        return false;
    Nodo* frente = (*pc)->sig;
    memcpy(elem, frente->elem, MINIMO(tamElem, frente->tamElem));
    return true;
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

void destruirNodo (Nodo* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, MINIMO(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}
