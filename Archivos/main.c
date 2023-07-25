#include "Archivos.h"

int main() {
    system("chcp 1252 > nul");
    int res;
    /*********************************** Actualizacion de de archivos ***********************************/
    /*res = crearArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    puts("\nArchivo sin actualizar:\n");

    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    res = actualizarArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    puts("\nArchivo actualizado:\n");

    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;*/

    /**************************************** Merge de archivos ****************************************/
    /*res = crearArchivoBinMovimientos(PATH_MOVS_BIN);
    if(res != TODO_OK)
        return res;

    puts("Antes de actualizar:");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    res = actualizarProductos(PATH_PRODS_BIN, PATH_MOVS_BIN);
    if(res != TODO_OK)
        return res;

    puts("\nDespues de actualizar:");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;*/

    /********************************* Archivo texto variable a binario *********************************/
    /*res = crearArchivoTxtVarProductos(PATH_PRODS_VAR_TXT);
    if(res != TODO_OK)
        return res;

    convertirArchTxtVarABin(PATH_PRODS_VAR_TXT, PATH_PRODS_BIN, PATH_PRODS_ERR);

    puts("Leyendo del archivo binario");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    convertirArchBinATxtVar(PATH_PRODS_BIN, PATH_PRODS_VAR_TXT, PATH_PRODS_ERR);

    puts("\nLeyendo del archivo de texto variable");
    res = leerArchivoTxtVarProductos(PATH_PRODS_VAR_TXT);
    if(res != TODO_OK)
        return res;*/

    /*********************************** Archivo texto fijo a binario ***********************************/
    /*res = crearArchivoTxtFijoProductos(PATH_PRODS_FIJO_TXT);
    if(res != TODO_OK)
        return res;

    puts("\nLeyendo del archivo de texto fijo");
    res = leerArchivoTxtFijoProductos(PATH_PRODS_FIJO_TXT);
    if(res != TODO_OK)
        return res;

    convertirArchTxtFijoABin(PATH_PRODS_FIJO_TXT, PATH_PRODS_BIN, PATH_PRODS_ERR);

    puts("\nLeyendo del archivo binario");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;*/

    /********************************* Archivo binario a texto variable *********************************/
    /*res = crearArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    puts("\nLeyendo del archivo binario");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    convertirArchBinATxtVar(PATH_PRODS_BIN, PATH_PRODS_VAR_TXT);

    puts("\nLeyendo del archivo de texto variable");
    res = leerArchivoTxtVarProductos(PATH_PRODS_VAR_TXT);
    if(res != TODO_OK)
        return res;*/

    /*********************************** Archivo binario a texto fijo ***********************************/
    /*res = crearArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    puts("\nLeyendo del archivo binario");
    res = leerArchivoBinProductos(PATH_PRODS_BIN);
    if(res != TODO_OK)
        return res;

    convertirArchBinATxtFijo(PATH_PRODS_BIN, PATH_PRODS_FIJO_TXT);

    puts("\nLeyendo del archivo de texto fijo");
    res = leerArchivoTxtFijoProductos(PATH_PRODS_FIJO_TXT);
    if(res != TODO_OK)
        return res;*/

    /*********************************** Ejercicio 13 ***********************************/

    res = crearArchivoBinEmpleados(PATH_EMP_BIN);
    if (res != TODO_OK)
        return res;

    res = crearArchivoBinEstudiantes(PATH_EST_BIN);
    if (res != TODO_OK)
        return res;

    puts("Archivo Empleados:");
    res = leerArchivoBinEmpleados(PATH_EMP_BIN);
    if (res != TODO_OK)
        return res;

    puts("\nArchivo Estudiantes:");
    res = leerArchivoBinEstudiantes(PATH_EST_BIN);
    if (res != TODO_OK)
        return res;

    res = actualizarEmpleados(PATH_EMP_BIN, PATH_EST_BIN);
    if (res != TODO_OK)
        return res;

    puts("\nEmpleados actualizados:");

    puts("Archivo Empleados:");
    res = leerArchivoBinEmpleados(PATH_EMP_BIN);
    if (res != TODO_OK)
        return res;

    return TODO_OK;
}
