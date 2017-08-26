// [3]
// Descomentar el ifndef, define y endif
// este idiom de C es usado para evitar incluir 2 veces un mismo archivo
//
//#ifndef PERSON_H_  // [4]   si no esta definido "PERSON_H_", entonces
//#define PERSON_H_  // definirlo aqui. Entonces, por logica
                     // todo este archivo solo sera incluido una unica vez
                     // (por que luego de la primera vez, PERSON_H_ ya estara definido
                     // y por lo tanto el "ifndef" siempre sera False)
                     //
                     // vuelve a 08_main.c

// En un .h hay que poner solo las declaraciones de las funciones
// y las definiciones de los struct (o clases)
struct Person {
    char c;
};

//#endif
