#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//#include "../PilaEstatica/PilaEstatica.h"
//#include "../PilaDinamica/PilaDinamica.h"
#include "../PilaCircular/PilaCircular.h"

#define PATH_NUMEROS "numeros.txt"
#define A_ENTERO(X) (isdigit(X)? (X)-'0' : (X))
#define FIN_LINEA '\n'

bool sumarNumerosEnArchivoTxt (const char* nombreArchivo);

bool cargarEnterosEnPilaPorTeclado (Pila* pila, unsigned cantElem);

void pasarElementosAPilas (Pila* pila, Pila* pilaAux1, Pila* pilaAux2);
void pasarElementosAPila (Pila* pilaOrigen, Pila* pilaDestino);
void pasarElementosAPilaMenosValor (Pila* pilaOrigen, Pila* pilaDestino, int valor);
void pasarElementosAPilasMismoOrden (Pila* pilaOrigen, Pila* pilaDestino);
void invertirElementosPila (Pila* pila);
void ponerPrimerElementoAlTope (Pila* pila);
void ponerElementoTopeAlPrincipio (Pila* pila);
void repartirElementosPilaAPilasAlternado (Pila* pilaMazo, Pila* pilaJugador1, Pila* pilaJugador2);
int cmpPilasPorCantidadElementos (Pila* pilaA, Pila* pilaB);
bool cmpPilasPorCantidadElementosYValores (Pila* pilaA, Pila* pilaB);
void eliminarElementosPilaSegunElementoTope (Pila* pilaModelo, Pila* pila1);
void eliminarElementosPilaSegunElementosPila (Pila* pilaModelo, Pila* pila1);
void pasarElementosAPilasSegunTope (Pila* pilaLimite, Pila* pila1, Pila* pilaMenores, Pila* pilaMayores);

int main()
{
    if(sumarNumerosEnArchivoTxt(PATH_NUMEROS))
        puts("La suma se realizo correctamente en el archivo");
    else
        puts("Se produjo un error al realizar la suma");
    return 0;
}

/*Ejercicio 10: Resuelva el cálculo de la suma de dos números enteros de muchos dígitos (30 o
muchos más) haciendo uso de dos pilas en las que almacena sólo los dígitos. Tenga en
cuenta que debe utilizar una tercera pila en la que irá cargando los resultados parciales.
Compruebe que obtiene idénticos resultados con ambas implementaciones de
Pila (estática y dinámica)*/

bool sumarNumerosEnArchivoTxt (const char* nombreArchivo)
{
    FILE* pNumeros = fopen(nombreArchivo,"r+t");
    if(!pNumeros)
    {
        puts("No abrio el archivo");
        return false;
    }

    Pila pilaNumero1, pilaNumero2, pilaResultado;
    crearPila(&pilaNumero1);
    crearPila(&pilaNumero2);
    crearPila(&pilaResultado);

    char numeroChar;
    int numero1, numero2, resultado, carry = 0;

    ///Leemos el primer numero
    fscanf(pNumeros,"%c",&numeroChar);

    while(numeroChar != FIN_LINEA)
    {
        //Pasamos a entero
        numero1 = A_ENTERO(numeroChar);
        apilar(&pilaNumero1, &numero1, sizeof(numero1));
        //Leemos el proximo char
        fscanf(pNumeros, "%c", &numeroChar);
    }

    ///Leemos el segundo numero
    fscanf(pNumeros,"%c",&numeroChar);

    while(!feof(pNumeros))
    {
        //Pasamos a entero
        numero2 = A_ENTERO(numeroChar);
        apilar(&pilaNumero2, &numero2, sizeof(numero2));
        //Leemos el proximo char
        fscanf(pNumeros, "%c", &numeroChar);
    }

    ///Desapilamos ambas pilas y realizamos la suma por cada digito
    while(!pilaVacia(&pilaNumero1) || !pilaVacia(&pilaNumero2))
    {
        if(!desapilar(&pilaNumero1,&numero1,sizeof(numero1)))
            numero1 = 0;

        if(!desapilar(&pilaNumero2,&numero2,sizeof(numero2)))
            numero2 = 0;

        resultado = numero1 + numero2 + carry;

        if(resultado >= 10)
        {
            resultado %= 10;
            carry = 1;
        }
        else
            carry = 0;

        apilar(&pilaResultado,&resultado,sizeof(resultado));
    }

    if(carry)
        apilar(&pilaResultado,&carry,sizeof(carry));

    fprintf(pNumeros,"\n--------------\n");

    while(desapilar(&pilaResultado,&resultado,sizeof(resultado)))
        fprintf(pNumeros,"%d",resultado);

    fclose(pNumeros);

    return true;
}

/****************************** Ejercitación de Pilas ******************************/

/*1 - Crear/cargar Pila1 por teclado con 5 elementos. Poner los primeros tres elementos
de la PilaAux1 y los restantes a otra PilaAux2, ambas inicializadas en null/vacias.*/

bool cargarEnterosEnPilaPorTeclado (Pila* pila, unsigned cantElem)
{
    if(cantElem == 0)
        return false;

    int elem;

    for(int i = 0; i < cantElem; i++)
    {
        puts("Ingrese un elemento: ");
        scanf("%d", &elem);
        if(!apilar(pila, &elem, sizeof(int)))
            return false;
    }

    return true;
}

void pasarElementosAPilas (Pila* pila, Pila* pilaAux1, Pila* pilaAux2)
{
    int i = 0, elemento;
    while(desapilar(pila,&elemento,sizeof(elemento)))
    {
        if(i++ < 2)
            apilar(pilaAux2,&elemento,sizeof(elemento));
        else
            apilar(pilaAux1,&elemento,sizeof(elemento));
    }
}

/*2 - Cargar PilaOrigen por teclado e inicializar en vacio PilaDestino.
Pasar todos los elementos de PilaOrigen a la PilaDestino.*/

void pasarElementosAPila (Pila* pilaOrigen, Pila* pilaDestino)
{
    int elemento;

    while(desapilar(pilaOrigen,&elemento,sizeof(elemento)))
        apilar(pilaDestino,&elemento,sizeof(elemento));
}

/*3 - Cargar desde teclado PilaOrigen y pasar a PilaDestino todos aquellos elementos distintos a 8(ocho).*/

void pasarElementosAPilaMenosValor (Pila* pilaOrigen, Pila* pilaDestino, int valor)
{
    int elemento;

    while(desapilar(pilaOrigen,&elemento,sizeof(elemento)))
        if(elemento!=valor)
            apilar(pilaDestino,&elemento,sizeof(elemento));
}

/*4 - Cargar desde taclado PilaOrigen e inicializar (null) la PilaDestino.
Pasar los elementos de PilaOrigen a PilaDestino pero deben quedar en el mismo orden.*/

void pasarElementosAPilasMismoOrden (Pila* pilaOrigen, Pila* pilaDestino)
{
    int elemento;
    Pila pilaAux;
    crearPila(&pilaAux);

    while(desapilar(pilaOrigen,&elemento,sizeof(elemento)))
        apilar(&pilaAux,&elemento,sizeof(elemento));

    while(desapilar(&pilaAux,&elemento,sizeof(elemento)))
        apilar(pilaDestino,&elemento,sizeof(elemento));
}

/*5 - Cargar desde teclado Pila1. Invertir la pila para que Pila1 contenga los elementos
cargados originalmente en orden inverso.*/

void invertirElementosPila (Pila* pila)
{
    int elemento;
    Pila pilaAux1, pilaAux2;
    crearPila(&pilaAux1);
    crearPila(&pilaAux2);

    while(desapilar(pila,&elemento,sizeof(elemento)))
        apilar(&pilaAux1,&elemento,sizeof(elemento));

    while(desapilar(&pilaAux1,&elemento,sizeof(elemento)))
        apilar(&pilaAux2,&elemento,sizeof(elemento));

    while(desapilar(&pilaAux2,&elemento,sizeof(elemento)))
        apilar(pila,&elemento,sizeof(elemento));
}

/*6 - Pasar el primer elemento de la Pila1 a su última posición, dejando los restantes en el mismo orden.*/

void ponerPrimerElementoAlTope (Pila* pila)
{
    int elemento;
    Pila pilaAux;
    crearPila(&pilaAux);

    ///Ahora desapilamos los elementos de Pila1 y los apilamos en pilaAux
    while(desapilar(pila,&elemento,sizeof(elemento)))
        apilar(&pilaAux,&elemento,sizeof(elemento));

    ///En el tope de pilaAux, se encuentra el primer elemento de Pila1
    desapilar(&pilaAux,&elemento,sizeof(elemento));
    int primerElemento = elemento;

    ///Despues de guardarlo, desapilamos todo lo demas y lo volvemos a apilar en Pila1
    while(desapilar(&pilaAux,&elemento,sizeof(elemento)))
        apilar(pila,&elemento,sizeof(elemento));

    ///El primerElemento que quedo en guardado en la variable, lo apilamos
    apilar(pila,&primerElemento,sizeof(primerElemento));
}

/*7 - Pasar el último elemento de la Pila1 a su primera posición, dejando los restantes en el mismo orden.*/
void ponerElementoTopeAlPrincipio (Pila* pila)
{
    int ultimoElemento, elemento;
    Pila pilaAux;
    crearPila(&pilaAux);

    desapilar(pila,&ultimoElemento,sizeof(ultimoElemento));

    while(desapilar(pila,&elemento,sizeof(elemento)))
        apilar(&pilaAux,&elemento,sizeof(elemento));

    apilar(pila,&ultimoElemento,sizeof(ultimoElemento));

    while(desapilar(&pilaAux,&elemento,sizeof(elemento)))
        apilar(pila,&elemento,sizeof(elemento));
}

/*8 - Repartir los elementos de la PilaMazo en la PilaJugador1 y PilaJugador2 en forma alternada.*/
void repartirElementosPilaAPilasAlternado (Pila* pilaMazo, Pila* pilaJugador1, Pila* pilaJugador2)
{
    int elemento, i=0;
    while(desapilar(pilaMazo,&elemento,sizeof(elemento)))
    {
        if(i%2==0)
            apilar(pilaJugador1,&elemento,sizeof(elemento));
        else
            apilar(pilaJugador2,&elemento,sizeof(elemento));
        i++;
    }
}

/*9 - Comparar la cantidad de elementos de la PilaA y PilaB. Mostrar por pantalla el resultado.*/

int cmpPilasPorCantidadElementos (Pila* pilaA, Pila* pilaB)
{
    int elemento, cantidadElementosPA = 0, cantidadElementosPB = 0;

    while(desapilar(pilaA,&elemento,sizeof(elemento)))
        cantidadElementosPA++;

    while(desapilar(pilaB,&elemento,sizeof(elemento)))
        cantidadElementosPB++;

    return cantidadElementosPA - cantidadElementosPB;
    /*Devuelve 0 si PA = PB, devuelve negativo si PB > PA y positivo si PA > PB*/
}

/*10 - Comparar la cantidad de elementos de la PilaA y PilaB, evaluando si son complemente iguales
(en cant de elementos, valores y posiciones). Mostrar por pantalla el resultado.*/

bool cmpPilasPorCantidadElementosYValores (Pila* pilaA, Pila* pilaB)
{
    int elementoA, elementoB;
    bool valoresDistintos = false;
    while(!pilaVacia(pilaA) && !pilaVacia(pilaB) && !valoresDistintos)
    {
        desapilar(pilaA,&elementoA,sizeof(elementoA));
        desapilar(pilaB,&elementoB,sizeof(elementoB));
        if(elementoA != elementoB)
            valoresDistintos = true;
    }
    return pilaVacia(pilaA) && pilaVacia(pilaB) && !valoresDistintos;
    //printf("\nLa PilaA y PilaB son iguales, tanto en cantidad de elementos y valores iguales\n");
    //printf("\nLa PilaA y PilaB no son iguales\n");
}

/*11 - Suponiendo la existencia de PilaModelo no vacia, eliminar de la Pila1 todos los elementos que sean
iguales al tope de la PilaModelo.*/

void eliminarElementosPilaSegunElementoTope (Pila* pilaModelo, Pila* pila1)
{
    int elementoTope, elemento1;
    Pila pilaAux;
    crearPila(&pilaAux);
    desapilar(pilaModelo,&elementoTope,sizeof(elementoTope));

    while(desapilar(pila1,&elemento1,sizeof(elemento1)))
        if(elemento1!=elementoTope)
            apilar(&pilaAux,&elemento1,sizeof(elemento1));

    while(desapilar(&pilaAux,&elemento1,sizeof(elemento1)))
        apilar(pila1,&elemento1,sizeof(elemento1));
}

/*12 - Suponiendo la existencia de PilaModelo vacia o no, eliminar de la Pila1 todos los
elementos que existan en PilaModelo.*/

void eliminarElementosPilaSegunElementosPila (Pila* pilaModelo, Pila* pila1)
{
    int elementoModelo, elemento1;
    Pila pilaAux;
    crearPila(&pilaAux);
    while(desapilar(pilaModelo,&elementoModelo,sizeof(elementoModelo)))
    {
        while(desapilar(pila1,&elemento1,sizeof(elemento1)))
            if(elemento1 != elementoModelo)
                apilar(&pilaAux,&elemento1,sizeof(elemento1));

        while(desapilar(&pilaAux,&elemento1,sizeof(elemento1)))
            apilar(pila1,&elemento1,sizeof(elemento1));
    }
}

/*13 - Suponiendo la existencia de PilaLimite, pasar los elementos de la Pila1 que sean >= que
el tope de PilaLimite a la PilaMayores y los menores a la pilaMenores.*/

void pasarElementosAPilasSegunTope (Pila* pilaLimite, Pila* pila1, Pila* pilaMenores, Pila* pilaMayores)
{
    int elementoTope, elemento1;
    desapilar(pilaLimite,&elementoTope,sizeof(elementoTope));
    while(desapilar(pila1,&elemento1,sizeof(elemento1)))
    {
        if(elemento1 >= elementoTope)
            apilar(pilaMayores,&elemento1,sizeof(elemento1));
        else
            apilar(pilaMenores,&elemento1,sizeof(elemento1));
    }
}
