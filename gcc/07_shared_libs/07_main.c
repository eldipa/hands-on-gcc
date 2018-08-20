// [1]
// Armar una libreria dinamica (shared)
// ------------------------------------
//
//  Compilar la libreria generando codigo cuyos offsets son independientes
//  (aka no hardcodeados)
//
//  gcc -Wall -Werror -std=c99 -pedantic -fPIC -shared -o 07_lib.so 07_libby2.c 07_libby3.c
//
//      -fPIC       el codigo generado no asume posiciones fijas en memoria
//                  sino relativas a una posicion "a definir". Este nivel de
//                  indireccion es representado por la estructura GOT (global
//                  offset table) que es completada al momento que un ejecutable
//                  carga la libreria dinamica.
//
//      -shared     genera una libreria dinamica que puede ser cargada en un ejecutable
//                  en tiempo de load (cuando el programa se carga a memoria) o incluso
//                  en tiempo de ejecucion (el mismo programa que ya esta corriendo
//                  puede cargar esta libreria)
//

// [2]
// Armar el ejecutable
// -------------------
//
// Notese como *no* estamos linkeando con la libreria 07_lib.so.
//
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -o 07_main.exe  07_main.c -ldl
//
//      -ldl        Carga la libreria dl necesaria con las definiciones de las
//                  funciones dlopen, dlsym, dlerror y dlclose entre otras.
//                  Dichas funciones nos permitiran cargar una libreria dinamica
//                  en tiempo de ejecucion.

#include <dlfcn.h>
#include <stdio.h>

typedef int (*func_pointer)(int);

int print_error_and_close(void *shared_lib, const char *msj, const char *err) {
    printf("%s: %s\n", msj, err);
    dlclose(shared_lib);
    return -1;
}

int main(int argc, char* argv[]) {
    const char *err;
    // [3]
    // En tiempo de ejecucion podemos carga en memoria una libreria dinamica o
    // shared library. En linux estas librerias tienen extension .so, en windows
    // se las conocen como DLLs.
    //
    // Usar dlerror para obtener un mensaje de error en caso de que alguna de
    // estas funciones dl* falle.
    void *shared_lib = dlopen("./07_lib.so", RTLD_NOW);
    err = dlerror();
    if (!shared_lib) {
        printf("dlopen failed: %s\n", err);
        return -1;
    }

    // [4]
    // Con la libreria en memory podemos obtener punteros a las funciones
    // que alli se encuentran definidas.
    // Para ello debemos conocer los nombres de las funciones
    func_pointer by2;
    *(void**) (&by2) = dlsym(shared_lib, "by2"); // [5] tomese un tiempo para
    err = dlerror();                             // entender ese casteo

    if(err)
        return print_error_and_close(shared_lib, "dlsym for by2 failed", err);


    func_pointer by3;
    *(void**) (&by3) = dlsym(shared_lib, "by3"); // [6] asegurese de haber
    err = dlerror();                             // entendido este casteo

    if(err)
        return print_error_and_close(shared_lib, "dlsym for by3 failed", err);


    // [7]
    // Ahora usamos esos punteros a funcion normalmente.
    // Notese que nada impide cargar otras librerias dinamicas e incluso cambiar
    // la definicion de estas funciones en tiempo de ejecucion!
    //
    // No crea que solo lenguajes dinamicos como Python o Ruby pueden hacer
    // magia,
    //
    //          Don't underestimate C.
    //                          -- Darth Vader
    //
    int result = by2(3) + by3(2);

    // [8]
    // Como todo recurso, hay que liberarlo luego de su uso.
    //
    // Bien! has terminado este tutorial. Continue en 08_includes/08_main.c
    dlclose(shared_lib);

    return result;
}
