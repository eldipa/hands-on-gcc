# Makefiles

## Introducción

Para simplificar la compilación, es muy común utilizar *make* para ejecutar las de compilación.
Make por defecto busca un archivo conocido como *Makefile*, que posee el siguiente esquema:

~~~ {.make}
target: dependencias
	instrucciones

otroTarget: otroTargetMas
	más instrucciones
~~~

El target por defecto es el primero que no tiene un "." por delante. Por convención el primer target es *all*

*** Ver Ejemplo 1 ***

### Phony: targets virtuales

Cuando se ejecuta un target, se revisa el timestamp del archivo con el mismo nombre, y el de sus dependencias, recursivamente. Si no hubo modificación en las dependencias (posterior al target), el target se encuentra actualizado, por lo que no se ejecuta.

Como se puede ver, el ejemplo tiene el grave defecto que si existen archivos all o clean, estos targets se ejecutarían siempre (excepto que actualicen dichos archivos). Es más, en el caso de clean, como no hay dependencias, se considera que siempre está al día, y nunca se ejecuta.

Para evitar esto se declaran estos targets como virtuales utilizando *.PHONY*

### Variables

*make* permite utilizar variables, viniendo con varias ya predefinidas para mayor flexibilidad.
Las variables se identifican porque vienen entre paréntesis precedidas de un signo "$"

Algunas variables ya vienen predefinidas, como por ejemplo, en un entorno linux *CC* suele referenciar a *gcc*, *CXX* a *g++*, *RM* a *rm -f*, entre otros.

También podemos declarar nuestras propias variables, lo que es una muy buena práctica para no hardcodear valores a lo largo del makefile.

*** Ver Ejemplo 2 ***

Como se puede ver, ahora los archivos objeto dependen de los *.cpp*. Por un lado la notación es más sencilla, pero por otro lado, modificar cualquier *.cpp* involucra recompilar todos los archivos objeto. Además, al ser una única tarea, no es paralelizable.
Una posible solución es crear a mano un target *.o* por cada *.cpp* presente, pero claramente esto es incómodo y poco viable.

#### Variables automáticas

Durante la ejecución de un target se crean distintas variables, por ejemplo:

* **$@**: Nombre del target

* **$<**: Nombre del primer prerequisito

* **$?**: Nombres de las dependencias que son más nuevas que el target

#### Patrones

Otro feature interesante es el de *pattern matching*. Utilizando el símbolo **%** declaro reglas implícitas, que son llamadas sobre cualquier target que haga match con el patrón utilizado.

*** Ver ejemplo 3 ***

Este ejemplo, si bien es paralelizable, tiene el defecto de que no detecta árboles de dependencias. Por ejemplo, si mi clase Foo hereda de Bar, y modifico la clase Bar, Foo no se recompila.

### Detección de dependencias básicas

Para crear un detector de dependencias básicos, utilizaremos el comando *gcc -MM*, que genera un listado de dependencias para los archivos pasados por parámetro.

Este generaremos un archivo .dep por cada target de compilación (Por fines didácticos se hará cambiando la extensión de .o a .cpp). Luego se incluirá el contenido de este .dep a dentro del makefile, sólo como targets con dependencias, sin ninguna instrucción en particular.

\newpage

# Bibliografía:

* https://linux.die.net/man/1/gcc

* https://www.gnu.org/software/make/manual/

* https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
