// [1] Generar codigo objeto (sin linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -c 03_size_and_offsets.c
//
// Error, eh? Esta vez pusimos una forward declaration de la estructura Person,
// por que falla la compilacion esta vez?
//
// Ver los comentarios de la funcion person_set [2]
//




// [3]
// definitions
// -----------
//
// Descomentar la siguiente estructura para que el
// compilador sepa:
//  - el size del struct (cuantos bytes ocupa la estructura?)
//  - el offset de cada atributo (cuantos bytes hay entre cada atributo y
//                                el principio de la estructura?)
//
// Descomenta el codigo y vuelve a compilar
/*
struct Person {
    int age;        // offset 0
    int height;     // offset 4 (asume sizeof(int) == 4 y sin padding)
    int weight;     // offset 8 (idem)
};
*/


// [4] Inspeccionar el codigo objeto junto con el codigo fuente con:
//  objdump -d -S 03_size_and_offsets.o
//
// Trata de ver los offsets para acceder a cada uno de los atributos dentro de
// la funcion person_set
//
// Intenta ver cuanto espacio se reserva en el stack para la estructura.
//
// Es por esta razon que el compilador necesita la definicion de la
// estructura: no puede generar codigo sin ella.
//
//
// Bien! has terminado este tutorial. El camino hacia el entendimiento de
// la Fuerza es largo. Pero hoy has aprendido a compilar y eso es algo notable.
// Sigue en 04_linker.c



// [2]
// El compilador no puede generar codigo ya que no sabe cuanta memoria
// ocupa Person (no es un puntero): no sabe cuanta memoria reservar en el stack
//
// Ademas, no sabe como acceder a los atributos 'age', 'height' ni 'weight'
// ya que no conoce el offset que hay desde el principio de la estructura Person
// hasta dicho atributo.
//
// Una declaracion adelantada no alcanza, el compilador necesita la definicion de
// la estructura completa
//
struct Person;

int person_set(struct Person person_tmp) {
    struct Person person;
    person.age = 0x41;
    person.height = 0x42;
    person.weight = 0x43;

    return person.age;
}
