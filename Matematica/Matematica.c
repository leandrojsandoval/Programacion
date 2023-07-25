#include "Matematica.h"

int menuMatematicas() {
    int opcion;
    printf("\nMenu Principal - Funciones Matematicas\n");
    printf("---------------------------------------\n");
    printf("\n1) Factorial\n");
    printf("\n2) Combinatoria\n");
    printf("\n3) e^x\n");
    printf("\n4) Raiz Cuadrada\n");
    printf("\n5) Fibonacci\n");
    printf("\n6) Seno\n");
    printf("\n7) Clasificar numero en perfecto, abundante y deficiente\n");
    printf("\n8) Producto mediante sumas sucesivas\n");
    printf("\n9) Cociente y resto\n");
    printf("\n10) Suma primeros N numeros naturales\n");
    printf("\n11) Suma primeros N numeros naturales pares\n");
    printf("\n12) Suma primeros N numeroes naturales pares menores que N\n");
    printf("\n13) Primo\n");
    printf("\n0) Salir\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 13);
    return opcion;
}

/*Ejercicio 1: El factorial de un número natural incluido el 0, se calcula de la siguiente manera:

    1 si N = 0
    N! = N*(N - 1)! si N > 0
    o sea, N! = N*(N - 1)*(N - 2) ...

Ejemplo: 5! = 5*4*3*2*1 = 120
Desarrollar una función para calcular el factorial de un entero.*/

double factorial(int numero) {
    int i;
    double resultado = 1;
    if (numero < 0)
        return 0;
    for (i = 2; i <= numero; i++)
        resultado *= i;
    return resultado;
}

double factorialRecursivo(int numero) {
    return !numero ? 1 : numero * factorialRecursivo(numero - 1);
}

/*Ejercicio 2: Dados dos números enteros m y n (m >= n y n>= 0), el número combinatorio se
calcula de la siguiente manera:
    m(n) = m ! / (n! * (m−n)!)
Desarrollar una función para calcular el combinatorio m sobre n.*/

int combinatoria(int m, int n) {
    int res;
    if (m >= n && n >= 0) {
        res = factorial(m) / (factorial(n) * factorial(m - n));
        return res;
    }
    return -1;
}

/*Ejercicio 3: Dado un número entero X y una tolerancia (TOL), puede obtenerse e x mediante
la suma de los términos de la serie:
    e^x = 1 + (X^1/1) + ( X^2/(1*2)) + ( X^3/(1*2*3)) + ( X^4/(1*2*3*4)) + ...
El proceso termina cuando se obtiene un término calculado que sea menor que la tolerancia TOL.
Desarrollar una función para calcular el e^x, dados X y TOL.*/

double eALaX(int exp, double tolerancia) {
    double termino = 1, resultado = 1;
    int i = 1;
    while (termino > tolerancia) {
        termino *= (double)exp / i;
        resultado += termino;
        i++;
    }
    return resultado;
}

/*Ejercicio 4: La raíz cuadrada de un número positivo A puede calcularse mediante un proceso iterativo que genera términos según la siguiente fórmula:
    R1 = 1
    Ri = 1 /2( Ri−1+( A / Ri− 1))
El proceso de cálculo se da por terminado cuando la diferencia entre dos términos sucesivos es menor que una cota fijada de antemano.
Desarrollar una función para calcular la raíz cuadrada de X con una tolerancia TOL.*/

float raizCuadrada(int numero, double tolerancia) {
    float resultadoAnterior = 1, resultadoActual = 1;
    do {
        resultadoAnterior = resultadoActual;
        resultadoActual = 0.5 * (resultadoAnterior + (numero / resultadoAnterior));
    } while (fabs(resultadoAnterior - resultadoActual) >= tolerancia);
    return resultadoActual;
}

/*Ejercicio 5: En la serie de Fibonacci, cada término es la suma de los dos anteriores y los
dos primeros términos son 1
    Serie: 1    1   2   3   5   8   13  21  34 ...
Desarrollar una función para determinar si un entero pertenece a la serie de Fibonacci.*/

bool fibonacci(int numero) {
    int anteultimoNumero = 0, ultimoNumero = 1, siguienteNumero = 1;
    if (numero <= 0) {
        return 0;
    }
    while (numero > siguienteNumero) {
        siguienteNumero = anteultimoNumero + ultimoNumero;
        anteultimoNumero = ultimoNumero;
        ultimoNumero = siguienteNumero;
    }
    return numero == siguienteNumero;
}

/*Ejercicio 6: Dados X y una tolerancia TOL es posible calcular el seno (x) mediante la suma
de los términos de la serie:
    seno(x) = x - x^3/ 3! + x^5/ 5! - x^7/ 7! + x^9/ 9! - x^11 / 11! + ...
Este proceso continúa mientras el termino calculado (en valor absoluto) sea mayor que la tolerancia.
Desarrollar una función que obtenga el seno de X con tolerancia TOL, utilizando dicha serie.*/

double seno(int numero, double tolerancia) {
    int i = 1, signo = 1;
    double termino, resultado = 0;
    do {
        termino = (signo) * (pow(numero, i) / factorial(i));
        signo *= -1;
        i += 2;
        resultado += termino;
    } while (fabs(termino) > tolerancia);
    return resultado;
}

/*Ejercicio 7: Un número natural es perfecto, deficiente o abundante según que la suma de
sus divisores positivos menores que él sea igual, menor o mayor que él. Por ejemplo:

    Número  Divisores positivos menores que él   Suma de los divisores   Clasificación
    6       1, 2, 3                                 6                      PERFECTO
    10      1, 2, 5                                 8                      DEFICIENTE
    12      1, 2, 3, 4, 6                           16                     ABUNDANTE

Desarrollar una función que determine si un número natural es perfecto, deficiente
o abundante.*/

int clasificarNumero(int numero) {
    if (numero <= 0)
        return NUMERO_SIN_CLASIFICACION;
    int suma = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0)
            suma += i;
    }
    return suma == numero ? NUMERO_PERFECTO : suma < numero ? NUMERO_DEFICIENTE
                                                            : NUMERO_ABUNDANTE;
}

/*Ejercicio 8: Dados dos números naturales (incluido el cero), obtener su producto por sumas
sucesivas.*/

int sumaSucesiva(int numero1, int numero2) {
    int i, resultado = 0;
    for (i = 0; i < numero2; i++) {
        resultado += numero1;
    }
    return resultado;
}

/*Ejercicio 9: Dados dos números naturales A y B, desarrollar una función para obtener el cociente
entero A/B y el resto. (A puede ser 0; B, no).*/

void cocienteResto(int numero1, int numero2) {
    if (numero2 <= 0 || numero1 < 0) {
        printf("\nNo es posible realizar la division\n");
        return;
    }
    int i = 0, resto = numero1;
    do {
        resto -= numero2;
        i++;
    } while (numero2 < resto);
    printf("\nEl cociente de la division entre %d y %d es %d, y su resto es %d", numero1, numero2, i, resto);
}

/*Ejercicio 10: Construir un programa que lea un número natural N y calcule la suma de los primeros
N números naturales.*/

int sumaPrimerosNumeros(int numero) {
    int i, suma = 0;
    for (i = 1; i <= numero; i++)
        suma += i;
    return suma;
}

/*Ejercicio 11: Construir un programa que lea un número natural N y calcule la suma de los primeros
N números pares.*/

int sumaPrimerosNumerosPares(int numero) {
    int suma = 0;
    for (int i = 1; i <= numero; i++)
        if (i % 2 == 0)
            suma += i;
    return suma;
}

/*Ejercicio 12: Construir un programa que lea un número natural N y calcule la suma de los números
pares menores que N.*/

int sumaPrimerosNumerosParesMenores(int numero) {
    int suma = 0;
    for (int i = 1; i < numero; i++)
        if (i % 2 == 0)
            suma += i;
    return suma;
}

/*Ejercicio 13: Desarrollar una función que determine si un número natural es primo.*/

bool esPrimo(int numero) {
    int divisor = numero, contador = 0;
    while (divisor > 0) {
        if (numero % divisor == 0) {
            contador++;
        }
        divisor--;
    }
    return contador == 2;
}

/*Ejercicio 20: El metodo de multiplicacion rusa de dos numeros naturales, consiste en lo siguiente:
Se divide sucesivamente por 2 (division entera) a uno de sus factores hasta obtener 1.
Paralelamente, se multiplica sucesivamente por 2 al otro factor.
La suma de estos ultimos numeros obtenidos que se correspondan con numeros impares obtenidos en las divisiones,
es el producto buscado (Se consideran los factores originales para la suma correspondiente).
Por ejemplo para: 35 x 8
    35  8                   8,16 y 256 se conrresponden con impares (35, 17 y 1)
    17  16                  8+16+256=280
    8   32
    4   64
    2   128
    1   256*/

int productoMetodoRuso(int numero1, int numero2) {
    int resultado = 0;
    while (numero1 >= 1) {
        if (numero1 % 2 != 0) {
            resultado += numero2;
        }
        numero1 /= 2;
        numero2 *= 2;
    }
    return resultado;
}

/*Ejercicio 21: Desarrollar una funcion para obtener la parte entera de un numero real*/
int parteEnteraDeUnReal(double numero) {
    return numero - (numero - (int)numero);
}
