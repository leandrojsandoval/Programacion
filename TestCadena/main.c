#include <stdio.h>
#include <stdlib.h>

#include "../Cadena/Cadena.h"

int main() {
    /// Uso de tildes
    system("chcp 1252 >nul");

    /// Normalizar
    char textoOrig[] = "'%$vIvA-$ \t�SpA�a/()/()-";
    char textoDest[TAM];

    normalizarATitulo(textoOrig, textoDest);
    printf("\n'%s'\n", textoDest);

    normalizarAMinuscula(textoOrig, textoDest);
    printf("\n'%s'\n", textoDest);

    normalizarAMayuscula(textoOrig, textoDest);
    printf("\n'%s'\n", textoDest);

    normalizarAOracion(textoOrig, textoDest);
    printf("\n'%s'\n", textoDest);

    char nombreCompleto[TAM] = "  sandoval vAsQuez    LeaNdrO jUaN ";
    normalizarABibliografia(nombreCompleto, nombreCompleto);
    printf("\n'%s'\n", nombreCompleto);

    char numero[] = "-123";
    printf("\n%d\n", miAtoi(numero));

    /// Palindromo
    char cadPalindromo[] = "    N�u ,Q .  �e  n";
    if (esPalindromo(cadPalindromo))
        puts("Es palindromo");
    else
        puts("No es palindromo");

    /// strstr
    char s1[13] = "Hola a todos";
    char s2[3] = "m";
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("strstr(s1,s2) = %s\n", miStrstr(s1, s2));

    /// Anagrama
    char cadAnagrama1[] = "Alborota";
    char cadAnagrama2[] = "Rata, lobo";
    if (esAnagrama(cadAnagrama1, cadAnagrama2))
        puts("Las cadenas son anagramas");
    else
        puts("Las cadenas no son anagramas");

    /// Cantidad de palabras
    char texto[TAM] = "Hola a todo el mundo";
    printf("\nLa cadena '%s' tiene %d palabras\n", texto, cantidadPalabras(texto));
    printf("\nLa palabra mas larga tiene una longitud de %d caracteres\n", longitudPalabraMasLarga(texto));

    char frase[TAM_TEXTO] =
        "En muchas partes del cuerpo como son las manos, las orejas o los pies, estan "
        "representados todos los organos y partes del cuerpo. Incidiendo sobre estas "
        "zonas se pueden crear arcos reflejos que actuen directamente sobre cualquier "
        "organos del cuerpo y que solucionen cualquier anomalia que exista. En las "
        "manos, las orejas o los pies, se representan todos los organos del cuerpo."
        "Incidiendo sobre estas zonas se pueden crear arcos reflejos que actuen "
        "directamente sobre cualquier punto del organismo y que solucionan cualquier "
        "punto del organismo y que solucionen la anomalia que exista.";
    int top;
    puts("Ingrese el top de ocurrencias de la cadena:");
    fflush(stdin);
    scanf("%d", &top);
    mostrarTopOcurrencias(frase, top);

    return 0;
}
