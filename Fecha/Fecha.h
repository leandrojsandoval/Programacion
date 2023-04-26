#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define ERROR_FECHA_INVALIDA -5
#define VERDADERO 1
#define FALSO 0
#define ANIO_BASE 1601
#define ES_BISIESTO(X) (((X)%4 == 0 && (X)%100 != 0) || (X)%400 == 0)
#define ES_MAYOR_O_IGUAL_FECHA(X,Y) ((((X)->anio * 100 + (X)->mes) * 100 + (X)->dia) >= (((Y)->anio * 100 + (Y)->mes) * 100 + (Y)->dia))

typedef struct
{
    int dia, mes, anio;
} Fecha;

void mostrarFecha (const Fecha* f);
int cantDiasMes (int mes, int anio);
int esFechaValida (const Fecha* f);
void cargarFechaValida (Fecha* f);
void sumarUnDia (Fecha* f);
void sumarNDias (Fecha* f, int dias);
void restarNDias (Fecha* f, int dias);
int getDiaRel (const Fecha* f);
long diferenciaEntreFechasV1 (const Fecha* f1, const Fecha* f2);
long diferenciaEntreFechasV1 (const Fecha* f1, const Fecha* f2);
int diaDeLaSemana (const Fecha* f);
char* diaDeLaSemanaStr (const Fecha* f);

#endif // FECHA_H_INCLUDED
