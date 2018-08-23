// [1] Generar codigo objeto (sin linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -c 04_linker.c
//
// Ningun problema. La compilacion funciono perfectamente.


// [2] Ver el codigo compilado y tratar de ver 'la direccion' de say_hello.
//  objdump -S -d 04_linker.o


// [3] No continues si no hiciste [1] o [2]
// Armar un ejecutable (gcc va a precompilar, compilar y linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -o 04_linker.exe  04_linker.c
//
//      -o <name>:  gcc usa ese nombre como nombre del executable
//
// Falla, eh? Leer los errores y luego leer los comentarios de la funcion main
//


// [5]
// declarations & definitions
// --------------------------
//
// Descomentar la >>definicion<< de la funcion say_hello
// y la >>declaracion<< (forward declaration) de puts
//
// Volver a armar el ejecutable y verlo el codigo del ejecutable con:
//  objdump -S -d 04_linker.exe
//
// Intenta ver la direccion y el codigo de say_hello. Y la de puts?
/*
int puts(const char*); // [7] esta funcion, donde esta definida?
                       // objdump va a mostrar que el codigo de puts *no*
                       // esta en el binario.
                       //
                       // Aun sin la definicion, gcc linkeo correctamente e incluso
                       // el ejecutable puede correr sin problemas.
                       //
                       // El codigo de puts esta en una libreria externa, la libc
                       // que se carga al momento de ejecutar el programa:
                       // esto se llama linkeo dinamico
                       //
                       // La ventaja de un linkeo dinamico es que permite reutilizar
                       // codigo compilado (de otro modo todos los programas en C estarian
                       // teniendo una copia de la lib compilada).
                       //
                       // Otra ventaja es que cualquier bug en la lib dinamica solo requiere
                       // recompilar la lib y reiniciar los programas que la usan
                       //
       // [8] Volver a compilar pero con un flag adicional:
       //   gcc -Wall -Werror -std=c99 -pedantic -ggdb -nostdlib -o 04_linker.exe  04_linker.c
       //
       //       -nostdlib: instruye al compilador que no linkee con la libreria
       //                  estandar de C, la "libc".
       //
       // Verificar que el linkeo falla por que la funcion puts no esta definida
       //

void say_hello() {   // [6] objdump va a mostrar que el codigo de say_hello
    puts("Hello");   // esta dentro del mismo binario: esto se llama linkeo estatico
                     // La ventaja de este tipo de linkeo es que es mas rapida la llamada a
                     // la funcion.
}
*/

// [9] Realmente tienes que intentar ver el codigo de say_hello.
//     No avances si no lo hiciste!!
//
// Bien! has terminado este tutorial.
//
//      Well, the libc is what gives a Jedi his power.
//      It surrounds us and penetrates us; it binds the galaxy together.
//                              - Obi-Wan Kenobi
//
// Continua tu entrenamiento en 05_linkeo_estatico_clib.c
//


// [4] El compilador tiene todo lo necesario para emitir codigo objeto
// pero para armar un ejecutable es necesario resolver la posicion
// de todas las funciones.
//
// En otras palabras, en donde esta el codigo de cada funcion, de otro
// modo el ejecutable no puede invocar/llamar a una funcion si no sabe
// donde esta.
//
// La tarea de resolver las posiciones la hace el "linker"
void say_hello(); // esta funcion, donde esta?

int main(int argc, char* argv[]) {
    say_hello();
    say_hello();
    say_hello();
}
