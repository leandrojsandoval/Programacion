#ifndef EJERCICIOS_HEADER_H_INCLUDED
#define EJERCICIOS_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

#define NUMERO_SIN_CLASIFICACION - 1
#define NUMERO_PERFECTO 1
#define NUMERO_DEFICIENTE 2
#define NUMERO_ABUNDANTE 3

int menuMatematicas();

double factorial (int numero);
double factorialRecursivo (int numero);
int combinatoria (int,int);
double eALaX (int, double);
float raizCuadrada (int,double);
bool fibonacci (int);
double seno (int,double);
int clasificarNumero (int numero);
int sumaSucesiva (int,int);
void cocienteResto (int, int);
int sumaPrimerosNumeros (int);
int sumaPrimerosNumerosPares (int);
int sumaPrimerosNumerosParesMenores (int);
bool esPrimo (int);
int productoMetodoRuso (int numero1, int numero2);

#endif // EJERCICIOS_HEADER_H_INCLUDED
