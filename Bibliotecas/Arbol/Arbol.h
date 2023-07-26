#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define SIN_MEMORIA 1
#define DUPLICADO 2
#define ERROR_ARCHIVO 3
#define SIN_INICIALIZAR 4
#define NO_EXISTE 5

#define MINIMO(X, Y) ((X) > (Y) ? (Y) : (X))
#define MAXIMO(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct sNodoA {
    void* elem;
    size_t tamElem;
    struct sNodoA* hIzq;
    struct sNodoA* hDer;
} NodoA;

typedef NodoA* Arbol;

/************************************************* Funciones comunes *************************************************/

typedef int (*Cmp)(const void*, const void*);
typedef void (*Accion)(void*, void*);
typedef void (*Actualizar)(void*, const void*);
typedef void (*MostrarElemArbol)(const void*, int nivel);

/**************************************************** Primitivas ****************************************************/

void crearArbol(Arbol* pa);
int insertarOActualizarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);

int alturaArbol(const Arbol* pa);
int contarElemArbol(const Arbol* pa);
int contarElemArbolHastaNivel(const Arbol* pa, int nivel);
int contarHojasArbol(const Arbol* pa);
int podarArbol(Arbol* pa, int nivel);  // Devuelve la cantidad de nodos que se eliminaron
int vaciarArbol(Arbol* pa);            // Devuelve la cantidad de nodos que se eliminaron

// Usar pre orden para volver a cargar el arbol balanceado
/// Pos Orden : I, D, R
/// Pre Orden : R, I, D
/// En Orden  : I, R, D
void recorrerArbolPre(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEn(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPos(Arbol* pa, Accion accion, void* datosAccion);

int cargarArbolDeArchivoOrdenado(Arbol* pa, int limInf, int limSup, size_t tamElem, FILE* arch);
int cargarArchivoEnArbol(Arbol* pa, const char* nombreArchivo, size_t tamElem);

/// Balanceado: Hasta el penultimo nivel esta completo
bool esArbolCompleto(const Arbol* pa);
int esArbolCompletoHastaNivel(const Arbol* pa, int nivel);
bool esArbolBalanceado(const Arbol* pa);
bool esArbolAVL(const Arbol* pa);

bool buscarElemNoClaveArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarElemNoClaveDeArbol(Arbol* pa, void* elem, Cmp cmp);
bool mayorElemArbol(const Arbol* pa, void* elem, size_t tamElem);
bool mayorElemNoClaveArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool menorElemArbol(const Arbol* pa, void* elem, size_t tamElem);
bool menorElemNoClaveArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);

/******************************************* Funciones complementarias *******************************************/

NodoA* crearNodo(const void* elem, size_t tamElem);
NodoA* crearNodoArchivo(FILE* arch, size_t tamElem);
void destruirNodo(NodoA* nae, void* elem, size_t tamElem);

Arbol* buscarNodoA(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
void eliminarNodoA(Arbol* pnae);
Arbol* mayorNodoDeArbol(const Arbol* pa);
Arbol* menorNodoDeArbol(const Arbol* pa);

const Arbol* buscarNodoNoClaveA(const Arbol* pa, const void* elem, Cmp cmp);
const Arbol* mayorNodoNoClaveArbol(const Arbol* pa, const Arbol* mayor, Cmp cmp);
const Arbol* menorNodoNoClaveArbol(const Arbol* pa, const Arbol* menor, Cmp cmp);

void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar);
void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel);

#endif  // ARBOL_H_INCLUDED
