#include "Matriz.h"

int menuMatrices() {
    int opcion;
    printf("------------------------------\n");
    printf("\n\tMenu matrices\n");
    printf("\n------------------------------\n");
    printf("\n1) Cargar matriz\n");
    printf("\n2) Mostrar matriz\n");
    printf("\n3) Menu mostrar matriz DS\n");
    printf("\n4) Menu mostrar matriz DP\n");
    printf("\n5) Menu suma matriz DS\n");
    printf("\n6) Menu suma matriz DP\n");
    printf("\n7) Definir si la matriz es diagonal\n");
    printf("\n8) Definir si la matriz es identidad\n");
    printf("\n9) Definir si la matriz es simetrica\n");
    printf("\n10) Trasponer matriz\n");
    printf("\n11) Crear matriz traspuesta cuadrada\n");
    printf("\n12) Producto de matrices\n");
    printf("\n0) Salir\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 12);
    return opcion;
}

int menuMostrarDS() {
    int opcion;
    printf("\n1) Mostrar diagonal secundaria\n");
    printf("\n2) Mostrar elementos abajo de la diagonal secundaria (incluida)\n");
    printf("\n3) Mostrar elementos abajo de la diagonal secundaria\n");
    printf("\n4) Mostrar elementos arriba de la diagonal secundaria (incluida)\n");
    printf("\n5) Mostrar elementos arriba de la diagonal secundaria\n");
    printf("\n0) Atras\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 5);
    return opcion;
}

int menuMostrarDP() {
    int opcion;
    printf("\n1) Mostrar diagonal principal\n");
    printf("\n2) Mostrar elementos abajo de la diagonal principal (incluida)\n");
    printf("\n3) Mostrar elementos abajo de la diagonal principal\n");
    printf("\n4) Mostrar elementos arriba de la diagonal principal (incluida)\n");
    printf("\n5) Mostrar elementos arriba de la diagonal principal\n");
    printf("\n0) Atras\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 5);
    return opcion;
}

int menuSumaDP() {
    int opcion;
    printf("\n1) Sumar elementos de la diagonal principal\n");
    printf("\n2) Sumar elementos arriba de la diagonal principal (incluida)\n");
    printf("\n3) Sumar elementos arriba de la diagonal princial\n");
    printf("\n4) Sumar elementos abajo de la diagonal principal (incluida)\n");
    printf("\n5) Sumar elementos abajo de la diagonal princial\n");
    printf("\n0) Atras\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 5);
    return opcion;
}

int menuSumaDS() {
    int opcion;
    printf("\n1) Sumar elementos de la diagonal secundaria\n");
    printf("\n2) Sumar elementos arriba de la diagonal secundaria (incluida)\n");
    printf("\n3) Sumar elementos arriba de la diagonal secundaria\n");
    printf("\n4) Sumar elementos abajo de la diagonal secundaria (incluida)\n");
    printf("\n5) Sumar elementos abajo de la diagonal secundaria\n");
    printf("\n0) Atras\n");
    do {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 5);
    return opcion;
}

///**************************************************************************************************************///

void cargarMatriz(int matriz[][TAM], int fila, int columna) {
    int i, j;
    for (i = 0; i < fila; i++)
        for (j = 0; j < columna; j++) {
            printf("\nFila %d | Columna %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
}

void mostrarMatriz(int matriz[][TAM], int fila, int columna) {
    int i, j;
    printf("\n");
    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++)
            printf(" %5d\t", matriz[i][j]);
        printf("\n");
    }
}

/// Diagonal secundaria

void mostrarDS(int matriz[][TAM], int orden) {
    int i;
    printf("\n");
    for (i = 0; i < orden; i++)
        printf("%d ", matriz[i][orden - i - 1]);
    printf("\n");
}

void mostrarElementosAbajoDS(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = orden - i - 1; j < orden; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosAbajoSinDS(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = orden - i; j < orden; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosArribaDS(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = 0; j < orden - i; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosArribaSinDS(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden - 1; i++)
        for (j = 0; j < orden - i - 1; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

/// Diagonal principal

void mostrarDP(int matriz[][TAM], int orden) {
    int i;
    printf("\n");
    for (i = 0; i < orden; i++)
        printf("%d ", matriz[i][i]);
    printf("\n");
}

void mostrarElementosArribaDP(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = i; j < orden; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosArribaSinDP(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = i + 1; j < orden; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosAbajoDP(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = 0; j <= i; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

void mostrarElementosAbajoSinDP(int matriz[][TAM], int orden) {
    int i, j;
    printf("\n");
    for (i = 0; i < orden; i++)
        for (j = 0; j < i; j++)
            printf("%d ", matriz[i][j]);
    printf("\n");
}

/*Ejercicio 29: Desarrollar una funci�n para que, dada una matriz cuadrada de reales de
orden N, obtenga la sumatoria de los elementos que est�n por encima de la diagonal principal
(excluida �sta).
Lo mismo para la diagonal secundaria.
Lo mismo incluyendo la diagonal.
Lo mismo, con los que est�n por debajo de la diagonal.*/

/// Diagonal principal

int sumaElementosAbajoDP(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = 0; j <= i; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosAbajoSinDP(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = 0; j < i; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosArribaDP(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = i; j < orden; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosArribaSinDP(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = i + 1; j < orden; j++)
            resultado += matriz[i][j];
    return resultado;
}

/// Diagonal secundaria

int sumaElementosArribaSinDS(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden - 1; i++)
        for (j = 0; j < orden - i - 1; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosArribaDS(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = 0; j < orden - i; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosAbajoSinDS(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = orden - i; j < orden; j++)
            resultado += matriz[i][j];
    return resultado;
}

int sumaElementosAbajoDS(int matriz[][TAM], int orden) {
    int i, j, resultado = 0;
    for (i = 0; i < orden; i++)
        for (j = orden - i - 1; j < orden; j++)
            resultado += matriz[i][j];
    return resultado;
}

/*Ejercicio 30: Desarrollar una funci�n para que, dada una matriz cuadrada de enteros de
orden N, obtenga la traza de la misma (sumatoria de los elementos de la diagonal principal).
Lo mismo, pero con la diagonal secundaria.*/

int sumaDS(int matriz[][TAM], int orden) {
    int i;
    float resultado = 0;
    for (i = 0; i < orden; i++)
        resultado += matriz[i][orden - i - 1];
    return resultado;
}

int sumaDP(int matriz[][TAM], int orden) {
    int i;
    float resultado = 0;
    for (i = 0; i < orden; i++)
        resultado += matriz[i][i];
    return resultado;
}

/*Ejercicio 31: Desarrollar una funci�n que determine si una matriz cuadrada de enteros de
orden N es matriz diagonal (ceros en todos sus elementos excepto en la diagonal principal).*/

int esDiagonal(int matriz[][TAM], int fila, int columna) {
    int i, j, esCero = 0;
    if (fila != columna)
        return 0;
    for (i = 0; i < fila; i++)
        for (j = 0; j < columna; j++)
            if (matriz[i][j] == 0 && i != j)
                esCero++;
    return esCero == (fila * fila) - fila;
}

/*Ejercicio 32: Desarrollar una funci�n que determine si una matriz cuadrada de enteros de
orden N es matriz identidad (matriz diagonal, con unos en la diagonal principal y ceros enlos
restantes).*/

int esIdentidad(int matriz[][TAM], int fila, int columna) {
    int i;
    if (fila != columna)
        return 0;
    if (esDiagonal(matriz, fila, columna))
        for (i = 0; matriz[i][i] == 1 && i < fila; i++)
            ;
    return i == fila;
}

/*Ejercicio 33: Desarrollar una funci�n que determine si una matriz cuadrada de enteros de orden
N es sim�trica.*/

int esSimetrica(int matriz[][TAM], int fila, int columna) {
    int i, j, bandera = 0;
    if (fila != columna)  // compruebo que sea cuadrada
        return NO_CUADRADA;
    for (i = 0; i < fila && !bandera; i++)  // compruebo que sea simetrica
        for (j = i + 1; j < columna && !bandera; j++)
            if (matriz[i][j] != matriz[j][i])
                bandera = 1;
    return TODO_OK;
}

/*Ejercicio 34: Desarrollar una funci�n para trasponer, in situ(en el lugar), una matriz cuadrada.*/

void trasponerMatriz(int matriz[][TAM], int orden) {
    int aux, i, j;
    for (i = 0; i < orden; i++)  // Ver funcion triangular superior sin DP
        for (j = i + 1; j < orden; j++) {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
}

/*Ejercicio 35: Desarrollar una funci�n para obtener la traspuesta de una matriz dada.*/

void copiarYTrasponerMatriz(int matriz[][TAM], int auxMatriz[][TAM], int orden) {
    int i, j;
    for (i = 0; i < orden; i++)
        for (j = 0; j < orden; j++)
            auxMatriz[i][j] = matriz[i][j];
    trasponerMatriz(auxMatriz, orden);
}

/*Ejercicio 36: Desarrollar una funci�n para obtener la matriz producto entre dos matrices de enteros.*/

void productoMatrices(int matriz1[][TAM], int fila1, int columna1, int matriz2[][TAM], int fila2, int columna2) {
    int i, j, k;
    int matrizProducto[TAM][TAM] = {{0}};
    if (columna1 != fila2) {
        printf("\nNo es posible realizar el producto de matrices\n");
        return;
    }
    /// [fil1] [col1] * [fil2] [col2] = [fil1] * [col2]
    for (i = 0; i < fila1; i++)
        for (j = 0; j < columna2; j++)
            for (k = 0; k < columna1; k++)  // fila2
                matrizProducto[i][j] += matriz1[i][k] * matriz2[k][j];
    printf("\nEl producto de matrices da como resultado: \n");
    mostrarMatriz(matrizProducto, fila1, columna2);
}

/**********************************************************************************************************/

/*Loom: Desarrollar dos funciones:
1) Una funcion que dadas la cantidad de filas y columnas, reserve la memoria necesaria (en forma dinamica)
para operar con una matriz de "cualquier tipo" a traves de subindices.
2) Una funcion que libere la matriz anterior

Para poder utilizar la matriz con los subindices de fila y columna:
1) Debe reservar memoria para un vector que guarde la direccion de cada vector fila.
2) Reservar memoria para cada uno de los vectores fila de la matriz.
3) Si no pudo reservar memoria libere*/

void* reservarMemMatriz(int fila, int columna, size_t tamanio) {
    void** matriz = malloc(sizeof(void*) * fila);
    int memoriaLlena = 0;
    for (int i = 0; i < fila && !memoriaLlena; i++) {
        matriz[i] = malloc(tamanio * columna);
        if (!matriz[i])
            memoriaLlena = 1;
    }
    if (memoriaLlena != 0) {
        liberarMatriz(matriz, fila);
        return NULL;
    }
    return matriz;
}

void liberarMatriz(void** matriz, int fila) {
    for (int i = 0; i < fila; i++)
        free(matriz[i]);
    free(matriz);
}

/*Desarrollar una funcion que transponga in situ una matriz con respecto a la diagonal secundaria*/

int trasponerRespectoDS(int matriz[][TAM], int fila, int columna) {
    int i, j, aux;
    if (fila != columna)
        return NO_CUADRADA;
    for (i = 0; i < fila; i++)
        for (j = 0; j < columna - i - 1; j++) {
            aux = matriz[i][j];
            matriz[i][j] = matriz[fila - 1 - j][columna - 1 - i];
            matriz[fila - 1 - j][columna - 1 - i] = aux;
        }
    return TODO_OK;
}
