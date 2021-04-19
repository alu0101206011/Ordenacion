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
  Vector<int> vector(14);
  vector[0] = 13;
  vector[1] = 3;
  vector[2] = 4;
  vector[3] = 12;
  vector[4] = 14;
  vector[5] = 10;
  vector[6] = 5;
  vector[7] = 1;
  vector[8] = 8;
  vector[9] = 2;
  vector[10] = 7;
  vector[11] = 9;
  vector[12] = 11;
  vector[13] = 6; 

  metodo_sort = new ShellSort<int>(vector, 0.5);
  
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
