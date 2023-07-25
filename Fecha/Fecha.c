#include "Fecha.h"

void mostrarFecha(const Fecha* f) {
    printf("\nLa fecha es: %02d/%02d/%04d\n", f->dia, f->mes, f->anio);
}

/*Ejercicio 14: Desarrollar una funcion que determine si una fecha es formalmente correcta.*/

void cargarFechaValida(Fecha* f) {
    puts("Ingrese una fecha (D/M/A): ");
    fflush(stdin);
    scanf("%d/%d/%d", &f->dia, &f->mes, &f->anio);
    while (!esFechaValida(f)) {
        puts("Fecha invalida. Ingrese una fecha (D/M/A): ");
        fflush(stdin);
        scanf("%d/%d/%d", &f->dia, &f->mes, &f->anio);
    }
}

int esFechaValida(const Fecha* f) {
    if (f->anio >= ANIO_BASE)
        if (f->mes >= 1 && f->mes <= 12)
            if (f->dia >= 1 && f->dia <= cantDiasMes(f->mes, f->anio))
                return VERDADERO;
    return FALSO;
}

int cantDiasMes(int mes, int anio) {
    static char cmd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return mes == 2 && ES_BISIESTO(anio) ? 29 : cmd[mes];
}

/*Ejercicio 15: Desarrollar una funcion que a partir de una fecha obtenga la correspondiente al
dia siguiente.*/

void sumarUnDia(Fecha* f) {
    f->dia++;
    if (f->dia > cantDiasMes(f->mes, f->anio)) {
        f->dia = 1;
        f->mes++;
    }
    if (f->mes > 12) {
        f->mes = 1;
        f->anio++;
    }
}

/*Ejercicio 16: Desarrollar una funcion que a partir de una fecha obtenga la que resulte de
sumarle N dias*/

void sumarNDias(Fecha* f, int dias) {
    int cdm;
    f->dia += dias;
    while (f->dia > (cdm = cantDiasMes(f->mes, f->anio))) {
        f->dia -= cdm;
        f->mes++;
        if (f->mes > 12) {
            f->mes = 1;
            f->anio++;
        }
    }
}

/*Ejercicio 17: Desarrollar una funcion que a partir de una fecha obtenga la que resulte de res-tarle
N dias.*/

void restarNDias(Fecha* f, int dias) {
    f->dia -= dias;
    while (f->dia < 1) {
        f->dia += cantDiasMes(f->mes, f->anio);
        f->mes--;
        if (f->mes < 1) {
            f->mes = 12;
            f->anio--;
        }
    }
}

/*Ejercicio 18: Desarrollar una funcion que a partir de dos fechas obtenga la cantidad de dias que
hay entre ellas*/

long diferenciaEntreFechasV1(const Fecha* f1, const Fecha* f2) {
    Fecha fechaHasta = ES_MAYOR_O_IGUAL_FECHA(f1, f2) ? *f1 : *f2;
    Fecha fechaDesde = !ES_MAYOR_O_IGUAL_FECHA(&fechaHasta, f1) ? *f2 : *f1;
    long dias = fechaHasta.dia;
    if (fechaDesde.anio != fechaHasta.anio) {
        fechaHasta.mes--;
        while (fechaHasta.mes >= 1) {
            dias += cantDiasMes(fechaHasta.mes, fechaHasta.anio);
            fechaHasta.mes--;
        }
        fechaHasta.anio--;
        while (fechaHasta.anio > fechaDesde.anio) {
            dias += ES_BISIESTO(fechaHasta.anio) ? 366 : 365;
            fechaHasta.anio--;
        }
        fechaHasta.mes = 12;
        while (fechaHasta.mes > fechaDesde.mes) {
            dias += cantDiasMes(fechaHasta.mes, fechaHasta.anio);
            fechaHasta.mes--;
        }
    } else if (fechaDesde.mes != fechaHasta.mes) {
        fechaHasta.mes--;
        while (fechaHasta.mes > fechaDesde.mes) {
            dias += cantDiasMes(fechaHasta.mes, fechaHasta.anio);
            fechaHasta.mes--;
        }
    } else {
        return fechaHasta.dia - fechaDesde.dia;
    }
    return dias + cantDiasMes(fechaDesde.mes, fechaDesde.anio) - fechaDesde.dia;
}

int getDiaRel(const Fecha* f) {
    Fecha fechaAux = *f;
    long dias = fechaAux.dia;
    fechaAux.mes--;
    while (fechaAux.mes >= 1) {
        dias += cantDiasMes(fechaAux.mes, fechaAux.anio);
        fechaAux.mes--;
    }
    fechaAux.anio--;
    while (fechaAux.anio >= ANIO_BASE) {
        dias += ES_BISIESTO(fechaAux.anio) ? 366 : 365;
        fechaAux.anio--;
    }
    return dias;
}

long diferenciaEntreFechasV2(const Fecha* f1, const Fecha* f2) {
    return abs(getDiaRel(f1) - getDiaRel(f2));
}

/*Ejercicio 19: Desarrollar una funcion que a partir de una fecha devuelva un entero que
representa el dia de la semana que le corresponde (0: Domingo; 1: Lunes; 2: Martes;�etc.)*/

int diaDeLaSemana(const Fecha* f) {
    return getDiaRel(f) % 7;
}

char* diaDeLaSemanaStr(const Fecha* f) {
    static char* vectorDiaSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    return vectorDiaSemana[diaDeLaSemana(f)];
}
