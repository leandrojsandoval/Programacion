#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "../ColaDinamica/ColaDinamica.h"
//#include "../ColaEstatica/ColaEstatica.h"
#include "../ColaCircular/ColaCircular.h"

#define TAM_CLIENTES 10

typedef struct
{
    unsigned dni;
    char nombre[50];
    char apellido[50];
} Cliente;

int tiempoAleatorioDeSalida();
int tiempoAleatorioDeEntrada();
int generarValorAleatorio(int limInf, int limSup);
void mostrarCliente(const Cliente* cliente);

int main()
{
    system("chcp 1252 >nul");
    srand(time(NULL));

    Cola colaClientes;
    crearCola(&colaClientes);

    Cliente vClientes[TAM_CLIENTES] =
    {
        {12345678,"Francisco","Fern�ndez"},
        {11111111,"Milagros","Ag�ero"},
        {78901234,"Martin","G�mez"},
        {44444444,"Florencia","G�mez"},
        {55555555,"Sofia","Morales"},
        {56789012,"Lautaro","Guti�rrez"},
        {34567890,"M�nica","Mart�nez"},
        {22222222,"Camila","Gonz�lez"},
        {33333333,"Pedro","Fern�ndez"},
        {90123456,"Juan","V�squez"},
    };

    int cantVecesColaVacia = 0;
    Cliente cliente;

    int minutosEntrada = tiempoAleatorioDeEntrada();
    int minutosSalida = tiempoAleatorioDeSalida();

    while(cantVecesColaVacia < 5)
    {
        cliente = vClientes[generarValorAleatorio(0,9)];
        encolar(&colaClientes, &cliente, sizeof(Cliente));
        puts("Ingreso el cliente:");
        mostrarCliente(&cliente);
        while(!colaVacia(&colaClientes))
        {
            if(minutosEntrada == 0)
            {
                cliente = vClientes[generarValorAleatorio(0,TAM_CLIENTES - 1)];
                encolar(&colaClientes, &cliente, sizeof(Cliente));
                puts("Ingreso el cliente:");
                mostrarCliente(&cliente);
                minutosEntrada = tiempoAleatorioDeEntrada();
            }
            if(minutosSalida == 0)
            {
                desencolar(&colaClientes, &cliente, sizeof(Cliente));
                puts("Sali� el cliente:");
                mostrarCliente(&cliente);
                minutosSalida = tiempoAleatorioDeSalida();
            }
            minutosEntrada--;
            minutosSalida--;
        }
        cantVecesColaVacia++;
    }
    return 0;
}

void mostrarCliente(const Cliente* cliente)
{
    printf("DNI: %d\n", cliente->dni);
    printf("Nombre: %s\n", cliente->nombre);
    printf("Apellido: %s\n", cliente->apellido);
    putchar('\n');
}

int tiempoAleatorioDeSalida()
{
    int numeroRandom = generarValorAleatorio(1, 3);
    return numeroRandom == 2? 5 : numeroRandom;
}

int tiempoAleatorioDeEntrada()
{
    int numeroRandom = generarValorAleatorio(1, 3);
    return numeroRandom == 2? 5 : numeroRandom == 3? 9 : 1;
}

int generarValorAleatorio(int limInf, int limSup)
{
    return rand () % (limSup - limInf + 1) + limInf;
}
