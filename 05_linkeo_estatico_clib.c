// [1] Armar un ejecutable (gcc va a precompilar, compilar y linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -static -o 05_linkeo_estatico_clib.exe 05_linkeo_estatico_clib.c
//
//      -static:    fuerza a que el linkeo sea estatico, agregando el codigo objeto al binario final


// [2] Ver el codigo compilado con:
//  objdump -S -d 05_linkeo_estatico_clib.exe
//

// [4] Ver cuanto pesa el binario y comparalo con el binario del tutorial anterior
//
// Bien! has terminado este tutorial. Continua en 06_libs/06_main.c

int puts(const char*); // [3] esta funcion, donde esta definida?
                       // objdump va a mostrar que el codigo de puts *si*
                       // esta en el binario: verificarlo!

void say_hello() {
    puts("Hello");
}



void say_hello();

int main(int argc, char* argv[]) {
    say_hello();
    say_hello();
    say_hello();
}
