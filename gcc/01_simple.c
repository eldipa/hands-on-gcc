// [1] Ejecutar gcc y detenerlo luego de la etapa de compilacion (gcc va a
// precompilar y compilar pero no linkear) usando el flag (-c).
// Esto genera codigo objeto pero no un binario ejecutable (falta la etapa de
// linkeo):
//  gcc -Wall -Werror -std=c99 -pedantic -c  01_simple.c
//
//      -Wall       emitir todos los warnings
//      -Werror     todos los warning son considerados errores (detienen el proceso)
//      -std=c99    ser estricto y no permitir nada fuera del estandar C99
//      -pedantic   ser mas estrictos con el estandar
//      -c          gcc detiene el proceso luego de la etapa de compilacion
//
// No continues leyendo hasta no haber compilado, creeme, vale la pena hacer
// este ejercicio.
//
// Luego, sigue con el paso [2]



// [3] Ya hiciste los pasos [1] y [2] no?
// Inspeccionar el codigo objeto (compilado) con:
//  objdump -d 01_simple.o
//
//      -d          desensambla (disassembly): intenta tomar el codigo objeto (binario)
//                  y traducirlo a codigo assembly, ligeramente mas entendible para el humano.
//
//  No es necesario que entiendas todo el codigo assembly pero intenta ver donde se hace
//  la operacion de suma.
//


// [4] Generar codigo objeto (gcc va a precompilar y compilar, pero no linkear)
// pero esta vez agregandole los simbolos de debugging:
//  gcc -Wall -Werror -std=c99 -pedantic -ggdb -c 01_simple.c
//
//      -ggdb       incluye en el binario todos los simbolos y datos necesarios para poder
//                  correlacionar el codigo objeto con el codigo fuente y asi poder debuggear


// [5] Inspeccionar el codigo objeto junto con el codigo fuente con:
//  objdump -d -S 01_simple.o
//
//      -S          intenta correlacionar el codigo fuente con el codigo binario haciendo uso
//                  de los simbolos de debugging que estan en el binario.
//
//  Encontraste la operacion de suma? Requiere mas de una instruccion.


// [6] Generar codigo objeto (sin linkear) pero esta vez instruyendole a gcc
// de que haga el codigo objeto mas optimo posible
//  gcc -Wall -Werror -std=c99 -pedantic -O3 -c 01_simple.c
//
//      -On         nivel de optimizacion 'n': 0 (sin optimizar), 1 y 2 (optimizacion normal),
//                                             3 (optimizacion agresiva),
//                                             s (optimiza el tamaño del binario, no su velocidad)
//
//      **Nota:** si se quiere debuggear un programa no solo hay que usar el
//                flag -ggdb sino que tambien hay que deshabilitar explicitamente
//                cualquier optimizacion con el flag -O0. De otro modo la tarea
//                de debugging sera mucho mas dificil.


// [7] Inspeccionar el codigo objeto (compilado) una vez mas:
//  objdump -d 01_simple.o
//
// Que diferencia ves respecto al dump anterior?
//
// Bien! has terminado este tutorial. Pero el camino aun es largo mi joven padawan
// Tu entramiento continua en 02_fw_declaration.c


// [2] Los sizes de todos los parametros son conocidos asi como tambien
// los tipos completos.
// El compilador tiene toda la informacion para generar codigo objeto
// asi como tambien para validarlo.
int sumar(int a, int b) {
    int c = 0;
    c = a + b;
    return c;
}

