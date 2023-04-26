#include "Matriz.h"

int main()
{
    /*int matriz[][TAM]= {{}},auxMatriz[][TAM]= {{}},matrizProducto[][TAM]= {{}};
    int bandera=0,fila=0,columna=0,filaProducto,columnaProducto,opcion=menuMatrices();
    while(opcion)           //Salgo del while cuando opcion sea 0
    {
        switch(opcion)
        {
        case 1:
            printf("\nIngrese las filas que tendra la matriz: ");
            scanf("%d",&fila);
            printf("\nIngrese las columnas que tendra la matriz: ");
            scanf("%d",&columna);
            if(columna<=TAM)
                cargarMatriz(matriz,fila,columna);
            else
                printf("\nSe excedio el tamanio maximo (%d)\n",TAM);
            break;
        case 2:
            mostrarMatriz(matriz,fila,columna);
            break;
        case 3:
            system("cls");
            opcion=menuMostrarDS();
            while(opcion)
            {
                switch(opcion)
                {
                case 1:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarDS(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 2:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosAbajoDS(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 3:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosAbajoSinDS(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 4:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosArribaDS(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 5:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosArribaSinDS(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");
                opcion=menuMostrarDS();
            }
            break;
        case 4:
            system("cls");
            opcion=menuMostrarDP();
            while(opcion)
            {
                switch(opcion)
                {
                case 1:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarDP(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 2:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosAbajoDP(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 3:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosAbajoSinDP(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 4:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosArribaDP(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 5:
                    if(fila==columna && (fila!=0 || columna!=0))
                        mostrarElementosArribaSinDP(matriz,columna);
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                };
                printf("\n");
                system("pause");
                system("cls");
                opcion=menuMostrarDP();
            }
            break;
        case 5:
            system("cls");
            opcion=menuSumaDS();
            while(opcion)
            {
                switch(opcion)
                {
                case 1:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de la diagonal secundaria es: %d\n",sumaDS(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 2:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos arriba de la diagonal secundaria (incluida) es: %d\n",sumaElementosArribaDS(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 3:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos arriba de la diagonal secundaria es: %d\n",sumaElementosArribaSinDS(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 4:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos abajo de la diagonal secundaria (incluida) es: %d\n",sumaElementosAbajoDS(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 5:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos abajo de la diagonal secundaria es: %d\n",sumaElementosAbajoSinDS(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");
                opcion=menuSumaDS();
            }
            break;
        case 6:
            system("cls");
            opcion=menuSumaDP();
            while(opcion)
            {
                switch(opcion)
                {
                case 1:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de la diagonal principal es: %d\n",sumaDP(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 2:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos arriba de la diagonal principal (incluida) es: %d\n",sumaElementosArribaDP(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 3:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos arriba de la diagonal principal es: %d\n",sumaElementosArribaSinDP(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 4:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos abajo de la diagonal principal (incluida) es: %d\n",sumaElementosAbajoDP(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                case 5:
                    if(fila==columna && (fila!=0 || columna!=0))
                        printf("\nLa suma de los elementos abajo de la diagonal principal es: %d\n",sumaElementosAbajoSinDP(matriz,columna));
                    else if(!fila && !columna)
                        printf("\nLa matriz no fue cargada\n");
                    else
                        printf("\nLa matriz cargada no es una matriz cuadrada\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");
                opcion=menuSumaDP();
            }
            break;
        case 7:
            if(!fila && !columna)
                printf("\nLa matriz no fue cargada\n");
            else
                printf("\n%s\n",esDiagonal(matriz,fila,columna)? "La matriz es diagonal" : "La matriz no es diagonal");
            break;
        case 8:
            if(!fila && !columna)
                printf("\nLa matriz no fue cargada\n");
            else
                printf("\n%s\n",esIdentidad(matriz,fila,columna)? "La matriz es identidad" : "La matriz no es identidad");
            break;
        case 9:
            if(!fila && !columna)
                printf("\nLa matriz no fue cargada\n");
            else
                printf("\n%s\n",esSimetrica(matriz,fila,columna)? "La matriz no es simetrica" : "La matriz no es simetrica");
            break;
        case 10:
            if(fila==columna && (fila!=0 || columna!=0))
                trasponerMatriz(matriz,columna);
            else if(!fila && !columna)
                printf("\nLa matriz no fue cargada\n");
            else
                printf("\nLa matriz cargada no es una matriz cuadrada\n");
            break;
        case 11:
            if(fila==columna && (fila!=0 || columna!=0))
            {
                copiarYTrasponerMatriz(matriz,auxMatriz,columna);
                printf("\nMatriz traspuesta: \n");
                mostrarMatriz(auxMatriz,fila,columna);
            }
            else if(!fila && !columna)
                printf("\nLa matriz no fue cargada\n");
            else
                printf("\nLa matriz cargada no es una matriz cuadrada\n");
            break;
        case 12:
            if(fila)
            {
                printf("\nIngrese filas de la matriz: ");
                scanf("%d",&filaProducto);
                do
                {
                    if(bandera==1)
                        printf("\nLas columnas exceden el tamanio maximo (%d)\n",TAM);
                    bandera=1;
                    printf("\nIngrese las columnas de la matriz: ");
                    scanf("%d",&columnaProducto);
                }
                while(columnaProducto>TAM);
                cargarMatriz(matrizProducto,filaProducto,columnaProducto);
                productoMatrices(matriz,fila,columna,matrizProducto,filaProducto,columnaProducto);
            }
            else
                printf("\nPara cargar la segunda matriz es necesario cargar la primera (opcion 1)\n");
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
        opcion=menuMatrices();
    }*/

    int fila,columna;
    printf("\nIngrese la cantidad de la filas: ");
    scanf("%d",&fila);
    printf("\nIngrese la cantidad de columnas: ");
    scanf("%d",&columna);
    /*Casteamos lo que devuelve la funcion al tipo de dato a usar*/
    int* pMatriz = (int*) reservarMemMatriz(fila,columna,sizeof(int));
    printf("\n%p\n",(int*)pMatriz);
    printf("\n%p\n",(int*)pMatriz+(fila*columna));
    /*Para liberar tambien hay que castear a generico*/
    liberarMatriz((void*)pMatriz,fila);

    return 0;
}
