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

#include "../include/sort.h"

void Usage(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  Usage(argc, argv);

  BaseSort<int>* metodo_sort;
  metodo_sort = new QuickSort<int>(10);
  
  std::cout << metodo_sort->get_vector() << "\n";
  metodo_sort->Sort();
  std::cout << metodo_sort->get_vector() << "\n";
  std::cout << *(metodo_sort->get_traza());
  //std::cout << metodo_sort->get_vector() << "\n";

  return 0;
}


void Usage(int argc, char *argv[]) {
  if (argc == 2)
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
      std::cout << "Uso: " << argv[0] << " [Sin opciones]\n";
      exit(0);
    }
  if (argc != 1) {
    std::cout << "Tiene argumentos inválidos.\nEscriba "
              << "--help para más ayuda\n";
    exit(1);
  } 
}
