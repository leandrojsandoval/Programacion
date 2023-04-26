#include "Lista.h"

void crearLista (Lista* pl)
{
    *pl = NULL;
}

bool listaLlena (const Lista* pl, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);
    free(nue);
    free(elem);
    return !nue || !elem;
}

bool listaVacia (const Lista* pl)
{
    return !*pl;
}

bool insertarPrimeroEnLista (Lista* pl, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);
    if(!nue)
        return false;
    nue->sig = *pl;
    *pl = nue;
    return true;
}

bool insertarUltimoEnLista(Lista* pl, const void* elem, size_t tamElem)
{
    while(*pl)
        pl = &(*pl)->sig;
    Nodo* nue = crearNodo(elem, tamElem);
    if(!nue)
        return false;
    *pl = nue;
    return true;
}

int insertarOActualizarEnListaOrd (Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
    {
        if(actualizar)
            actualizar((*pl)->elem, elem);
        return DUPLICADO;
    }

    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return SIN_MEMORIA;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}

bool eliminarPrimeroDeLista (Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return false;
    Nodo* nae = *pl;
    *pl = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool eliminarUltimoDeLista (Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return false;
    while(*pl)
        pl = &(*pl)->sig;
    Nodo* nae = *pl;
    *pl = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool eliminarDeListaOrd (Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;
    if(!*pl || cmp(elem, (*pl)->elem) < 0)
        return false;
    Nodo* nae = *pl;
    *pl = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool eliminarDeListaDes (Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) != 0)
        pl = &(*pl)->sig;
    if(!*pl)
        return false;
    Nodo* nae = *pl;
    *pl = nae->sig;
    destruirNodo(nae, elem, tamElem);
    return true;
}

bool eliminarDuplicadosDeListaOrd (Lista* pl, Cmp cmp)
{
    if(!*pl)
        return false;
    Nodo* nae;

    Lista* plDup = &(*pl)->sig;

    while(*pl)
    {
        while(*plDup && !cmp((*pl)->elem, (*plDup)->elem))
        {
            nae = *plDup;
            *plDup = nae->sig;
            free(nae->elem);
            free(nae);
        }
        pl = &(*pl)->sig;
        plDup = &(*pl)->sig;
    }

    return true;
}

bool eliminarDuplicadosDeListaDes (Lista* pl, Cmp cmp)
{
    if(!*pl)
        return false;

    Nodo* nae;

    Lista* plDup = &(*pl)->sig;
    while(*pl)
    {
        while(*plDup)
        {
            if(!cmp((*pl)->elem, (*plDup)->elem))
            {
                nae = *plDup;
                *plDup = nae->sig;
                free(nae->elem);
                free(nae);
            }
            else
                plDup = &(*plDup)->sig;
        }
        pl = &(*pl)->sig;
        plDup = &(*pl)->sig;
    }

    return true;
}

bool buscarElementoEnLista (Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && (cmp(elem, (*pl)->elem)) != 0)
        pl = &(*pl)->sig;
    if(!*pl)
        return false;
    memcpy(elem, (*pl)->elem, MINIMO(tamElem, (*pl)->tamElem));
    return true;
}

void vaciarLista (Lista* pl)
{
    Nodo* nae;
    while(*pl)
    {
        nae = *pl;
        *pl = nae->sig;
        free(nae->elem);
        free(nae);
    }
}

void recorrerLista (const Lista* pl, Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion((*pl)->elem, datosAccion);
        pl = &(*pl)->sig;
    }
}

void ordenarLista (Lista* pl, Cmp cmp, int sentidoOrdenamiento)
{
    Lista lOrd = NULL;
    Lista* plOrd = &lOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo = *pl;
        *pl = nodo->sig;

        plOrd = &lOrd;

        while(*plOrd && (sentidoOrdenamiento * cmp(nodo->elem, (*plOrd)->elem)) >= 0)
            plOrd = &(*plOrd)->sig;

        nodo->sig = *plOrd;
        *plOrd = nodo;
    }

    *pl = lOrd;
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
