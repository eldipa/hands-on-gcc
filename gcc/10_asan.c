// [1]
// Armar un ejecutable (gcc va a precompilar, compilar y linkear) con:
//  gcc -std=c99 -ggdb -fno-stack-protector -o 10_asan.exe  10_asan.c
//
//      -fno-stack-protector    deshabilitamos ciertas protecciones que hace el compilador 
//                              sobre los buffers (reordenamiento en el stack y canaries)
//                              Salvo que se tenga una excelente razon, *jamas* hagas esto.
//                              Este flag esta puesto a tan solo los efectos de este ejemplo.
//
// Ejecutarlo. A pesar del buffer overflow no hay un crash...
//


// [2]
// Ejecutarlo con valgrind con:
//  valgrind ./10_asan.exe
//
// Tampoco valgrind se da cuenta del buffer overflow!!


// [3]
// Armar un ejecutable con ASAN activado "AddressSanitizer" (es un feature experimental de gcc):
//  gcc -std=c99 -ggdb -fno-stack-protector -fsanitize=address -lasan -o 10_asan.exe  10_asan.c
//
//      -fsanitize=address      habilita la generacion de codigo especial (mucho mas lento)
//                              que instrumenta los accesos a memoria y permite detectar errores
//                              como buffer overflows.
//
//      -lasan                  linkea con la libreria de ASAN
//
// Ejecutar nuevamente el binario con:
//  ASAN_OPTIONS=symbolize=1 ./10_asan.exe
//
// Wow! ASAN detecto el buffer overflow.
//
// ASAN es una nueva tecnologia para la deteccion de errores de codigo C. 
//
// Asi termina esta serie de tutoriales, pero tu entrenamiento continua mi joven padawan.
// 
//      https://www.youtube.com/watch?v=h5SNAluOj6U
//

#include <stdio.h>
void fill(char *buf, int buf_size, const char c) {
    for (int i = 0; i < buf_size; ++i) {
        buf[i] = c;
    }
}

int main(int argc, char* argv[]) {
    int cookie = 0;
    char buf[4];

    // Codigo especial para forzar un buffer overflow "chico"
    int buf_size = ((void*)&cookie - (void*)&buf[0] + 4); // <-- nunca hagan esto
    if (buf_size < 4) {printf("buuuu\n"); return 1;} // si entra en el if, el compilador alloco la variable buf antes que 
                                                     // cookie entonces no se puede pisar con un buffer overflow :(

    fill(buf, buf_size, 'A');

    printf("cookie: %x\n", cookie);

    buf[3] = 0;
    printf("buf: %s\n", buf);
    return 0;
}


