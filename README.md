# Ordenación
Algoritmos y Estructuras de Datos Avanzadas.

Curso 2020-2021.

## Práctica 7: Implementación de métodos de ordenación (I)
### Objetivo 
El objetivo de esta práctica es trabajar con algoritmos de ordenación interna y realizar la implementación en lenguaje C++.


### Entrega
La entrega se realizará en la sesión de laboratorio entre el 19 y el 23 de abril. Durante esta sesión se podrán solicitar modificaciones sobre el enunciado de la práctica.

En el actual escenario de presencialidad adaptada, la entrega se realizará en tareas
separadas para la rotación con asistencia presencial y la rotación con asistencia online. Si la ULL cambiase al escenario 2, docencia online, se comunicará la forma de entrega a través del aula virtual.


### Enunciado
Se pide implementar en lenguaje C++, al menos, los siguientes métodos de ordenación:
* Inserción
* QuickSort
* Por Incrementos Decrecientes (ShellSort): debe permitir seleccionar la constante de reducción alfa, siendo 0 < alfa < 1

El programa realizado debe permitir observar la traza del funcionamiento de cada algoritmo para secuencias pequeñas.

La implementación de cada método de ordenación se realizará mediante una **plantilla de función** en la que se especificará el tipo de elementos a ordenar (``Clave``). La función recibirá como parámetros la secuencia a ordenar con elementos de tipo ``Clave`` y su tamaño:
``` 
nombre_método<Clave> (vector<Clave>, tamaño) 
```

El programa principal va a ejecutar los métodos con ``Clave=int``. Solicitará al usuario el algoritmo a ejecutar, el tamaño de la secuencia a ordenar (``N``) y si se desea mostrar la traza de ejecución. También permitirá elegir entre introducir los ``N`` valores manualmente o generarlos de forma aleatoria. En este caso, se generarán valores aleatorios entre 1 y 1000.

Al ejecutar con la opción de mostrar la traza se presentará en pantalla el resultado de cada comparación, indicando los elementos del vector que son comparados y cómo queda la secuencia tras la comparación y la acción realizada.

### Referencias
1.- [Transparencias de clase](https://campusingenieriaytecnologia.ull.es/pluginfile.php/334715/mod_resource/content/15/Tema3_Ordenacion.pdf)

2.- [Algoritmo de ordenamiento](https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento)
