// [1]
// Armar un ejecutable (gcc va a precompilar, compilar y linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -o 09_define.exe 09_define.c
//
// Ejecutar el programa, da lo que se espera? Acaso una funcion MAX no es simetrica?


// [5]
// Precompilar (y solo precompilar) con
//  gcc -Wall -Werror -std=c99 -pedantic -E 09_define.c
//
// Ver como se expanden las constantes y las macros. Por que esta mal el codigo generado
// cuando se usa la macro MAX?


// [6]
// Comentar la macro MAX **mal** implementada y descomentar la **bien** implementada
// Compilar y ejecutar el programa
//


// [2] Esta es la definicion de una constante
#define PI 3.1416   // una "constante" de C

// [3] En cambio esta es una macro.
// MAX recibe 2 paramentros y retorna el maximo de ambos... o no?
#define MAX(x,y) (x > y) ? x : y  // una "macro" **mal** implementada

//#define MAX(x,y)   (((x) > (y)) ? (x) : (y))  // una "macro" **bien** implementada
                                                //  - todos los argumentos son puestos entre parentesis
                                                //  - toda la macro es puesta entre parentesis
                                                //

// [7]
// Las macros pueden ser completamente arbitrarias.
// Sin embargo, el precompilador solo debe ser usado en
// casos *muy* especificos y *muy* justificados.
//
// Son extraordinariamente dificiles de debuggear y entender y no tienen
// ningun chequeo por parte del compilador.
//
#define FOREACH(elem, array) \
    for (unsigned int i = 0; \
            (elem) = (array)[i], \
            i < sizeof((array)) / sizeof(*(array)); \
            ++i)


#include <stdio.h>
int main(int argc, char* argv[]) {
    float f = PI;

    // [4]
    // En C, todo numero salvo 0 es considerado como true y un true es considerado como un 1
    //
    // Entonces
    //    2 || 4 es equivalente a "true or true", o sea, "true" y por lo tanto 1.
    //
    // Entonces
    //    MAX(2 || 4, f) ==> MAX(1, 3.1416) ==> 3.1416
    //    MAX(f, 2 || 4) ==> MAX(3.1416, 1) ==> 3.1416
    // no?
    printf("Max between %f and %f ==> %f\n",
            (float)(2 || 4),
            f,
            MAX(2 || 4, f)); // esto da el resultado correcto?

    printf("Max between %f and %f ==> %f\n",
            f,
            (float)(2 || 4),
            MAX(f, 2 || 4)); // este printf deberia ser igual
                             // al anterior (MAX es simetrica, no?)
    printf("\n");

    int nums[] = {1, 2, 3, 5, 8};
    int n;
    printf("Numbers: \n");

    // [8]
    // Luke: Is the precompiler stronger?
    // Yoda: No, no, no. Quicker, easier, more seductive.
    //       ifndefs, defines, macros; the dark side of the Force are they
    //
    // Bien! has terminado este tutorial. Continua en 10_asan.c
    //
    FOREACH(n, nums) {
        printf("%i, ", n);
    }
    printf("\n");

    return 0;
}
