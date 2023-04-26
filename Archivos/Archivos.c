#include "Archivos.h"

/************************************* Creacion de archivos *************************************/

int crearArchivoBinProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "wb");
    if(!archProds)
    {
        puts("No se pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }
    Producto arrProds[CANT_PRODS] =
    {
        {"00", "Higo", 120.50, {12,1,2022}, 100},
        {"04", "Banana", 80.50, {1,11,2021}, 100},
        {"07", "Pera", 50.50, {5,9,2020}, 50},
        {"09", "Manzana", 70.50, {28,4,2022}, 70},
        {"10", "Arándano", 60.50, {2,10,2022}, 30},
        {"14", "Durazno", 90.50, {15,4,2020}, 90}
    };
    fwrite(arrProds, sizeof(Producto), CANT_PRODS, archProds);
    fclose(archProds);
    return TODO_OK;
}

int crearArchivoBinMovimientos (const char* nombreArchivo)
{
    FILE* archMovs = fopen(nombreArchivo,"wb");
    if(!archMovs)
    {
        puts("No se pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }
    Movimiento arrMovs[CANT_MOVS] =
    {
        {"01", 20},
        {"07", 20},
        {"07", -10},
        {"08", 40},
        {"10", 40},
        {"10", 20},
        {"11", 50},
        {"12", 60},
        {"12", -10},
        {"15", 80},
        {"15", 40}
    };
    fwrite(arrMovs, sizeof(Movimiento), CANT_MOVS, archMovs);
    fclose(archMovs);
    return TODO_OK;
}

int crearArchivoTxtVarProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "wt");
    if(!archProds)
    {
        puts("No se pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }
    Producto arrProds[CANT_PRODS] =
    {
        {"00", "Higo", 120.50, {12,1,2022}, 100},
        {"04", "Banana", 80.50, {1,11,2021}, 100},
        {"07", "Pera", 50.50, {5,9,2020}, 50},
        {"09", "Manzana", 70.50, {28,4,2022}, 70},
        {"10", "Arándano", 60.50, {2,10,2022}, 30},
        {"14", "Durazno", 90.50, {15,4,2020}, 90}
    };
    for(int i=0; i<CANT_PRODS; i++)
    {
        grabarRegistroProdsTxtVar(archProds, &arrProds[i]);
    }
    fclose(archProds);
    return TODO_OK;
}

int crearArchivoTxtFijoProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "wt");

    if(!archProds)
    {
        puts("No se pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }

    Producto arrProds[CANT_PRODS] =
    {
        {"00", "Higo", 120.50, {12,1,2022}, 100},
        {"04", "Banana", 80.50, {1,11,2021}, 100},
        {"07", "Pera", 50.50, {5,9,2020}, 50},
        {"09", "Manzana", 70.50, {28,4,2022}, 70},
        {"10", "Arándano", 60.50, {2,10,2022}, 30},
        {"14", "Durazno", 90.50, {15,4,2020}, 90}
    };

    for(int i=0; i<CANT_PRODS; i++)
        grabarRegistroProdsTxtFijo(archProds, &arrProds[i]);

    fclose(archProds);
    return TODO_OK;
}

int crearArchivoBinEmpleados (const char* nombreArchivo)
{
    FILE* archEmp = fopen(nombreArchivo, "wb");
    if(!archEmp)
        return ERROR_ARCHIVO;
    Empleado vEmpleados[] =
    {
        {12345678,"Peralta","Diaz",175000},
        {56789012,"Martina","Fernández",75000},
        {56789012,"Ana","Gómez",75000},
        {12345678,"Juan","Gómez",360000},
        {78901234,"Facundo","González",200000},
        {34567890,"Belen","Gutiérrez",300000},
        {34567890,"Sofia","Gutiérrez",95000},
        {90123456,"Matilda","Martinez",150000},
        {90123456,"Constantino","Morales",80000},
        {78901234,"Pedro","Quiroga",125000},
    };
    fwrite(vEmpleados, sizeof(vEmpleados), 1, archEmp);
    fclose(archEmp);
    return TODO_OK;
}

int crearArchivoBinEstudiantes (const char* nombreArchivo)
{
    FILE* archEst = fopen(nombreArchivo, "wb");
    if(!archEst)
        return ERROR_ARCHIVO;
    Estudiante vEstudiantes[] =
    {
        {12345678,"Peralta","Diaz",8.75},
        {56789012,"Martina","Fernández",8},
        {56789012,"Ana","Gómez",6.75},
        {12345678,"Gaston","Gómez",4.25},
        {22222222,"Facundo","González",2},
        {11111111,"Camila","Gutiérrez",8.50},
        {66666666,"Lucia","Gutiérrez",7.25},
        {90123456,"Matilda","Martinez",7.50},
        {44444444,"Constantino","Morales",5},
        {55555555,"Pedro","Quiroga",10},
    };
    fwrite(vEstudiantes, sizeof(vEstudiantes), 1, archEst);
    fclose(archEst);
    return TODO_OK;
}

/************************************* Lectura de archivos *************************************/

int leerArchivoBinProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "rb");
    if(!archProds)
    {
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }
    Producto prod;
    fread(&prod, sizeof(Producto), 1, archProds);
    while(!feof(archProds))
    {
        printf("%-10s%-10s%8.2f\t%02d/%02d/%4d\t%5d\n",prod.codigo,prod.descripcion,prod.precio,prod.fPro.dia,prod.fPro.mes,prod.fPro.anio,prod.stock);
        fread(&prod, sizeof(Producto), 1, archProds);
    }
    fclose(archProds);
    return TODO_OK;
}

int leerArchivoBinMovimientos (const char* nombreArchivo)
{
    FILE* archMovs = fopen(nombreArchivo, "rb");
    if(!archMovs)
    {
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }
    Movimiento mov;
    fread(&mov, sizeof(Movimiento), 1, archMovs);
    while(!feof(archMovs))
    {
        printf("%-10s\t%4d\n",mov.codigo,mov.cantidad);
        fread(&mov, sizeof(Movimiento), 1, archMovs);
    }
    fclose(archMovs);
    return TODO_OK;
}

int leerArchivoTxtVarProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "rt");
    if(!archProds)
    {
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }

    Producto prod;

    while(leerRegistroProdsTxtVar(archProds, &prod) != EOF)
        printf("%-10s%-10s%8.2f\t%02d/%02d/%4d\t%5d\n",prod.codigo,prod.descripcion,prod.precio,prod.fPro.dia,prod.fPro.mes,prod.fPro.anio,prod.stock);

    fclose(archProds);
    return TODO_OK;
}

int leerArchivoTxtFijoProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "rt");
    if(!archProds)
    {
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }

    Producto prod;

    char linea[TAM_LINEA];
    int codRet = TODO_OK;

    while(fgets(linea, TAM_LINEA, archProds))
    {
        codRet = txtFijoABin(linea, &prod);
        if(codRet == TODO_OK)
            printf("%-10s%-10s%8.2f\t%02d/%02d/%4d\t%5d\n",prod.codigo,prod.descripcion,prod.precio,prod.fPro.dia,prod.fPro.mes,prod.fPro.anio,prod.stock);
    }

    ///PREGUNTAR LO DE FSCANF
    /*while(leerRegistroProdsTxtFijo(archProds, &prod) != EOF)
        printf("%-10s%-10s%8.2f\t%02d/%02d/%4d\t%5d\n",prod.codigo,prod.descripcion,prod.precio,prod.fPro.dia,prod.fPro.mes,prod.fPro.anio,prod.stock);*/

    fclose(archProds);
    return TODO_OK;
}

int leerArchivoBinEmpleados (const char* nombreArchivo)
{
    FILE* archEmp = fopen(nombreArchivo, "rb");
    if(!archEmp)
        return ERROR_ARCHIVO;
    Empleado emp;
    fread(&emp, sizeof(Empleado), 1, archEmp);
    while(!feof(archEmp))
    {
        printf("%-10d%-20s%-20s%.2lf\n",emp.dni,emp.nombre,emp.apellido,emp.sueldo);
        fread(&emp, sizeof(Empleado), 1, archEmp);
    }
    fclose(archEmp);
    return TODO_OK;
}

int leerArchivoBinEstudiantes (const char* nombreArchivo)
{
    FILE* archEst = fopen(nombreArchivo, "rb");
    if(!archEst)
        return ERROR_ARCHIVO;
    Estudiante est;
    fread(&est, sizeof(Estudiante), 1, archEst);
    while(!feof(archEst))
    {
        printf("%-10d%-20s%-20s%.2f\n",est.dni,est.nombre,est.apellido,est.promedio);
        fread(&est, sizeof(Estudiante), 1, archEst);
    }
    fclose(archEst);
    return TODO_OK;
}

/********************************** Actualizacion / Merge Archivos **********************************/

int actualizarArchivoBinProductos (const char* nombreArchivo)
{
    FILE* archProds = fopen(nombreArchivo, "r+b");
    if(!archProds)
    {
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }
    Producto prod;
    fread(&prod, sizeof(Producto), 1, archProds);
    while(!feof(archProds))
    {
        prod.precio *= 1.20;
        fseek(archProds, (long)-sizeof(Producto), SEEK_CUR);
        fwrite(&prod, sizeof(Producto), 1, archProds);
        fseek(archProds, 0L, SEEK_CUR);
        fread(&prod, sizeof(Producto), 1, archProds);
    }
    fclose(archProds);
    return TODO_OK;
}

int actualizarProductos (const char* nombreProductos, const char* nombreMovimientos)
{
    FILE* archProds = fopen(nombreProductos, "rb");
    FILE* archMovs = fopen(nombreMovimientos, "rb");
    FILE* archProdsTmp = fopen("Productos.tmp", "wb");

    if(!archProds || !archMovs || !archProdsTmp)
    {
        fclose(archProds);
        fclose(archMovs);
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }

    Producto prod;
    Movimiento mov;
    int comp;

    fread(&prod, sizeof(Producto), 1, archProds);
    fread(&mov, sizeof(Movimiento), 1, archMovs);

    while(!feof(archMovs) && !feof(archProds))
    {
        comp = strcmp(prod.codigo, mov.codigo);
        if(comp == 0)
            actualizarProductoYAvanzarMov(&prod, &mov, archMovs);
        if(comp < 0)
            grabarProductoYAvanzarProd(&prod, archProds, archProdsTmp);
        if(comp > 0)
            procesarProductoNuevo(&mov, archMovs, archProdsTmp);
    }
    while(!feof(archProds))
        grabarProductoYAvanzarProd(&prod, archProds, archProdsTmp);

    while(!feof(archMovs))
        procesarProductoNuevo(&mov, archMovs, archProdsTmp);

    fclose(archMovs);
    fclose(archProds);
    fclose(archProdsTmp);

    remove(nombreProductos);
    rename("Productos.tmp", nombreProductos);
    return TODO_OK;
}

void actualizarProductoYAvanzarMov(Producto* prod, Movimiento* mov, FILE* archMovs)
{
    prod->stock += mov->cantidad;
    fread(mov, sizeof(Movimiento), 1, archMovs);
}

void grabarProductoYAvanzarProd(Producto* prod, FILE* archProds, FILE* archProdsTmp)
{
    fwrite(prod, sizeof(Producto), 1, archProdsTmp);
    fread(prod, sizeof(Producto), 1, archProds);
}

void procesarProductoNuevo(Movimiento* mov, FILE* archMovs, FILE* archProdsTmp)
{
    Producto prodNue = {"","",0,{1,1,ANIO_BASE},0};
    strcpy(prodNue.codigo, mov->codigo);
    prodNue.stock = mov->cantidad;
    fread(mov, sizeof(Movimiento), 1, archMovs);
    while(!feof(archMovs) && strcmp(prodNue.codigo, mov->codigo) == 0)
    {
        prodNue.stock += mov->cantidad;
        fread(mov, sizeof(Movimiento), 1, archMovs);
    }
    fwrite(&prodNue, sizeof(Producto), 1, archProdsTmp);
}

/*Ejercicio 13: Se dispone de dos archivos binarios: <"empleados"> y <"estudiantes">.
Cada registro del primer archivo contiene los campos:
    - <dni>, <apellido>, <nombre> y <sueldo>,

En tanto que los del segundo:

    - <dni>, <apellido>, <nombre> y <promedio>.

Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> /
<dni>. Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en
arrays. El sueldo es double y el promedio es float.

Escriba un programa que, leyendo ambos archivos, actualice el sueldo de
aquellos empleados que tengan un registro de estudiante con un promedio superior a 7,
en un 7,28%.*/

int actualizarEmpleados (const char* nombreEmpleados, const char* nombreEstudiantes)
{
    FILE* archEmp = fopen(nombreEmpleados, "r+b");
    FILE* archEst = fopen(nombreEstudiantes, "rb");
    if(!archEmp || !archEst)
    {
        fclose(archEmp);
        fclose(archEst);
        return ERROR_ARCHIVO;
    }
    Empleado emp;
    Estudiante est;

    fread(&emp, sizeof(Empleado), 1, archEmp);
    fread(&est, sizeof(Estudiante), 1, archEst);

    int comp;

    while(!feof(archEmp) && !feof(archEst))
    {
        comp = cmpEstudiantesEmpleados(&emp, &est);
        if(comp == 0)
        {
            if(est.promedio > 7)
                actualizarSueldoYGrabarEmpleados(&emp, archEmp);
            fread(&emp, sizeof(Empleado), 1, archEmp);
            fread(&est, sizeof(Estudiante), 1, archEst);
        }
        if(comp < 0)
            fread(&emp, sizeof(Empleado), 1, archEmp);
        if(comp > 0)
            fread(&est, sizeof(Estudiante), 1, archEst);
    }
    fclose(archEst);
    fclose(archEmp);
    return TODO_OK;
}

void actualizarSueldoYGrabarEmpleados (Empleado* emp, FILE* archEmp)
{
    emp->sueldo += emp->sueldo / 7.28;
    fseek(archEmp, (long)-sizeof(Empleado), SEEK_CUR);
    fwrite(emp, sizeof(Empleado), 1, archEmp);
    fseek(archEmp, 0L, SEEK_CUR);
}

/********************************** Conversion bin - txt y txt - bin **********************************/

int convertirArchTxtVarABin (const char* nombreArchivoTxt, const char* nombreArchivoBin, const char* nombreArchivoErr)
{
    FILE* archProdsTxt = fopen(nombreArchivoTxt, "rt");
    FILE* archProdsBin = fopen(nombreArchivoBin, "wb");
    FILE* archProdsErr = fopen(nombreArchivoErr, "wt");

    if(!archProdsTxt || !archProdsBin || !archProdsErr)
    {
        fclose(archProdsTxt);
        fclose(archProdsErr);
        puts("No pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }

    Producto prod;
    char linea[TAM_LINEA];
    bool errorF, errorNoF;
    errorF = errorNoF = false;
    int codRet = TODO_OK;

    //fgets devuelve la direccion del vector que se pasa por parametro, si no puedo realizar la lectura devuelve NULL
    while(!(errorF = esErrorFatal(codRet)) && fgets(linea, TAM_LINEA, archProdsTxt))
    {
        codRet = txtVarABin(linea, &prod);
        if(codRet == TODO_OK)
            fwrite(&prod, sizeof(Producto), 1, archProdsBin);
        else
            grabarErrorEnArchivo(archProdsErr, &prod, codRet);
    }

    //Otra forma para leer desde el archivo de texto y grabar en el binario es usando fscanf
    /*while(leerRegistroProdsTxtVar(archProdsTxt, &prod) != EOF)
        fwrite(&prod, sizeof(Producto), 1, archProdsBin);*/

    fclose(archProdsBin);
    fclose(archProdsTxt);
    fclose(archProdsErr);

    return errorF? ERROR_FATAL : (errorNoF? ERROR_NO_FATAL : TODO_OK);
}

int convertirArchTxtFijoABin (const char* nombreArchivoTxt, const char* nombreArchivoBin, const char* nombreArchivoErr)
{
    FILE* archProdsTxt = fopen(nombreArchivoTxt, "rt");
    FILE* archProdsBin = fopen(nombreArchivoBin, "wb");
    FILE* archProdsErr = fopen(nombreArchivoErr, "wt");

    if(!archProdsTxt || !archProdsBin || !archProdsErr)
    {
        fclose(archProdsTxt);
        fclose(archProdsErr);
        puts("No pudo abrir el archivo");
        return ERROR_ARCHIVO;
    }

    Producto prod;
    char linea[TAM_LINEA];
    bool errorF, errorNoF;
    errorF = errorNoF = false;
    int codRet = TODO_OK;

    while(!(errorF = esErrorFatal(codRet)) && fgets(linea, TAM_LINEA, archProdsTxt))
    {
        codRet = txtFijoABin(linea, &prod);
        if(codRet == TODO_OK)
            fwrite(&prod, sizeof(Producto), 1, archProdsBin);
        else
            grabarErrorEnArchivo(archProdsErr, &prod, codRet);
    }

    /*while(leerRegistroProdsTxtFijo(archProdsTxt, &prod) != EOF)
        fwrite(&prod, sizeof(Producto), 1, archProdsBin);*/

    fclose(archProdsBin);
    fclose(archProdsTxt);
    fclose(archProdsErr);

    return errorF? ERROR_FATAL : (errorNoF? ERROR_NO_FATAL : TODO_OK);
}

int convertirArchBinATxtVar (const char* nombreArchivoBin, const char* nombreArchivoTxt)
{
    FILE* archProdsBin = fopen(nombreArchivoBin, "rb");
    FILE* archProdsTxt = fopen(nombreArchivoTxt, "wt");
    if(!archProdsBin || !archProdsTxt)
    {
        fclose(archProdsTxt);
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }
    Producto prod;
    fread(&prod, sizeof(Producto), 1, archProdsBin);
    while(!feof(archProdsBin))
    {
        grabarRegistroProdsTxtVar(archProdsTxt, &prod);
        fread(&prod, sizeof(Producto), 1, archProdsBin);
    }
    fclose(archProdsBin);
    fclose(archProdsTxt);
    return TODO_OK;
}

int convertirArchBinATxtFijo (const char* nombreArchivoBin, const char* nombreArchivoTxt)
{
    FILE* archProdsBin = fopen(nombreArchivoBin, "rb");
    FILE* archProdsTxt = fopen(nombreArchivoTxt, "wt");
    if(!archProdsBin || !archProdsTxt)
    {
        fclose(archProdsTxt);
        puts("No abrio el archivo");
        return ERROR_ARCHIVO;
    }
    Producto prod;
    fread(&prod, sizeof(Producto), 1, archProdsBin);
    while(!feof(archProdsBin))
    {
        grabarRegistroProdsTxtFijo(archProdsTxt, &prod);
        fread(&prod, sizeof(Producto), 1, archProdsBin);
    }
    fclose(archProdsBin);
    fclose(archProdsTxt);
    return TODO_OK;
}

/******************************************* Texto variable *******************************************/

int grabarRegistroProdsTxtVar (FILE* archProdsTxt, Producto* prod)
{
    return fprintf(archProdsTxt,"%s|%s|%.2f|%02d/%02d/%4d|%d\n",
                   prod->codigo,prod->descripcion,prod->precio,
                   prod->fPro.dia,prod->fPro.mes,prod->fPro.anio,
                   prod->stock);
}

int leerRegistroProdsTxtVar (FILE* archProdsTxt, Producto* prod)
{
    return fscanf(archProdsTxt,"%[^|\n]|%[^|\n]|%f|%d/%d/%d|%d\n",
                  prod->codigo,prod->descripcion,&prod->precio,
                  &prod->fPro.dia,&prod->fPro.mes,&prod->fPro.anio,
                  &prod->stock);
}

int txtVarABin (const char* linea, Producto* prod)
{
    //Busco el enter,
    char* act = strrchr(linea, '\n');

    //En el caso de que el tamaño de la linea es menor que el registro no lo va a encontrar
    if(!act)
        return ERROR_LINEA_LARGA;

    ///Campo stock
    //Si lo encontro, se pone fin de linea reemplazando el '\n' por '\0'
    *act = '\0';
    //Se busca la ultima barra para ir agarrando campo por campo
    act = strrchr(linea, '|');
    //Apunto al siguiente caracter (act + 1), que es donde comienza dicho campo y lo copio en la estructura
    if(controlCampoInt(act + 1) == false)
        return ERROR_CAMPO;
    sscanf(act + 1, "%d", &prod->stock);

    ///Campo fecha
    *act = '\0';
    act = strrchr(linea, '|');
    if(controlCampoFecha(act + 1) == false)
        return ERROR_CAMPO;
    sscanf(act + 1, "%d/%d/%d", &prod->fPro.dia, &prod->fPro.mes, &prod->fPro.anio);
    if(!esFechaValida(&prod->fPro))
        return ERROR_FECHA_INVALIDA;

    ///Campo precio
    *act = '\0';
    act = strrchr(linea, '|');
    if(controlCampoFloat(act + 1) == false)
        return ERROR_CAMPO;
    sscanf(act + 1, "%f", &prod->precio);

    ///Campo descripcion
    *act = '\0';
    act = strrchr(linea, '|');
    strncpy(prod->descripcion, act + 1, TAM_DESCRIPCION - 1);
    //Este control es por si copio mas del tamaño de la descripcion, entonces se pone un '\0' al final
    *(prod->descripcion + TAM_DESCRIPCION - 1) = '\0';

    ///Campo codigo
    *act = '\0';
    act = strrchr(linea, '|');
    strcpy(prod->codigo, linea);

    return TODO_OK;
}

/********************************************* Texto fijo *********************************************/

int grabarRegistroProdsTxtFijo (FILE* archProdsTxt, Producto* prod)
{
    return fprintf(archProdsTxt,"%-20s%-50s%08.2f%02d/%02d/%04d%05d\n",
                   prod->codigo,prod->descripcion,prod->precio,
                   prod->fPro.dia,prod->fPro.mes,prod->fPro.anio,
                   prod->stock);

    ///Graba mal en el archivo
    /*return fprintf(archProdsTxt, "%-.*s%-.*s%08.2f%02d/%02d/%04d%.*d\n",
                   TAM_CODIGO,prod->codigo,
                   TAM_DESCRIPCION,prod->descripcion,
                   prod->precio,
                   prod->fPro.dia,prod->fPro.mes,prod->fPro.anio,
                   TAM_STOCK,prod->stock);*/
}

int leerRegistroProdsTxtFijo (FILE* archProdsTxt, Producto* prod)
{
    return fscanf(archProdsTxt,"%20[^\n]%50[^\n]%8f%2d/%2d/%4d%5d\n",
                  prod->codigo,prod->descripcion,&prod->precio,
                  &prod->fPro.dia,&prod->fPro.mes,&prod->fPro.anio,
                  &prod->stock);
}

int txtFijoABin (const char* linea, Producto* prod)
{
    char* act = strrchr(linea, '\n');

    if(!act)
        return ERROR_LINEA_LARGA;

    *act = '\0';
    act -= TAM_STOCK;
    if(controlCampoInt(act) == false)
        return ERROR_CAMPO;
    sscanf(act, "%d", &prod->stock);

    *act = '\0';
    act -= TAM_FECHA;
    if(controlCampoFecha(act) == false)
        return ERROR_CAMPO;
    sscanf(act, "%2d/%2d/%4d", &prod->fPro.dia, &prod->fPro.mes, &prod->fPro.anio);

    *act = '\0';
    act -= TAM_PRECIO;
    if(controlCampoFloat(act) == false)
        return ERROR_CAMPO;
    sscanf(act, "%f", &prod->precio);

    *act = '\0';
    act -= TAM_DESCRIPCION - 1;
    trim(act);
    strcpy(prod->descripcion, act);

    *act = '\0';
    act -= TAM_CODIGO - 1;
    trim(act);
    strcpy(prod->codigo, act);

    return TODO_OK;
}

/******************************************* Otras funciones *******************************************/

int cmpEstudiantesEmpleados (const Empleado* emp, const Estudiante* est)
{
    int res;
    if((res = miStrcmp(emp->apellido, est->apellido)) == 0)
    {
        if((res = miStrcmp(emp->nombre, est->nombre)) == 0)
            return (int)emp->dni - (int)est->dni;
    }
    return res;
}

bool controlCampoInt (const char* campo)
{
    while(ES_NUMERO(*campo))
        campo++;
    return *campo == '\0';
}

bool controlCampoFloat (const char* campo)
{
    while(ES_NUMERO(*campo))
        campo++;
    if(*campo != '.')
        return false;
    campo++;
    while(ES_NUMERO(*campo))
        campo++;
    return *campo == '\0';
}

bool controlCampoFecha (const char* campo)
{
    int i = 0;
    while(i++ < 2)
    {
        if(!ES_NUMERO(*campo) || !ES_NUMERO(*campo + 1))
            return false;
        campo += 2;
        if(*campo != '/')
            return false;
        campo++;
    }
    while(ES_NUMERO(*campo))
        campo++;
    return *campo == '\0';
}

bool esErrorFatal (int codRet)
{
    return codRet != TODO_OK;
}

int grabarErrorEnArchivo (FILE* archProdsErr, Producto* prod, int codRet)
{
    return fprintf(archProdsErr, "El producto %s no se pudo grabar en el archivo, informe de error %d", prod->codigo,codRet);
}
