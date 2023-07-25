#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"

#define TODO_OK 0

/************************************* NOMBRES DE LOS ARCHIVOS *************************************/

#define PATH_PRODS_BIN "Productos.dat"
#define PATH_PRODS_VAR_TXT "Productos_var.txt"
#define PATH_PRODS_FIJO_TXT "Productos_fijo.txt"
#define PATH_PRODS_ERR "Produtos_Errores.txt"
#define PATH_MOVS_BIN "Movimientos.dat"

#define PATH_EMP_BIN "Empleados.dat"
#define PATH_EST_BIN "Estudiantes.dat"

/******************************* TAMA�OS DE LOS VECTORES ESTRUCTURAS *******************************/

#define CANT_PRODS 6
#define CANT_MOVS 11

/************************************** MACROS PARA ARCHIVOS **************************************/

#define TAM_LINEA 300
#define ERROR_NO_FATAL 2
#define ERROR_ARCHIVO -1
#define ERROR_FATAL -2
#define ERROR_LINEA_LARGA -3
#define ERROR_CAMPO -4

/********************************* TAMA�OS DE CAMPOS Y VECTORES *********************************/

#define TAM_CODIGO 21
#define TAM_DESCRIPCION 51
#define TAM_PRECIO 8
#define TAM_FECHA 10
#define TAM_STOCK 5

typedef struct {
    char codigo[TAM_CODIGO];
    char descripcion[TAM_DESCRIPCION];
    float precio;
    Fecha fPro;
    int stock;
} Producto;

typedef struct {
    char codigo[TAM_CODIGO];
    int cantidad;
} Movimiento;

typedef struct {
    unsigned dni;
    char nombre[30];
    char apellido[30];
    float promedio;
} Estudiante;

typedef struct {
    unsigned dni;
    char nombre[30];
    char apellido[30];
    double sueldo;
} Empleado;

/************************************* Creacion de archivos *************************************/

int crearArchivoBinProductos(const char* nombreArchivo);
int crearArchivoBinMovimientos(const char* nombreArchivo);
int crearArchivoTxtVarProductos(const char* nombreArchivo);
int crearArchivoTxtFijoProductos(const char* nombreArchivo);

int crearArchivoBinEmpleados(const char* nombreArchivo);
int crearArchivoBinEstudiantes(const char* nombreArchivo);

/************************************* Lectura de archivos *************************************/

int leerArchivoBinProductos(const char* nombreArchivo);
int leerArchivoBinMovimientos(const char* nombreArchivo);
int leerArchivoTxtVarProductos(const char* nombreArchivo);
int leerArchivoTxtFijoProductos(const char* nombreArchivo);

int leerArchivoBinEmpleados(const char* nombreArchivo);
int leerArchivoBinEstudiantes(const char* nombreArchivo);

/******************************* Actualizacion / Merge Archivos *******************************/

int actualizarArchivoBinProductos(const char* nombreArchivo);
int actualizarProductos(const char* nombreProductos, const char* nombreMovimientos);
void actualizarProductoYAvanzarMov(Producto* prod, Movimiento* mov, FILE* archMovs);
void grabarProductoYAvanzarProd(Producto* prod, FILE* archProds, FILE* archProdsTmp);
void procesarProductoNuevo(Movimiento* mov, FILE* archMovs, FILE* archProdsTmp);

int actualizarEmpleados(const char* nombreEmpleados, const char* nombreEstudiantes);
void actualizarSueldoYGrabarEmpleados(Empleado* emp, FILE* archEmp);

/****************************** Conversion bin - txt y txt - bin ******************************/

int convertirArchTxtVarABin(const char* nombreArchivoTxt, const char* nombreArchivoBin, const char* nombreArchivoErr);
int convertirArchTxtFijoABin(const char* nombreArchivoTxt, const char* nombreArchivoBin, const char* nombreArchivoErr);
int convertirArchBinATxtVar(const char* nombreArchivoBin, const char* nombreArchivoTxt);
int convertirArchBinATxtFijo(const char* nombreArchivoBin, const char* nombreArchivoTxt);

/**************************************** Texto variable ****************************************/

int grabarRegistroProdsTxtVar(FILE* archProdsTxt, Producto* prod);
int leerRegistroProdsTxtVar(FILE* archProdsTxt, Producto* prod);
int txtVarABin(const char* linea, Producto* prod);

/****************************************** Texto fijo ******************************************/

int grabarRegistroProdsTxtFijo(FILE* archProdsTxt, Producto* prod);
int leerRegistroProdsTxtFijo(FILE* archProdsTxt, Producto* prod);
int txtFijoABin(const char* linea, Producto* prod);

/**************************************** Otras funciones ****************************************/

int grabarErrorEnArchivo(FILE* archProdsErr, Producto* prod, int codRet);
bool esErrorFatal(int codRet);
bool controlCampoInt(const char* campo);
bool controlCampoFloat(const char* campo);
bool controlCampoFecha(const char* campo);

int cmpEstudiantesEmpleados(const Empleado* emp, const Estudiante* est);

#endif  // ARCHIVOS_H_INCLUDED
