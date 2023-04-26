#include "Matematica.h"

int main()
{
    int n,numero,opcion;
    double tolerancia;
    opcion = menuMatematicas();
    while(opcion)
    {
        switch(opcion)
        {
        case 1:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            if(factorial(numero))
                printf("\nEl factorial del numero %d es %0.lf\n",numero,factorial(numero));
            else
                printf("No es posible realizar el factorial del numero %d\n",numero);
            break;
        case 2:
            printf("\nIngrese un numero m: ");
            scanf("%d",&numero);
            printf("\nIngrese un numero n: ");
            scanf("%d",&n);
            if(combinatoria(numero,n)!=-1)
                printf("\nLa combinatoria del los numeros %d y %d es: %d\n",numero,n,combinatoria(numero,n));
            else
                printf("\nNo es posible realizar la combinatoria de los numeros %d y %d\n",numero,n);
            break;
        case 3:
            printf("\nIngrese un numero (exponente): ");
            scanf("%d",&numero);
            printf("\nIngrese una tolerancia: ");
            scanf("%lf",&tolerancia);
            printf("\nEl numero e^%d con tolerancia %f es de: %f\n",numero,tolerancia,eALaX(numero,tolerancia));
            break;
        case 4:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nIngrese una tolerancia: ");
            scanf("%lf",&tolerancia);
            printf("\nLa raiz cuadrada de %d con tolerancia %f es de: %f\n",numero,tolerancia,raizCuadrada(numero,tolerancia));
            break;
        case 5:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            if(fibonacci(numero))
                printf("\nEl numero %d pertenece a la sucecion de Fibonacci\n",numero);
            else
                printf("\nEl numero %d no pertenece a la sucesion de Fibonacci\n",numero);
            break;
        case 6:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nIngrese una tolerancia: ");
            scanf("%lf",&tolerancia);
            printf("\nEl resultado de sen(%d) con una tolerancia de %lf es: %lf",numero,tolerancia,seno(numero,tolerancia));
            break;
        case 7:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            clasificarNumero(numero);
            break;
        case 8:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nIngrese otro numero: ");
            scanf("%d",&n);
            printf("\nEl resultado del producto de %d y %d utilizando sumas sucesivas es: %d\n",numero,n,sumaSucesiva(numero,n));
            break;
        case 9:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nIngrese otro numero: ");
            scanf("%d",&n);
            cocienteResto(numero,n);
            break;
        case 10:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nLa suma de los primeros %d numeros naturales es %d\n",numero,sumaPrimerosNumeros(numero));
            break;
        case 11:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nLa suma de los primeros %d numeros naturales pares es %d\n",numero,sumaPrimerosNumerosPares(numero));
            break;
        case 12:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            printf("\nLa suma de los primeros %d numeros naturales menores pares es %d\n",numero,sumaPrimerosNumerosParesMenores(numero));
            break;
        case 13:
            printf("\nIngrese un numero: ");
            scanf("%d",&numero);
            esPrimo(numero);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
        opcion=menuMatematicas();
    }
    return 0;
}
