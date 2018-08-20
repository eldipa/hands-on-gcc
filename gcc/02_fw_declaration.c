// [1] Generar codigo objeto (sin linkear) con:
//  gcc -Wall -Werror -std=c99 -pedantic -c 02_fw_declaration.c
//
// Error, eh? Tomese un segundo para leer el error y tratar de interpretarlo.
//
// Es importante esto por que en la vida real usted se enfrentara a errores como
// estos y no habra un comentario como este que le indique como solucionarlo.
//
// Luego, ver los comentarios de la funcion foofunc [2]
//



// [3]
// forward declaration
// -------------------
// descomentar esto para garantizarle al compilador
// que en algun lado existe una estructura llamada Person y vuelve a compilar
//
// struct Person;

// [4] Descomenta esto tambien para decirle al compilador que existe una
// funcion llamada person_print_name con esta firma:
//
// void person_print_name(struct Person*);


// [5] Vuelve a compilar. Ahora compila?
//
// Esto se lo conoce como declaracion adelantada o forward
// declaration. Se usa para decirle al compilador que una estructura o
// funcion existen en algun lado y que nosotros (los programadores) confirmamos
// su existencia.
//
// Bien! has terminado este tutorial. Tu siguiente desafio esta en 03_size_and_offsets.c



// [2] Ya compilaste como lo dice [1] ? No sigas si no lo hiciste o si no
// leiste los mensajes de error del compilador.
//
// Es muy IMPORTANTE leerlos para que los puedas reconocer y entender.
// Es TU DECISION si invertis tiempo ahora o dejarlo a la suerte.
//
// El compilador sabe el size de un puntero y tiene toda la informacion
// para generar codigo objeto pero no puede validarlo
//  - Como sabe el compilador que struct Person existe y no es un typo
//    del programador?
//  - Como sabe que person_print_name existe y que recibe un solo argumento
//    y de ese tipo?
//
// Sin esa informacion el compilador no puede chequear la sintaxis/semantica
// y fallara por que estamos compilando en modo stricto:
//      -Wall -Werror -std=c99 -pedantic
//
// Solo en muy raras ocaciones se debe relajar esos chequeos.
void foofunc(struct Person *person) {
    person_print_name(person);
}

