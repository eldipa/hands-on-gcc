// [1]
// Armar un ejecutable por el Metodo 1:
// -----------------------------------
//  (gcc va a precompilar, compilar y linkear)
//
// Aunque se llama al compilador una sola vez, el compilador
// Precompila + Compila cada fuente .c por separado
// y luego linkea todos los codigos objeto .o en un solo ejecutable
// resolviendo todas las direcciones de las funciones:
//
//  gcc -Wall -Werror -std=c99 -pedantic -o 06_main.exe 06_main.c 06_libby2.c 06_libby3.c
//
// Es un metodo simple pero cambiar un solo .c requiere recompilar todos los archivos fuente.
// No es muy optimo
//

// [2]
// Armar un ejecutable por el Metodo 2:
// -----------------------------------
//
// 1) Precompilar + Compilar cada fuente por separado
//  gcc -Wall -Werror -std=c99 -pedantic -c 06_main.c
//  gcc -Wall -Werror -std=c99 -pedantic -c 06_libby2.c
//  gcc -Wall -Werror -std=c99 -pedantic -c 06_libby3.c
//
// 2) y luego linkear los objetos:
//  gcc -Wall -Werror -std=c99 -pedantic -o 06_main.exe 06_main.o 06_libby2.o 06_libby3.o
//
// La ventaja de este metodo es que si se modifica solo un archivo fuente
// (digamos 06_libby2.c), solo es necesario recompilar dicho archivo y luego
// relinkear. En proyectos grandes esto salva **horas** de trabajo.
//
// Es por esto que es tan importante saber de las etapas de compilacion.


// [3]
// Armar un ejecutable por el Metodo 3:
// -----------------------------------
//
// 1) Precompilar + Compilar y "Empaquetar" los codigos de una lib
//  gcc -Wall -Werror -std=c99 -pedantic -c 06_libby2.c 06_libby3.c
//  ar -rc lib06_lib.a 06_libby2.o 06_libby3.o
//
//  ar es un programa para empaquetar codigo objeto.
//      -r      agrega elementos al empaquetado
//      -c      crea el empaquetado si no existe
//
// 2) y luego compilar el resto del proyecto y linkear con la lib
//  gcc -Wall -Werror -std=c99 -pedantic -o 06_main.exe 06_main.c lib06_lib.a
//
// La ventaja de este metodo es que podemos darle nuestra libreria a otras personas
// almacenada en un unico archivo en vez de varios .o
//
// Esto es reutilizacion de codigo!!


// [4]
// Armar un ejecutable por el Metodo 4:
// -----------------------------------
//
// 1) Precompilar + Compilar y "Empaquetar" los codigos de una lib (notese el nombre de la lib)
//  gcc -Wall -Werror -std=c99 -pedantic -c 06_libby2.c 06_libby3.c
//  ar -rc lib06_lib.a 06_libby2.o 06_libby3.o
//
// 2) y luego compilar el resto del proyecto y linkear con la lib
//  gcc -Wall -Werror -std=c99 -pedantic -o 06_main.exe 06_main.c -l06_lib
//
// Tira error, no? el flag "-l" y su argumento "06_lib" le dicen a gcc que hay
// que buscar una libreria llamada "lib06_lib.a" en las carpetas del sistema.
// (gcc automaticamente agrega "lib" y ".a" al nombre)
//
// El error esta en que nuestra lib no esta en dichas carpetas.
//
// Pero gcc ademas permite buscar librerias en carpetas no estandar: con el flag
// -L podemos indicar otras carpetas como la actual "./"
// Volver a linkear con:
//  gcc -Wall -Werror -std=c99 -pedantic -L./ -o 06_main.exe 06_main.c -l06_lib
//
//      -l<name>    busca la libreria llamada lib<name>.a para linkearla
//      -L<path>    agrega la carpeta <path> a la lista de carpetas para buscar librerias
//
// Este modo es el modo usual de compilar un codigo linkeando con una libreria
// externa que ya se encuentra instalada en nuestro sistema.
//

// [5] Bonus (tipico problema)
// ===========================
//
// Esto funciona:
//  gcc -Wall -Werror -std=c99 -pedantic -L./ -o 06_main.exe   06_main.c   -l06_lib
// pero esto no:
//  gcc -Wall -Werror -std=c99 -pedantic -L./ -o 06_main.exe    -l06_lib   06_main.c
//
// El codigo 06_main.c tiene funciones sin resolver (by2 y by3)
// que se encuentran en la lib lib06_lib.a. En otras palabras, 06_main.c
// depende de lib06_lib.a.
// En la linea de comandos hay que asegurarse que *todos* los dependientes
// de una libreria esten a la *izquierda* de ella.
//
//
// Bien! has terminado este tutorial. Continua en 07_shared_libs/07_main.c
//
int by2(int);
int by3(int);

int main(int argc, char* argv[]) {
    return by2(3) + by3(2);
}
