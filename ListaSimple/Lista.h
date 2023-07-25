#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ((X) > (Y) ? (Y) : (X))
#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEMORIA 2

typedef struct sNodo {
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Lista;

typedef int (*Cmp)(const void*, const void*);
typedef void (*Actualizar)(void*, const void*);
typedef void (*Accion)(void*, void*);

void crearLista(Lista* pl);

bool listaLlena(const Lista* pl, size_t tamElem);
bool listaVacia(const Lista* pl);

bool insertarPrimeroEnLista(Lista* pl, const void* elem, size_t tamElem);
bool insertarUltimoEnLista(Lista* pl, const void* elem, size_t tamElem);
int insertarOActualizarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);

bool eliminarPrimeroDeLista(Lista* pl, void* elem, size_t tamElem);
bool eliminarUltimoDeLista(Lista* pl, void* elem, size_t tamElem);
bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeListaDes(Lista* pl, void* elem, size_t tamElem, Cmp cmp);

/// TAMBIEN HAY VARIANTES CON EL PARAMETRO DE ACTUALIZAR
bool eliminarDuplicadosDeListaOrd(Lista* pl, Cmp cmp);
bool eliminarDuplicadosDeListaDes(Lista* pl, Cmp cmp);

bool buscarElementoEnLista(Lista* pl, void* elem, size_t tamElem, Cmp cmp);

void vaciarLista(Lista* pl);

void recorrerLista(const Lista* pl, Accion accion, void* datosAccion);

void ordenarLista(Lista* pl, Cmp cmp, int sentidoOrdenamiento);

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

#endif  // LISTA_H_INCLUDED
