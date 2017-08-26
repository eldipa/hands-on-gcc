# Ejemplo de bibliotecas externas

En este ejemplo se utiliza la biblioteca libzip para abrir un archivo zip e imprimir los nombres de los archivos que contiene.

## Makefile

El makefile posee los siguientes *targets*:

* *demo.zip*: Construye un archivo "demo.zip" que contiene 2 archivos, fooFile y barFile.

* *demo*: Compila la aplicación utilizando la biblioteca libzip dinámica.

* *static*: Compila la aplicación, pero en la mitad cambia la preferencia de bibliotecas a estáticas, linkea libzip.a y libz.a, y luego restaura la preferencia a bibliotecas dinámicas.

* *clean*: limpia el directorio

El target default (*all*) llama tanto a la construcción de demo.zip como al compilado con tipado dinámico.

## Algunos comandos interesantes

Para ver el tamaño que ocupa cada uno de los binarios, correr *ls -l*, observar que el target de compilación estática pesa mucho más que el que vincula dinámicamente.
Para saber contra qué bibliotecas se vincula nuestra aplicación, utilizar ldd. Observar que en la versión dinámica, a diferencia de la estática, se linkea contra libzip y libz.
