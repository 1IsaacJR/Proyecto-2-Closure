# Proyecto-2-Closure

Integrantes del proyecto: Isaac Rivera Jimenez\ No.Cuenta: 321225087\ González Gutiérrez Antonio Tonatiuh\ No.Cuenta: 321195476 \ Cervantes Farias Santiago\
No. Cuenta: 321155797\ 


Este proyecto contiene ejemplos en C++ que ilustran el funcionamiento de:

- Funciones de orden superior
- Closures y capturas léxicas
- Simulación de funciones sin closures y como afectarian las funciones de orden superior

El objetivo es mostrar cómo se preserva el ambiente léxico y la diferencia con el paso de parámetros convencional.

Archivos:
- main.cpp : Contiene la implementación de todas las funciones
- README.md : Este archivo de instrucciones.

Requisitos:

- Compilador C++ moderno que soporte C++11 o superior, por ejemplo:
  - g++ >= 5
  - clang++ >= 3.5
- Sistema operativo: Windows, Linux, macOS

Compilación:
Abrir la terminal y ejecutar:
g++ -std=c++11 -o main main.cpp

- -std=c++11 asegura soporte para lambdas y closures.
- -o main indica que el ejecutable se llamará main.

Ejecución:

Una vez compilado, ejecutar:

./main

Salida esperada:

1. Ejecución del closure fnc():

1
2
3
4
5

2. Ejecución de function1() (con lambdas y closures):

In function2: x = 7, a = 7
In function3: x = 7, a = 7
Notas:

- Los ejemplos muestran la preservación del estado en closures mediante capturas de variables.
- La versión sin closures utiliza paso de parámetros para lograr resultados equivalentes, pero no preserva un ambiente privado.
- Para modificar los valores iniciales de prueba, edita px, pa o los valores dentro de las lambdas en main.cpp.
