#include "ListaDoble.h"

void crearLista(Lista* pl) {
    *pl = NULL;
}

bool listaLlena(const Lista* pl, size_t tamElem) {
    void* nue = malloc(sizeof(NodoD));
    void* elem = malloc(tamElem);
    free(nue);
    free(elem);
    return !nue || !elem;
}

bool listaVacia(const Lista* pl) {
    return !*pl;
}

bool insertarPrimeroEnLista(Lista* pl, const void* elem, size_t tamElem) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    while (anterior) {
        siguiente = anterior;
        anterior = anterior->ant;
    }
    NodoD* nue = crearNodoDoble(elem, tamElem);
    if (!nue)
        return false;
    nue->sig = siguiente;
    nue->ant = NULL;
    if (siguiente)
        siguiente->ant = nue;
    *pl = nue;
    return true;
}

bool insertarUltimoEnLista(Lista* pl, const void* elem, size_t tamElem) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    while (siguiente) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }
    NodoD* nue = crearNodoDoble(elem, tamElem);
    if (!nue)
        return false;
    nue->ant = anterior;
    nue->sig = NULL;
    if (anterior)
        anterior->sig = nue;
    *pl = nue;
    return true;
}

int insertarOActualizarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    while (anterior && cmp(elem, anterior->elem) < 0) {
        siguiente = anterior;
        anterior = anterior->ant;
    }
    while (siguiente && cmp(elem, siguiente->elem) > 0) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }
    if ((anterior && !cmp(elem, anterior->elem)) || (siguiente && !cmp(elem, siguiente->elem))) {
        if (actualizar)
            actualizar(anterior && !cmp(elem, anterior->elem) ? anterior->elem : siguiente->elem, elem);
        return DUPLICADO;
    }
    NodoD* nue = crearNodoDoble(elem, tamElem);
    if (!nue)
        return SIN_MEMORIA;
    nue->ant = anterior;
    nue->sig = siguiente;
    if (anterior)
        anterior->sig = nue;
    if (siguiente)
        siguiente->ant = nue;
    *pl = nue;
    return TODO_OK;
}

bool buscarElementoEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;

    while (anterior && cmp(elem, anterior->elem) < 0) {
        siguiente = anterior;
        anterior = anterior->ant;
    }

    while (siguiente && cmp(elem, siguiente->elem) > 0) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }

    if ((!anterior || cmp(elem, anterior->elem)) && (!siguiente || cmp(elem, siguiente->elem)))
        return false;

    memcpy(elem, anterior && !cmp(elem, anterior->elem) ? anterior->elem : siguiente->elem,
           MINIMO(tamElem, anterior && !cmp(elem, anterior->elem) ? anterior->tamElem : siguiente->tamElem));
    return true;
}

bool eliminarPrimeroDeLista(Lista* pl, void* elem, size_t tamElem) {
    if (!*pl)
        return false;

    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente;

    while (anterior) {
        siguiente = anterior;
        anterior = anterior->ant;
    }

    NodoD* nae = siguiente;

    /*Entra por aca si NO es el ultimo elemento: El segundo elemento de la lista
    paso a ser el primero, por lo tanto, su anterior tiene que apuntar a NULL*/
    if (nae->sig)
        nae->sig->ant = NULL;

    /*Por convencion dejamos apuntando pl al nodo que se acaba de eliminar, en este
    caso, queda apuntando al primer elemento de la lista. Se le asigna NULL cuando
    se elimino el unico nodo que habia y por lo tanto la lista quedara vacia*/
    *pl = nae->sig ? nae->sig : NULL;

    destruirNodoDoble(nae, elem, tamElem);

    return true;
}

bool eliminarUltimoDeLista(Lista* pl, void* elem, size_t tamElem) {
    if (!*pl)
        return false;

    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;

    while (siguiente) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }

    NodoD* nae = anterior;

    if (nae->ant)
        nae->ant->sig = NULL;

    *pl = nae->ant ? nae->ant : NULL;

    destruirNodoDoble(nae, elem, tamElem);

    return true;
}

bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp) {
    if (!*pl)
        return false;

    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;

    while (anterior && cmp(elem, anterior->elem) < 0) {
        siguiente = anterior;
        anterior = anterior->ant;
    }

    while (siguiente && cmp(elem, siguiente->elem) > 0) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }

    NodoD* nae;

    if (anterior && !cmp(elem, anterior->elem))
        nae = anterior;
    else if (siguiente && !cmp(elem, siguiente->elem))
        nae = siguiente;
    else
        return false;

    if (nae->ant)
        nae->ant->sig = nae->sig;

    if (nae->sig)
        nae->sig->ant = nae->ant;

    *pl = nae->ant ? nae->ant : nae->sig;

    destruirNodoDoble(nae, elem, tamElem);

    return TODO_OK;
}

bool eliminarDeListaDes(Lista* pl, void* elem, size_t tamElem, Cmp cmp) {
    if (!*pl)
        return false;

    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    NodoD* nae;

    while (anterior && cmp(elem, anterior->elem))
        anterior = anterior->ant;

    if (anterior && cmp(elem, anterior->elem) == 0)
        nae = anterior;
    else {
        while (siguiente && cmp(elem, siguiente->elem))
            siguiente = siguiente->sig;

        if (siguiente && cmp(elem, siguiente->elem) == 0)
            nae = siguiente;
        else
            return false;
    }

    if (nae->ant)
        nae->ant->sig = nae->sig;

    if (nae->sig)
        nae->sig->ant = nae->ant;

    *pl = nae->ant ? nae->ant : nae->sig;

    destruirNodoDoble(nae, elem, tamElem);

    return true;
}

bool eliminarYOActualizarDuplicadosDeListaOrd(Lista* pl, Cmp cmp, Actualizar actualizar) {
    if (!*pl)
        return false;

    NodoD* nae;

    while ((*pl)->ant)
        *pl = (*pl)->ant;

    Lista* plDup = &(*pl)->sig;

    while (*pl) {
        while (*plDup && !cmp((*pl)->elem, (*plDup)->elem)) {
            if (actualizar)
                actualizar((*pl)->elem, (*plDup)->elem);

            nae = *plDup;

            if (nae->ant)
                nae->ant->sig = nae->sig;

            if (nae->sig)
                nae->sig->ant = nae->ant;

            free(nae->elem);
            free(nae);
        }
        pl = &(*pl)->sig;
        plDup = &(*pl)->sig;
    }
    return true;
}

bool eliminarYOActualizarDuplicadosDeListaDes(Lista* pl, Cmp cmp, Actualizar actualizar) {
    if (!*pl)
        return false;
    NodoD* nae;
    while ((*pl)->ant)
        *pl = (*pl)->ant;
    Lista* plDup = &(*pl)->sig;
    while (*pl) {
        while (*plDup) {
            if (!cmp((*pl)->elem, (*plDup)->elem)) {
                if (actualizar)
                    actualizar((*pl)->elem, (*plDup)->elem);

                nae = *plDup;

                if (nae->ant)
                    nae->ant->sig = nae->sig;

                if (nae->sig)
                    nae->sig->ant = nae->ant;

                free(nae->elem);
                free(nae);
            } else
                plDup = &(*plDup)->sig;
        }
        pl = &(*pl)->sig;
        plDup = &(*pl)->sig;
    }
    return true;
}

void recorrerListaDeIzqADer(Lista* pl, Accion accion, void* datosAccion) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    while (anterior) {
        siguiente = anterior;
        anterior = anterior->ant;
    }
    while (siguiente) {
        accion(siguiente->elem, datosAccion);
        anterior = siguiente;
        siguiente = siguiente->sig;
    }
}

void recorrerListaDeDerAIzq(Lista* pl, Accion accion, void* datosAccion) {
    NodoD* siguiente = *pl;
    NodoD* anterior = siguiente ? siguiente->ant : NULL;
    while (siguiente) {
        anterior = siguiente;
        siguiente = siguiente->sig;
    }
    while (anterior) {
        accion(anterior->elem, datosAccion);
        siguiente = anterior;
        anterior = anterior->ant;
    }
}

void vaciarLista(Lista* pl) {
    if (!*pl)
        return;
    NodoD* nae;
    while ((*pl)->ant)
        *pl = (*pl)->ant;
    while (*pl) {
        nae = *pl;
        *pl = nae->sig;
        free(nae->elem);
        free(nae);
    }
    *pl = NULL;
}

void ordenarLista(Lista* pl, Cmp cmp, int sentidoOrdenamiento) {
    Lista lOrd = NULL;
    Lista* plOrd;
    NodoD* nodo;
    while ((*pl)->ant)
        *pl = (*pl)->ant;
    while (*pl) {
        nodo = *pl;
        *pl = nodo->sig;

        plOrd = &lOrd;
        while (*plOrd && (sentidoOrdenamiento * cmp(nodo->elem, (*plOrd)->elem)) >= 0)
            plOrd = &(*plOrd)->sig;

        nodo->sig = *plOrd;
        nodo->ant = *plOrd ? (*plOrd)->ant : NULL;

        *plOrd = nodo;
    }
    *pl = lOrd;
}

NodoD* crearNodoDoble(const void* elem, size_t tamElem) {
    NodoD* nue = (NodoD*)malloc(sizeof(NodoD));
    void* elemNodo = malloc(tamElem);
    if (!nue || !elemNodo) {
        free(nue);
        free(elemNodo);
        return NULL;
    }
    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->ant = nue->sig = NULL;
    return nue;
}

void destruirNodoDoble(NodoD* nae, void* elem, size_t tamElem) {
    memcpy(elem, nae->elem, MINIMO(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}
