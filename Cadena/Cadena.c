#include "Cadena.h"

/**************************************** ctype.h *****************************************/

int toSinTilde (int letra)
{
    char matTildes[2][11] =
    {
        "ÁÉÍÓÚáéíóú",
        "AEIOUaeiou"
    };
    int j;
    for(j = 0; matTildes[FILA_TILDE][j] && matTildes[FILA_TILDE][j] != letra; j++);
    return matTildes[FILA_TILDE][j] == letra? matTildes[FILA_SIN_TILDE][j] : letra;
}

/*************************************** string.h ****************************************/

size_t miStrlen (const char* s)
{
    size_t longitud = 0;
    while(*s++)
        longitud++;
    return longitud;
}

char* miStrcat (char* s1, const char* s2)
{
    char* origen = s1;
    while(*s1)
        s1++;
    while((*s1++ = *s2++));
    return origen;
}

int miStrcmp (const char* s1, const char* s2)
{
    while(*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int miStrcmpi (const char* s1, const char* s2)
{
    while(*s1 && MI_TOLOWER(toSinTilde(*s1)) == MI_TOLOWER(toSinTilde(*s2)))
    {
        s1++;
        s2++;
    }
    return MI_TOLOWER(toSinTilde(*s1)) - MI_TOLOWER(toSinTilde(*s2));
}

char* miStrcpy (char *s1, const char *s2)
{
    char* origen = s1;
    while((*s1++ = *s2++));
    return origen;
}

char* miStrdup (const char* s1)
{
    char* cadDupli = (char*)malloc(miStrlen(s1) + 1);
    if(!cadDupli)
        return NULL;
    return miStrcpy(cadDupli, s1);
}

char* miStrncpy (char *s1, const char *s2, size_t n)
{
    char* origen = s1;
    size_t cantMin = MINIMO(miStrlen(s2), n);
    while(cantMin--)
        *s1++ = *s2++;
    *s1 = '\0';
    return origen;
}

char* miStrchr (char* s, int c)
{
    while(*s && *s != c)
        s++;
    return *s? s : NULL;
}

char* miStrrchr (char* s, int c)
{
    char* finCad = s + miStrlen(s) - 1;
    while(s <= finCad && *finCad != c)
        finCad--;
    return *finCad == c? finCad : NULL;
}

char* miStrstr (const char* s1, const char* s2)
{
    if(!miStrlen(s2))
        return (char*)s1;
    while(*s1 && miStrcmpSubcadena(s1, s2))
        s1++;
    return *s1? (char*)s1 : NULL;
}

char* miStrlwr (char* s)
{
    char* origen = s;
    while(*s)
    {
        if(ES_MAYUSCULA(*s))
            *s = MI_TOLOWER(*s);
        s++;
    }
    return origen;
}

char* miStrupr (char* s)
{
    char* origen = s;
    while(*s)
    {
        if(ES_MINUSCULA(*s))
            *s = MI_TOUPPER(*s);
        s++;
    }
    return origen;
}

char* miStrrev (char* s)
{
    char* origen = s;
    char* finCad = s + miStrlen(s) - 1;
    char temp;
    while(s < finCad)
    {
        temp = *s;
        *s++ = *finCad;
        *finCad-- = temp;
    }
    return origen;
}

/************************************ Otras de cadenas ************************************/

int miStrcmpSubcadena (const char* s1, const char* s2)
{
    while(*s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s2? *s1 - *s2 : 0;
}

const char* saltarLetraValI (const char* cad)
{
    while(*cad && !ES_LETRA(toSinTilde(*cad)))
        cad++;
    return cad;
}

const char* saltarLetraValD (const char* cad, const char* limIzq)
{
    while(cad > limIzq && !ES_LETRA(toSinTilde(*cad)))
        cad--;
    return cad;
}

char* trim (char* cadena)
{
    char* fin = cadena + miStrlen(cadena) - 1;
    while(fin >= cadena && ES_BLANCO(*fin))
        fin--;
    if(fin < cadena)
        return NULL;
    fin++;
    *fin = '\0';
    return cadena;
}

int contarVocales (const char * cadena)
{
    int cantidadVocales = 0;
    while(*cadena)
    {
        if(ES_VOCAL(*cadena))
            cantidadVocales++;
        cadena++;
    }
    return cantidadVocales;
}

/*Desarrollar una función que cuente la cantidad de apariciones de una cadena dentro de otra.*/

int miStrcmpApariciones (const char** cadena1, const char* cadena2)
{
    while(*cadena2 && **cadena1 == *cadena2)
    {
        (*cadena1)++;
        cadena2++;
    }
    return (!*cadena2)? 0 : **cadena1 - *cadena2;
}

int cantidadApariciones (const char* texto, const char* cadena)
{
    int repeticiones = 0;
    while(*texto)
        if(*texto == *cadena)
        {
            if(!miStrcmpApariciones(&texto,cadena))
                repeticiones++;
        }
        else
            texto++;
    return repeticiones;
}

/*Realizar una función que reemplace dentro de una cadena una subcadena por otra.*/

char* reemplazarSubcadena(char* cadena, const char* subcadena, const char* cadenaAReemplazar)
{
    char* punteroInicio = cadena;
    while(*cadena && miStrcmpSubcadena(cadena, subcadena))
        cadena++;
    if(!*cadena)
    {
        printf("\nLa subcadena '%s' no se encuentra dentro de la cadena '%s'\n",subcadena,punteroInicio);
        return NULL;
    }
    while(*cadena && *cadenaAReemplazar)
    {
        *cadena++ = *cadenaAReemplazar++;
    }
    return punteroInicio;
}

/*Ejercicio 27: Desarrollar una función que determine si una cadena de caracteres
es un palíndromo.*/

bool esPalindromo (const char* s)
{
    const char* izq = s;
    const char* der = s + miStrlen(s) - 1;
    izq = saltarLetraValI(izq);
    der = saltarLetraValD(der, s);
    while(izq < der && MI_TOLOWER(toSinTilde(*izq)) == MI_TOLOWER(toSinTilde(*der)))
    {
        izq++;
        izq = saltarLetraValI(izq);
        der--;
        der = saltarLetraValD(der, s);
    }
    return izq >= der;
}

/*Ejercicio 28: Desarrollar una función que devuelva el valor numérico de una
cadena de caracteres (asumiendo que los caracteres representan dígitos).*/

int miAtoi (const char* cadena)
{
    bool esNegativo = false;
    if(*cadena == '-')
    {
        esNegativo = true;
        cadena++;
    }

    int numero = 0;
    while(*cadena)
    {
        numero = numero * 10 + MI_TONUMINT(*cadena);
        cadena++;
    }
    return esNegativo? -numero : numero;
}

char* miItoa (int numero, char* cadena)
{
    char* punteroInicio = cadena;
    bool esNegativo = false;

    if(numero < 0)
    {
        esNegativo = true;
        numero *= -1;
    }

    while(numero > 10)
    {
        *cadena++ = MI_TOASCII(numero % 10);
        numero /= 10;
    }

    *cadena = MI_TOASCII(numero);

    if(esNegativo)
        *cadena++ = '-';

    intercambioDeCaracteres(punteroInicio, cadena);
    *++cadena = '\0';

    return punteroInicio;
}

bool esAnagrama (const char* s1, const char* s2)
{
    OcurrenciasLetra vOcurrencias1[TAM_ABECEDARIO];
    int cantElemOcurr1;
    cargarCadenaEnVectorOcurrenciasLetra(vOcurrencias1, &cantElemOcurr1,TAM_ABECEDARIO, s1);
    ordenamientoSeleccionAscendente(vOcurrencias1, cantElemOcurr1, sizeof(OcurrenciasLetra), cmpOcurrenciasLetra);

    OcurrenciasLetra vOcurrencias2[TAM_ABECEDARIO];
    int cantElemOcurr2;
    cargarCadenaEnVectorOcurrenciasLetra(vOcurrencias2, &cantElemOcurr2, TAM_ABECEDARIO, s2);
    ordenamientoSeleccionAscendente(vOcurrencias2, cantElemOcurr2, sizeof(OcurrenciasLetra), cmpOcurrenciasLetra);

    const OcurrenciasLetra* vec1 = vOcurrencias1;
    const OcurrenciasLetra* dirFinVec1 = vec1 + cantElemOcurr1 - 1;

    const OcurrenciasLetra* vec2 = vOcurrencias2;
    const OcurrenciasLetra* dirFinVec2 = vec2 + cantElemOcurr2 - 1;

    int res;
    while(vec1 <= dirFinVec1 && vec2 <= dirFinVec2 && !(res = cmpOcurrenciasLetra(vec1, vec2)))
    {
        vec1++;
        vec2++;
    }
    return vec1 > dirFinVec1 && vec2 > dirFinVec2;
}

/*Ejercicio 8: Dado un array de char que contiene un texto compuesto por palabras que termina en
'.' (o en su defecto en carácter nulo -'\0'-), escriba un programa en que determine e informe:
a- Cuál es la primera palabra y cuántas veces se repite en el texto
b- Cuántas palabras tiene el texto
c- Longitud de la palabra más larga*/

int cantidadPalabras (const char* texto)
{
    int cantPal = 0;
    SecuenciaPalabras secLect;
    crearSecuenciaPalabras(&secLect, texto);
    Palabra pal;
    while(leerPalabra(&secLect, &pal))
        cantPal++;
    return cantPal;
}

int longitudPalabraMasLarga (const char* texto)
{
    int longPalMasLarga;
    int nuevaLongPal;

    SecuenciaPalabras secLect;
    crearSecuenciaPalabras(&secLect, texto);

    Palabra pal;

    leerPalabra(&secLect, &pal);
    longPalMasLarga = miStrlenPal(&pal);

    while(leerPalabra(&secLect, &pal))
    {
        if(longPalMasLarga < (nuevaLongPal = miStrlenPal(&pal)))
            longPalMasLarga = nuevaLongPal;
    }

    return longPalMasLarga;
}

void mostrarTopOcurrencias (const char* texto, int top)
{
    OcurrenciasPalabra vOcurrPal[TAM];
    int cantElem;
    cargarCadenaEnVectorOcurrenciasPalabra(vOcurrPal, &cantElem, TAM, texto);
    if(top > cantElem)
    {
        puts("El top supera la cantidad de palabras distintas");
        return;
    }
    ordenamientoSeleccionDescendente(vOcurrPal, cantElem, sizeof(OcurrenciasPalabra), cmpOcurrenciasPalabra);
    printf("\nTop %d\n",top);
    mostrarVector(vOcurrPal, MINIMO(cantElem, top), sizeof(OcurrenciasPalabra), mostrarOcurrenciasPalabras);
}

/************************************ Normalizacion ************************************/

void normalizarATitulo (const char* textoOrig, char* textoDest)
{
    SecuenciaPalabras secLect, secEscr;
    crearSecuenciaPalabras(&secLect, textoOrig);
    crearSecuenciaPalabras(&secEscr, textoDest);
    Palabra pal;
    while(leerPalabra(&secLect, &pal))
    {
        escribirPalabraPrimeraMayuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ' ');
    }
    reposicionarCursor(&secEscr, -1);
    cerrarSecuenciaPalabras(&secEscr);
}

void normalizarAMinuscula (const char* textoOrig, char* textoDest)
{
    SecuenciaPalabras secLect, secEscr;
    crearSecuenciaPalabras(&secLect, textoOrig);
    crearSecuenciaPalabras(&secEscr, textoDest);
    Palabra pal;
    while(leerPalabra(&secLect, &pal))
    {
        escribirPalabraMinuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ' ');
    }
    reposicionarCursor(&secEscr, -1);
    cerrarSecuenciaPalabras(&secEscr);
}

void normalizarAMayuscula (const char* textoOrig, char* textoDest)
{
    SecuenciaPalabras secLect, secEscr;
    crearSecuenciaPalabras(&secLect, textoOrig);
    crearSecuenciaPalabras(&secEscr, textoDest);
    Palabra pal;
    while(leerPalabra(&secLect, &pal))
    {
        escribirPalabraMayuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ' ');
    }
    reposicionarCursor(&secEscr, -1);
    cerrarSecuenciaPalabras(&secEscr);
}

void normalizarAOracion (const char* textoOrig, char* textoDest)
{
    SecuenciaPalabras secLect, secEscr;
    crearSecuenciaPalabras(&secLect, textoOrig);
    crearSecuenciaPalabras(&secEscr, textoDest);
    Palabra pal;

    leerPalabra(&secLect, &pal);
    escribirPalabraPrimeraMayuscula(&secEscr, &pal);
    escribirCaracter(&secEscr, ' ');

    while(leerPalabra(&secLect, &pal))
    {
        escribirPalabraMinuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ' ');
    }
    reposicionarCursor(&secEscr, -1);
    cerrarSecuenciaPalabras(&secEscr);
}

void normalizarABibliografia (const char* textoOrig, char* textoDest)
{
    int cont = cantidadPalabras(textoOrig);
    if(cont < 2 && cont >4)
        return;
    SecuenciaPalabras secLect, secEscr;
    crearSecuenciaPalabras(&secLect, textoOrig);
    crearSecuenciaPalabras(&secEscr, textoDest);
    Palabra pal;
    switch(cont)
    {
    case 2:
        leerPalabra(&secLect, &pal);
        escribirPalabraMayuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ',');
        escribirCaracter(&secEscr, ' ');
        leerPalabra(&secLect, &pal);
        escribirPalabraPrimeraMayuscula(&secEscr, &pal);
        break;
    case 3:
        leerPalabra(&secLect, &pal);
        escribirPalabraMayuscula(&secEscr, &pal);
        escribirCaracter(&secEscr, ',');
        escribirCaracter(&secEscr, ' ');
        while(leerPalabra(&secLect, &pal))
        {
            escribirPalabraPrimeraMayuscula(&secEscr, &pal);
            escribirCaracter(&secEscr, ' ');
        }
        reposicionarCursor(&secEscr, -1);
        break;
    case 4:
        cont = 0;
        while(cont != 2 && leerPalabra(&secLect, &pal))
        {
            escribirPalabraMayuscula(&secEscr, &pal);
            escribirCaracter(&secEscr, ' ');
            cont++;
        }
        reposicionarCursor(&secEscr, -1);
        escribirCaracter(&secEscr, ',');
        escribirCaracter(&secEscr, ' ');
        while(cont != 4 && leerPalabra(&secLect, &pal))
        {
            escribirPalabraPrimeraMayuscula(&secEscr, &pal);
            escribirCaracter(&secEscr, ' ');
            cont++;
        }
        reposicionarCursor(&secEscr, -1);
    }
    cerrarSecuenciaPalabras(&secEscr);
}

/****************************** Encriptado/Desencriptado ******************************/

void intercambioDeCaracteres (char* s1, char* s2)
{
    char temp;
    while(s1 < s2)
    {
        temp = *s1;
        *s1++ = *s2;
        *s2-- = temp;
    }
}

char* desplazarUnCaracter (char* s)
{
    char* origen = s;
    while(*s)
    {
        *s = *(s+1);
        s++;
    }
    //*s = '\0';
    return origen;
}

char* intercambiarCaracteresSegunNumero (char* cadena)
{
    char* origen = cadena;
    char* auxPuntero;
    int offset, tamDisponible;
    while(*cadena)
    {
        while(ES_NUMERO(*cadena))
        {
            offset = MI_TONUMINT(*cadena);
            tamDisponible = miStrlen(cadena);
            if(offset < tamDisponible)
            {
                auxPuntero = cadena + offset;
                intercambioDeCaracteres(cadena, auxPuntero);
                cadena = auxPuntero;
                desplazarUnCaracter(cadena);
            }
        }
        if(*cadena != '\0')
            cadena++;
    }
    return origen;
}

/*Desofuscar la siguiente lineal de texto:
    linea = "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA"
La línea fue ofuscada de la siguiente manera:

    1.Se identificaron las palabras, bloques de texto compuestos por letras a..z A..Z
    2.Se dieron vuelta las palabras, ej. : hola=>aloh
    3.Se retrocedieron los caracteres pertenecientes al conjunto : "acefhijklo" 3 posiciones
    en el mismo conjunto de forma circular, luego de la o esta la a.

No utilice cadenas auxiliares.*/

char* invertirPalabras (char* cadena)
{
    char* punteroInicio = cadena;
    char* auxPuntero = cadena;
    while(*cadena)
    {
        while(ES_LETRA(*auxPuntero) && *auxPuntero)
            auxPuntero++;
        auxPuntero--;
        intercambioDeCaracteres(cadena, auxPuntero);
        auxPuntero++;
        while(!ES_LETRA(*auxPuntero) && *auxPuntero)
            auxPuntero++;
        cadena = auxPuntero;
    }
    return punteroInicio;
}

char caracterDesencriptado (char* conjunto, char letra)
{
    while(*conjunto && *conjunto!=letra)
        conjunto++;
    return (!*conjunto)? '\0' : (letra=='k')? 'a' : (letra=='l')? 'c' : (letra=='o')? 'e' : *(conjunto+3);
}

char* desofuscarCadena (char* cadena)
{
    invertirPalabras(cadena);
    char letraDesencriptada;
    char* punteroInicio = cadena;
    while(*cadena)
    {
        if((letraDesencriptada = caracterDesencriptado("acefhijklo",*cadena)) != '\0')
        {
            *cadena = letraDesencriptada;
        }
        cadena++;
    }
    return punteroInicio;
}
