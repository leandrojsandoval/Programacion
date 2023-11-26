#include "Arbol.h"

/******************************************** CARGAR ********************************************/

void crearArbol(Arbol* pa)
{
    *pa = NULL;
}

NodoA* crearNodo(const void* elem, size_t tamElem)
{
    NodoA* nue = (NodoA*)malloc(sizeof(NodoA));
    void* elemNodo = malloc(tamElem);
    if (!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }
    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->hDer = nue->hIzq = NULL;
    return nue;
}

int insertarOActualizarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    if (!*pa)
    {
        *pa = crearNodo(elem, tamElem);
        if (!*pa)
            return SIN_MEMORIA;
        return TODO_OK;
    }

    int comp = cmp(elem, (*pa)->elem);

    if (comp == 0)
    {
        if (actualizar)
            actualizar((*pa)->elem, elem);
        return DUPLICADO;
    }

    return insertarOActualizarEnArbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, tamElem, cmp, actualizar);
}

int cargarArchivoEnArbol(Arbol* pa, const char* nombreArchivo, size_t tamElem)
{
    if (*pa)
        return SIN_INICIALIZAR;
    FILE* arch = fopen(nombreArchivo, "rb");
    if (!arch)
        return ERROR_ARCHIVO;
    fseek(arch, 0L, SEEK_END);
    int cantReg = ftell(arch) / tamElem;
    cargarArbolDeArchivoOrdenado(pa, 0, cantReg - 1, tamElem, arch);
    fclose(arch);
    return TODO_OK;
}

int cargarArbolDeArchivoOrdenado(Arbol* pa, int limInf, int limSup, size_t tamElem, FILE* arch)
{
    if (limInf > limSup)
        return TODO_OK;
    int m = (limInf + limSup) / 2;
    fseek(arch, m * tamElem, SEEK_SET);
    *pa = crearNodo(arch, tamElem);
    fread((*pa)->elem, tamElem, 1, arch);
    if (!*pa)
        return SIN_MEMORIA;
    cargarArbolDeArchivoOrdenado(&(*pa)->hIzq, limInf, m - 1, tamElem, arch);
    cargarArbolDeArchivoOrdenado(&(*pa)->hDer, m + 1, limSup, tamElem, arch);
    return TODO_OK;
}

/******************************************** BUSQUEDA ********************************************/

bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    if (!*pa)
        return false;

    int comp = cmp(elem, (*pa)->elem);

    if (comp == 0)
    {
        memcpy(elem, (*pa)->elem, MINIMO(tamElem, (*pa)->tamElem));
        return true;
    }

    return buscarEnArbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, tamElem, cmp);
}

Arbol* buscarNodoEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    if (!*pa)
        return NULL;
    int comp = cmp(elem, (*pa)->elem);
    if (comp == 0)
        return (Arbol*)pa;
    return buscarNodoEnArbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, tamElem, cmp);
}

/******************************************** BUSQUEDA NO CLAVE ********************************************/

bool buscarElemNoClaveEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    const Arbol* busq = NULL;

    if (!*pa)
        return false;

    if (cmp(elem, (*pa)->elem) == 0)
        busq = pa;
    else if ((busq = buscarNodoNoClaveEnArbol(&(*pa)->hIzq, elem, cmp)) == NULL)
        busq = buscarNodoNoClaveEnArbol(&(*pa)->hDer, elem, cmp);

    if (busq == NULL)
        return 0;

    memcpy(elem, (*busq)->elem, MINIMO(tamElem, (*busq)->tamElem));
    return true;
}

const Arbol* buscarNodoNoClaveEnArbol(const Arbol* pa, const void* elem, Cmp cmp)
{
    const Arbol* busq = NULL;
    if (!*pa)
        return NULL;
    if (cmp((*pa)->elem, elem) == 0)
        return pa;
    if ((busq = buscarNodoNoClaveEnArbol(&(*pa)->hIzq, elem, cmp)))
        return busq;
    return buscarNodoNoClaveEnArbol(&(*pa)->hDer, elem, cmp);
}

/******************************************** RECORRIDOS ********************************************/

void recorrerArbolPre(Arbol* pa, Accion accion, void* datosAccion)
{
    if (!*pa)
        return;

    accion((*pa)->elem, datosAccion);
    recorrerArbolPre(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPre(&(*pa)->hDer, accion, datosAccion);
}

void recorrerArbolEn(Arbol* pa, Accion accion, void* datosAccion)
{
    if (!*pa)
        return;

    recorrerArbolEn(&(*pa)->hIzq, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
    recorrerArbolEn(&(*pa)->hDer, accion, datosAccion);
}

void recorrerArbolPos(Arbol* pa, Accion accion, void* datosAccion)
{
    if (!*pa)
        return;
    recorrerArbolPos(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPos(&(*pa)->hDer, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
}

/******************************************** IMPRIMIR ********************************************/

void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar)
{
    graficarArbolRec(pa, mostrar, 0);
}

void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel)
{
    if (!*pa)
        return;
    // Recorrida en orden inverso
    graficarArbolRec(&(*pa)->hDer, mostrar, nivel + 1);
    mostrar((*pa)->elem, nivel);
    graficarArbolRec(&(*pa)->hIzq, mostrar, nivel + 1);
}

/******************************************** ADMINISTRATIVOS ********************************************/

int alturaArbol(const Arbol* pa)
{
    if (!*pa)
        return 0;
    int alturaHIzq = alturaArbol(&(*pa)->hIzq);
    int alturaHDer = alturaArbol(&(*pa)->hDer);
    return MAXIMO(alturaHIzq, alturaHDer) + 1;
}

int contarElemArbol(const Arbol* pa)
{
    if (!*pa)
        return 0;
    return contarElemArbol(&(*pa)->hIzq) + contarElemArbol(&(*pa)->hDer) + 1;
}

int contarElemArbolHastaNivel(const Arbol* pa, int nivel)
{
    if (!*pa)
        return 0;
    if (nivel == 0)
        return 1;
    return contarElemArbolHastaNivel(&(*pa)->hIzq, nivel - 1) + contarElemArbolHastaNivel(&(*pa)->hDer, nivel - 1) + 1;
}

int contarHojasArbol(const Arbol* pa)
{
    if (!*pa)
        return 0;
    if (!(*pa)->hIzq && !(*pa)->hDer)
        return 1;
    return contarHojasArbol(&(*pa)->hIzq) + contarHojasArbol(&(*pa)->hDer);
}

bool esArbolCompleto(const Arbol* pa)
{
    int h = alturaArbol(pa);
    int cnc = pow(2, h) - 1;        // Cantidad de nodos calculados
    int cnr = contarElemArbol(pa);  // Cantidad de nodos reales
    return cnr == cnc;
}

int esCompletoHastaNivelArbol(const Arbol* pa, int nivel)
{
    if (!*pa)
        return nivel < 0;
    if (nivel == 0)
        return 1;
    return esCompletoHastaNivelArbol(&(*pa)->hIzq, nivel - 1) && esCompletoHastaNivelArbol(&(*pa)->hDer, nivel - 1);
}

bool esArbolAVL(const Arbol* pa)
{
    if (!*pa)
        return true;
    int hi = alturaArbol(&(*pa)->hIzq);
    int hd = alturaArbol(&(*pa)->hDer);
    if (abs(hi - hd) > 1)
        return false;
    return esArbolAVL(&(*pa)->hIzq) && esArbolAVL(&(*pa)->hIzq);
}

bool esArbolBalanceado(const Arbol* pa)
{
    int h = alturaArbol(pa);
    if (h <= 2)
        return true;
    int cnc = pow(2, h - 1) - 1;                     // Cantidad de nodos calculados
    int cnr = contarElemArbolHastaNivel(pa, h - 2);  // Cantidad de nodos reales
    return cnr == cnc;
}

/******************************************** ELIMINAR ********************************************/

void destruirNodo(NodoA* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, MINIMO(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}

bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    Arbol* pnae = buscarNodoEnArbol(pa, elem, tamElem, cmp);
    if (!pnae)
        return false;
    eliminarNodoDeArbol(pnae);
    return true;
}

bool eliminarElemNoClaveDeArbol(Arbol* pa, void* elem, Cmp cmp)
{
    if (!*pa)
        return false;

    eliminarElemNoClaveDeArbol(&(*pa)->hIzq, elem, cmp);
    eliminarElemNoClaveDeArbol(&(*pa)->hDer, elem, cmp);

    if (!cmp(elem, (*pa)->elem))
        eliminarNodoDeArbol(pa);
    return true;
}

void eliminarNodoDeArbol(Arbol* pnae)
{
    if (!(*pnae)->hIzq && !(*pnae)->hDer)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }
    int alturaHIzq = alturaArbol(&(*pnae)->hIzq);
    int alturaHDer = alturaArbol(&(*pnae)->hDer);
    Arbol* pnreempl = alturaHIzq >= alturaHDer ? mayorNodoDeArbol(&(*pnae)->hIzq) : menorNodoDeArbol(&(*pnae)->hDer);
    (*pnae)->elem = (*pnreempl)->elem;
    (*pnae)->tamElem = (*pnreempl)->tamElem;
    eliminarNodoDeArbol(pnreempl);
}

int podarArbol(Arbol* pa, int nivel)
{
    if (!*pa)
        return 0;
    if (nivel == 0)
        return vaciarArbol(pa);
    return podarArbol(&(*pa)->hIzq, nivel - 1) + podarArbol(&(*pa)->hDer, nivel - 1);
}

int vaciarArbol(Arbol* pa)
{
    if (!*pa)
        return 0;
    int cne = 0;
    cne += vaciarArbol(&(*pa)->hIzq);
    cne += vaciarArbol(&(*pa)->hDer);
    free((*pa)->elem);
    free(*pa);
    *pa = NULL;
    return cne + 1;
}

/******************************************** MAYOR ********************************************/

bool mayorElemDeArbol(const Arbol* pa, void* elem, size_t tamElem)
{
    if (!(pa = mayorNodoDeArbol(pa)))
        return false;
    memcpy(elem, (*pa)->elem, MINIMO(tamElem, (*pa)->tamElem));
    return true;
}

Arbol* mayorNodoDeArbol(const Arbol* pa)
{
    return (*pa)->hDer ? mayorNodoDeArbol(&(*pa)->hDer) : (Arbol*)pa;
}

/******************************************** MAYOR NO CLAVE ********************************************/

bool mayorElemNoClaveDeArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    const Arbol* mayor = pa;
    if (!*pa)
        return false;
    mayor = mayorNodoNoClaveDeArbol(&(*pa)->hIzq, mayor, cmp);
    mayor = mayorNodoNoClaveDeArbol(&(*pa)->hDer, mayor, cmp);
    memcpy(elem, (*mayor)->elem, MINIMO(tamElem, (*mayor)->tamElem));
    return true;
}

const Arbol* mayorNodoNoClaveDeArbol(const Arbol* pa, const Arbol* mayor, Cmp cmp)
{
    if (!*pa)
        return mayor;
    if (cmp((*pa)->elem, (*mayor)->elem) > 0)
        mayor = pa;
    mayor = mayorNodoNoClaveDeArbol(&(*pa)->hIzq, mayor, cmp);
    mayor = mayorNodoNoClaveDeArbol(&(*pa)->hDer, mayor, cmp);
    return mayor;
}

/******************************************** MENOR ********************************************/

bool menorElemDeArbol(const Arbol* pa, void* elem, size_t tamElem)
{
    if (!(pa = menorNodoDeArbol(pa)))
        return false;
    memcpy(elem, (*pa)->elem, MINIMO(tamElem, (*pa)->tamElem));
    return true;
}

Arbol* menorNodoDeArbol(const Arbol* pa)
{
    return (*pa)->hIzq ? menorNodoDeArbol(&(*pa)->hIzq) : (Arbol*)pa;
}

/******************************************** MENOR NO CLAVE ********************************************/

bool menorElemNoClaveDeArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    const Arbol* menor = pa;
    if (!*pa)
        return false;
    menor = menorNodoNoClaveDeArbol(&(*pa)->hIzq, menor, cmp);
    menor = menorNodoNoClaveDeArbol(&(*pa)->hDer, menor, cmp);
    memcpy(elem, (*menor)->elem, MINIMO(tamElem, (*menor)->tamElem));
    return true;
}

const Arbol* menorNodoNoClaveDeArbol(const Arbol* pa, const Arbol* menor, Cmp cmp)
{
    if (!*pa)
        return menor;
    if (cmp((*pa)->elem, (*menor)->elem) < 0)
        menor = pa;
    menor = menorNodoNoClaveDeArbol(&(*pa)->hIzq, menor, cmp);
    menor = menorNodoNoClaveDeArbol(&(*pa)->hDer, menor, cmp);
    return menor;
}
