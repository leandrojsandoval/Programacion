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

/******************************************** CARGAR ********************************************/

void crearArbol(Arbol* pa);
NodoA* crearNodo(const void* elem, size_t tamElem);
int insertarOActualizarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
int cargarArchivoEnArbol(Arbol* pa, const char* nombreArchivo, size_t tamElem);
int cargarArbolDeArchivoOrdenado(Arbol* pa, int limInf, int limSup, size_t tamElem, FILE* arch);

/******************************************** BUSQUEDA ********************************************/

bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
Arbol* buscarNodoEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);

/******************************************** BUSQUEDA NO CLAVE ********************************************/

bool buscarElemNoClaveEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
const Arbol* buscarNodoNoClaveEnArbol(const Arbol* pa, const void* elem, Cmp cmp);

/******************************************** RECORRIDOS ********************************************/

// Usar pre orden para volver a cargar el arbol balanceado
/// Pos Orden : I, D, R
/// Pre Orden : R, I, D
/// En Orden  : I, R, D
void recorrerArbolPre(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEn(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPos(Arbol* pa, Accion accion, void* datosAccion);

/******************************************** IMPRIMIR ********************************************/

void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar);
void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel);

/******************************************** ADMINISTRATIVOS ********************************************/

int alturaArbol(const Arbol* pa);
int contarElemArbol(const Arbol* pa);
int contarElemArbolHastaNivel(const Arbol* pa, int nivel);
int contarHojasArbol(const Arbol* pa);
/// Balanceado: Hasta el penultimo nivel esta completo
bool esArbolCompleto(const Arbol* pa);
int esArbolCompletoHastaNivel(const Arbol* pa, int nivel);
bool esArbolAVL(const Arbol* pa);
bool esArbolBalanceado(const Arbol* pa);

/******************************************** ELIMINAR ********************************************/

void destruirNodo(NodoA* nae, void* elem, size_t tamElem);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarElemNoClaveDeArbol(Arbol* pa, void* elem, Cmp cmp);
void eliminarNodoDeArbol(Arbol* pnae);
int podarArbol(Arbol* pa, int nivel);  // Devuelve la cantidad de nodos que se eliminaron
int vaciarArbol(Arbol* pa);            // Devuelve la cantidad de nodos que se eliminaron

/******************************************** MAYOR ********************************************/

bool mayorElemDeArbol(const Arbol* pa, void* elem, size_t tamElem);
Arbol* mayorNodoDeArbol(const Arbol* pa);

/******************************************** MAYOR NO CLAVE ********************************************/

bool mayorElemNoClaveDeArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
const Arbol* mayorNodoNoClaveDeArbol(const Arbol* pa, const Arbol* mayor, Cmp cmp);

/******************************************** MENOR ********************************************/

bool menorElemDeArbol(const Arbol* pa, void* elem, size_t tamElem);
Arbol* menorNodoDeArbol(const Arbol* pa);

/******************************************** MENOR NO CLAVE ********************************************/

bool menorElemNoClaveDeArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
const Arbol* menorNodoNoClaveDeArbol(const Arbol* pa, const Arbol* menor, Cmp cmp);


#endif // ARBOL_H_INCLUDED
