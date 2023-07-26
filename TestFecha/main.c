#include "../Bibliotecas/Fecha/Fecha.h"

int menuFechas();

int main() {
    system("chcp 1252 >nul");

    int dias;
    Fecha fecha, priFecha, segFecha;

    int opcion = menuFechas();
    while (opcion) {
        switch (opcion) {
            case 1:
                cargarFechaValida(&fecha);
                mostrarFecha(&fecha);
                break;
            case 2:
                cargarFechaValida(&fecha);
                sumarUnDia(&fecha);
                mostrarFecha(&fecha);
                break;
            case 3:
                cargarFechaValida(&fecha);
                puts("Ingrese la cantidad de dias a sumar:");
                scanf("%d", &dias);
                sumarNDias(&fecha, dias);
                mostrarFecha(&fecha);
                break;
            case 4:
                puts("Ingrese la cantidad de dias a restar:");
                scanf("%d", &dias);
                restarNDias(&fecha, dias);
                mostrarFecha(&fecha);
                break;
            case 5:
                cargarFechaValida(&priFecha);
                cargarFechaValida(&segFecha);
                printf("\nLa diferencia entre las fechas %02d/%02d/%04d y %02d/%02d/%04d es: %lu\n",
                       priFecha.dia, priFecha.mes, priFecha.anio,
                       segFecha.dia, segFecha.mes, segFecha.anio,
                       diferenciaEntreFechasV1(&priFecha, &segFecha));
                break;
            case 6:
                cargarFechaValida(&fecha);
                printf("\nLa fecha %02d/%02d/%04d corresponde al dia de la semana %d\n",
                       fecha.dia, fecha.mes, fecha.anio,
                       diaDeLaSemana(&fecha));
                printf("\nLa fecha %02d/%02d/%04d corresponde al dia de la semana %s\n",
                       fecha.dia, fecha.mes, fecha.anio,
                       diaDeLaSemanaStr(&fecha));
                break;
        }
        puts("");
        system("PAUSE");
        system("CLS");
        opcion = menuFechas();
    }

    return 0;
}

int menuFechas() {
    int opcion;
    puts("\t\t\tMenu Fechas");
    puts("-----------------------------------------------------------------------------");
    printf("\n1 - Ejercicio 14: Desarrollar una funcion que determine si una fecha es formalmente correcta.\n");
    printf("\n2 - Ejercicio 15: Desarrollar una funcion que a partir de una fecha obtenga la correspondiente al dia siguiente.\n");
    printf("\n3 - Ejercicio 16: Desarrollar una funcion que a partir de una fecha obtenga la que resulte de sumarle N dias.\n");
    printf("\n4 - Ejercicio 17: Desarrollar una funcion que a partir de una fecha obtenga la que resulte de restarle N dias.\n");
    printf("\n5 - Ejercicio 18: Desarrollar una funcion que a partir de dos fechas obtenga la cantidad de dias que hay entre ellas.\n");
    printf("\n6 - Ejercicio 19: Desarrollar una funcion que a partir de una fecha devuelva un entero que representa el dia de la semana que le corresponde (0: Domingo; 1: Lunes; 2: Martes; etc.)\n");
    printf("\n0 - Salir\n\n");
    puts("Ingrese una opcion: ");
    do {
        scanf("%d", &opcion);
    } while (opcion < 0 && opcion > 6);
    return opcion;
}
