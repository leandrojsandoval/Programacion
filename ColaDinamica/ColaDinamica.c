#include "ColaDinamica.h"

void crearCola (Cola* pc)
{
    pc->frente = pc->fondo = NULL;
}

bool encolar (Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);
    if(!nue)
        return false;
    if(pc->fondo)
        pc->fondo->sig = nue;
    else
        pc->frente = nue;
    pc->fondo = nue;
    return true;
}

bool desencolar (Cola* pc, void* elem, size_t tamElem)
{
    if(!pc->frente)
        return false;
    Nodo* nae = pc->frente;
    pc->frente = nae->sig;
    if(!pc->frente)
        pc->fondo = NULL;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool frenteDeCola (const Cola* pc, void* elem, size_t tamElem)
{
    if(!pc->frente)
        return false;
    Nodo* frente = pc->frente;
    memcpy(elem, frente->elem, MINIMO(tamElem, frente->tamElem));
    return true;
}

void vaciarCola (Cola* pc)
{
    Nodo* nae;
    Nodo* frente = pc->frente;
    while(pc->frente)
    {
        nae = frente;
        frente = nae->sig;
        free(nae->elem);
        free(nae);
    }
    pc->frente = pc->fondo = NULL;
}

bool colaVacia (const Cola* pc)
{
    return !pc->frente;
}

bool colaLlena (const Cola* pc, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nue);
    free(elem);
    return !nue || !elem;
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
