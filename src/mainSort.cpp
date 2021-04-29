/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Algoritmos y Estructuras de Datos avanzadas
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 17 April 2021
/// @brief Programa con distintos metodos de ordenación.
///
///
/// To compile: make
/// To clean files: make clean
/// To debug: make debug

#include <iostream>

#include "../include/clave.h"
#include "../include/sort.h"
#include "../include/funcionmenu.h"


int main(int argc, char *argv[]) {
  Usage(argc, argv);
  cabecera();
  BaseSort<Clave>* metodo_sort = elegir_contenedor(1);
  visualizar_traza(metodo_sort);
  return 0;
}





