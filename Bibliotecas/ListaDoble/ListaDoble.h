#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ((X) > (Y) ? (Y) : (X))
#define TODO_OK 0
#define SIN_MEMORIA 1
#define DUPLICADO 2

typedef struct sNodoD {
    void* elem;
    size_t tamElem;
    struct sNodoD* sig;
    struct sNodoD* ant;
} NodoD;

typedef NodoD* Lista;

typedef int (*Cmp)(const void*, const void*);
typedef void (*Actualizar)(void*, const void*);
typedef void (*Accion)(void*, void*);

void crearLista(Lista* pl);

bool listaLlena(const Lista* pl, size_t tamElem);
bool listaVacia(const Lista* pl);

bool insertarPrimeroEnLista(Lista* pl, const void* elem, size_t tamElem);
bool insertarUltimoEnLista(Lista* pl, const void* elem, size_t tamElem);
int insertarOActualizarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);

bool buscarElementoEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);

bool eliminarPrimeroDeLista(Lista* pl, void* elem, size_t tamElem);
bool eliminarUltimoDeLista(Lista* pl, void* elem, size_t tamElem);
bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeListaDes(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
bool eliminarYOActualizarDuplicadosDeListaOrd(Lista* pl, Cmp cmp, Actualizar actualizar);
bool eliminarYOActualizarDuplicadosDeListaDes(Lista* pl, Cmp cmp, Actualizar actualizar);

void recorrerListaDeIzqADer(Lista* pl, Accion accion, void* datosAccion);
void recorrerListaDeDerAIzq(Lista* pl, Accion accion, void* datosAccion);

void vaciarLista(Lista* pl);

void ordenarLista(Lista* pl, Cmp cmp, int sentidoOrdenamiento);

NodoD* crearNodoDoble(const void* elem, size_t tamElem);
void destruirNodoDoble(NodoD* nae, void* elem, size_t tamElem);

#endif  // LISTADOBLE_H_INCLUDED
