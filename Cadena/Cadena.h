#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../Generico/Generico.h"
#include "Ocurrencia.h"
#include "Palabra.h"

/***************************************** Macros ******************************************/

#define NO_NUMERO 0

#define TAM_ABECEDARIO 27
#define TAM 100
#define TAM_TEXTO 2000

#define FILA_TILDE 0
#define FILA_SIN_TILDE 1

#define MINIMO(X,Y) ((X)>(Y)? (Y) : (X))

#define OFFSET_ASCII ('a'-'A')
#define OFFSET_ENTERO ('0')

#define ES_NUMERO(X) ((X)>='0' && (X)<='9')
#define ES_MINUSCULA(X) ((X)>='a' && (X)<='z')
#define ES_TILDE_MINUSCULA(X) ((X)== 'á' || (X)== 'é' || (X)== 'í' || (X)== 'ó' || (X)== 'ú')
#define ES_DIERESIS_MINUSCULA(X) ((X) == 'ä' || (X) == 'ë' || (X) == 'ï' || (X) == 'ö' || (X) == 'ü')
#define ES_BLANCO(X) ((X) == ' ' || (X) == '\n' || (X) == '\t')

#define ES_MAYUSCULA(X) ((X)>='A' && (X)<='Z')
#define ES_TILDE_MAYUSCULA(X) ((X)== 'Á' || (X)== 'É' || (X)== 'Í' || (X)== 'Ó' || (X)== 'Ú')
#define ES_DIERESIS_MAYUSCULA(X) ((X) == 'Ä' || (X) == 'Ë' || (X) == 'Ï' || (X) == 'Ö' || (X) == 'Ü')

#define ES_TILDE(X) (ES_TILDE_MAYUSCULA(X) || ES_TILDE_MINUSCULA(X))
#define ES_DIERESIS(X) (ES_DIERESIS_MAYUSCULA(X) || ES_DIERESIS_MINUSCULA(X))
#define ES_ENIE(X) ((X) == 'ñ' || (X) == 'Ñ')

#define ES_LETRA(X) (ES_MAYUSCULA(X) || ES_MINUSCULA(X) || ES_TILDE(X) || ES_ENIE(X) || ES_DIERESIS(X))
#define ES_ALFANUMERICO(X) (ES_LETRA(X) || ES_NUMERO(X))
#define ES_VOCAL(X) (MI_TOLOWER(X)=='a' || MI_TOLOWER(X)=='e' || MI_TOLOWER(X)=='i' || MI_TOLOWER(X)=='o' || MI_TOLOWER(X)=='u')

/*************************************** ctype.h ****************************************/

///Convierte un numero ASCII a un numero entero
#define MI_TONUMINT(X) (ES_NUMERO(X)? (X) - OFFSET_ENTERO : (X))
///Convierte un numero entero a un numero ASCII
#define MI_TOASCII(X) ((X) >= 0 && (X) <= 9 ? (X) + OFFSET_ENTERO : (X))
///Convierte un caracter en minuscula a mayuscula
#define MI_TOUPPER(X) ((ES_MINUSCULA(X) || ES_TILDE_MINUSCULA(X) || ES_DIERESIS_MINUSCULA(X) || (X) == 'ñ')? ((X) - OFFSET_ASCII) : (X))
///Convierte un caracter en mayuscula a minuscula
#define MI_TOLOWER(X) ((ES_MAYUSCULA(X) || ES_TILDE_MAYUSCULA(X) || ES_DIERESIS_MAYUSCULA(X) || (X) == 'Ñ')? ((X) + OFFSET_ASCII) : (X))
///Convierte un caracter con tilde al caracter sin tilde
int toSinTilde (int c);

/*************************************** string.h ****************************************/

size_t miStrlen (const char* s);                                        ///Devuelve la cantidad de caracteres
int miStrcmp (const char* s1, const char* s2);                          ///Compara dos cadenas (0 s1 = s2, + s1 > s2, - s1 < s2)
int miStrcmpi (const char* s1, const char* s2);                         ///Compara dos cadenas ignorando si son mayus o minus
char* miStrcpy (char* s1, const char* s2);                              ///Copia la segunda cadena en la primera
char* miStrdup (const char* s1);                                        ///Duplica una cadena (usa memoria dinamica)
char* miStrncpy (char *s1, const char *s2, size_t n);                   ///Lo mismo que strcpy pero hasta n
char* miStrcat (char* s1, const char* s2);                              ///Concatena la segunda cadena al final de la primera
char* miStrchr (char* s, int c);                                        ///Devuelve la direccion de la primera aparicion del caracter
char* miStrrchr (char* s, int c);                                       ///Devuelve la direccion de la ultima aparicion del caracter
char* miStrstr (const char* s1, const char* s2);                        ///Devuelve la direccion de la cadena en donde se encuentra la subcadena
char* miStrlwr (char* s);                                               ///Pasa los caracteres de la cadena que esten en mayusculas a minusculas
char* miStrupr (char* s);                                               ///Pasa los caracteres de la cadena que esten en minusculas a mayusculas
char* miStrrev (char* s);                                               ///Invierte la cadena

/******************************* Otras funciones de cadenas *******************************/

int miStrcmpSubcadena (const char* s1, const char* s2);                 ///Se fija si la subcadena se encuentra dentro de la cadena
const char* saltarLetraValI (const char* cad);                          ///Devuelve la direccion a la primera letra que se encuentre desde la izquierda
const char* saltarLetraValD (const char* cad, const char* limIzq);      ///Devuelve la direccion a la primera letra que se encuentre desde la derecha
char* trim (char* cadena);                                              ///Saca los espacios de la cadena que puede tener al final
bool esPalindromo (const char* s);                                      ///Una palabra es palindromo si coinciden las letras del principio con el final
int miAtoi (const char* cadena);                                        ///Convierte una cadena de caracteres a un entero
char* miItoa (int numero, char* cadena);                                ///Convierte un numero a una cadena de caracteres
bool esAnagrama (const char* s1, const char* s2);                       ///Dos palabras con las mismas letras pero que forman palabras distintas
int cantidadPalabras (const char* texto);                               ///Devuelve la cantidad de palabras de una cadana
int longitudPalabraMasLarga (const char* texto);                        ///Devuelve la longitud de la palabra mas larga de una cadena
void mostrarTopOcurrencias (const char* texto, int top);                ///Muestra las palabras que se encuentran en la cadena indicando el top de ocurrencias
int contarVocales (const char * cadena);                                ///Devuelve la cantidad de vocales de una cadena

/************************************ Normalizacion ************************************/

void normalizarATitulo (const char* textoOrig, char* destoDest);        ///Pone la cadena en formato 'Esta Es Una Cadena'
void normalizarAMinuscula (const char* textoOrig, char* textoDest);     ///Pone la cadena en formato 'esta es una cadena'
void normalizarAMayuscula (const char* textoOrig, char* textoDest);     ///Pone la cadena en formato 'ESTA ES UNA CADENA'
void normalizarAOracion (const char* textoOrig, char* textoDest);       ///Pone la cadena en formato 'Esta es una cadena'
void normalizarABibliografia (const char* textoOrig, char* textoDest);  ///Pone la cadena en formato

/****************************** Encriptado/Desencriptado ******************************/

///Ejercicio de Renata
void intercambioDeCaracteres (char* s1, char* s2);                      ///Intercambia los caracteres luego de un numero que indice cuantos caracteres se deben intercambiar
char* desplazarUnCaracter (char* s);                                    ///Ejemplo: abc3defg --> abcfedg
char* intercambiarCaracteresSegunNumero (char* cadena);

///Ejercicio de Loom
char* invertirPalabras (char* cadena);
char caracterDesencriptado (char* conjunto, char letra);
char* desofuscarCadena (char* cadena);

#endif // CADENA_H_INCLUDED
