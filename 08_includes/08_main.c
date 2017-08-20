// [1]
// Generar codigo objeto (sin linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -c 08_main.c
//
// Falla, verdad?
//
// Precompilar (y solo precompilar) con:
//  gcc -Wall -Werror -std=c99 -pedantic -E 08_main.c
//
//      -E      detiene a gcc luego de la etapa de precompilacion
//
// y ver la salida: cuantas veces se incluyo el archivo "08_person.h" ?
// (y por lo tanto cuantas veces se re-definio el struct Person ?)
//

//
// [2]
// Editar el archivo 08_person.h
//

// [5]
// Volver a compilar:
//  gcc -Wall -Werror -std=c99 -pedantic -c 08_main.c
//
// ahora funciona verdad?
// Medite el por que de esto...
//
// Bien! has terminado este tutorial. Continua en 09_defines.c

#include "08_person.h"      // en este archivo esta la definicion del struct Person
#include "08_foofunc.h"      // en este otro esta la declaracion de la funcion foofunc

int main(int argc, char* argv[]) {
    struct Person person;   // el compilador necesita saber el size del struct
                            // entonces necesita su definicion

    foofunc(person);        // el compilador necesita validar esta firma
                            // entonces necesita su declaracion
}
