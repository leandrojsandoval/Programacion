#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "../Bibliotecas/PilaDinamica/PilaDinamica.h"
// #include "../Bibliotecas/PilaEstatica/PilaEstatica.h"
#include "../Bibliotecas/PilaCircular/PilaCircular.h"

// Sumar 9947389 57267 --> Poner estos numeros en Project -> Set programs' arguments

char* sumarNumeros(const char* num1, const char* num2);
bool apilarCeros(Pila* pila, int cantCeros);
bool apilarNumero(Pila* pila, const char* num);
void desapilarNumero(char* num, Pila* pila);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        puts("Error: Debe ingresar dos numeros enteros como argumentos");
        return 1;
    }
    char* suma = sumarNumeros(argv[1], argv[2]);
    printf("%s", suma);
    free(suma);
    return 0;
}

char* sumarNumeros(const char* num1, const char* num2) {
    Pila pila1, pila2, pilaSuma;
    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pilaSuma);

    int tamNum1 = strlen(num1);
    int tamNum2 = strlen(num2);
    int restaTams = tamNum1 - tamNum2;
    int cantCeros = abs(restaTams);

    apilarCeros(restaTams < 0 ? &pila1 : &pila2, cantCeros);
    apilarNumero(&pila1, num1);
    apilarNumero(&pila2, num2);

    int acarreo = 0, digito1, digito2, digitoSuma;
    char dig1C, dig2C, digSumaC;

    while (!pilaVacia(&pila1)) {
        desapilar(&pila1, &dig1C, sizeof(char));
        desapilar(&pila2, &dig2C, sizeof(char));
        digito1 = dig1C - '0';
        digito2 = dig2C - '0';
        digitoSuma = digito1 + digito2 + acarreo;
        acarreo = digitoSuma / 10;
        digitoSuma %= 10;
        digSumaC = digitoSuma + '0';
        apilar(&pilaSuma, &digSumaC, sizeof(char));
    }

    int tamSuma = tamNum1 > tamNum2 ? tamNum1 : tamNum2;

    if (acarreo == 1) {
        digSumaC = '1';
        apilar(&pilaSuma, &digSumaC, sizeof(char));
        tamSuma++;
    }

    char* suma = (char*)malloc(tamSuma + 1);
    if (!suma) {
        puts("Error: No se pudo reservar memoria para la suma");
        vaciarPila(&pilaSuma);
        return NULL;
    }

    desapilarNumero(suma, &pilaSuma);

    return suma;
}

bool apilarCeros(Pila* pila, int cantCeros) {
    char cero = '0';
    for (int i = 0; i < cantCeros; i++) {
        if (!apilar(pila, &cero, sizeof(char))) {
            puts("Error: No se pudo apilar un cero");
            return false;
        }
    }
    return true;
}

bool apilarNumero(Pila* pila, const char* num) {
    const char* i = num;
    while (*i) {
        if (!apilar(pila, i, sizeof(char))) {
            puts("Error: No se pudo apilar un digito");
            return false;
        }
        i++;
    }
    return true;
}

void desapilarNumero(char* num, Pila* pila) {
    char* i = num;
    while (!pilaVacia(pila)) {
        desapilar(pila, i, sizeof(char));
        i++;
    }
    *i = '\0';
}
