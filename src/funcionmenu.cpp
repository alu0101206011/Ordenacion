#include <iostream>
#include <string>

#include "../include/clave.h"
#include "../include/sort.h"
#include "../include/funcionmenu.h"

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

void cabecera(void) {
  system("clear");
  std::cout << "----------------------------------"
            << "\n|                                |\n"
            << "|           Ordenación           |"
            << "\n|                                |\n"
            << "----------------------------------\n\n";
}

BaseSort<int>* elegir_contenedor(void) {
  BaseSort<int>* metodo;
  int opcion = -1;
  std::cout << "Elija un tamaño para el vector: ";
  unsigned size = control_errores_int();
  std::cout << "Pulse 0 para vector aleatorio.\nPulse 1 para introducir elementos para el vector.\n";
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: metodo = elegir_ordenacion(size); break;
    case 1: metodo = elegir_ordenacion(elegir_vector(size)); break;
    default: 
    std::cout << "\nError, seleccione 1 o 0.\n";
    opcion = -1; break;
    }
  }
  return metodo;
}

Vector<int> elegir_vector(unsigned size) {
  Vector<int> vector(size);
  std::cout << "\nIntroduzca los elementos del vector.\n";
  for (unsigned i = 0; i < size; i++) {
    std::cout << "Elemento [" << i << "]: ";
    vector[i] = control_errores_int();
  }
  return vector;
}

BaseSort<int>* elegir_ordenacion(unsigned size) {
  int opcion = -1;
  float reduccion = 0;
  std::cout << "\n[0] Inserción\n[1] QuickSort\n[2] ShellSort\n";
  BaseSort<int>* Base = NULL;
  Vector<int> vector(size);
  for (unsigned i = 0; i < size; i++) {
    vector[i] = (rand() % 1000) + 1;
  }
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: return Base = new Insercion<int>(vector);
    case 1: return Base = new QuickSort<int>(vector);
    case 2: 
    std::cout << "\nIntroduzca la constante de reducción alpha: ";
    reduccion = control_errores_float();
    return Base = new ShellSort<int>(vector, reduccion);
    default: 
    std::cout << "\nError, seleccione 2, 1 o 0.\n";
    opcion = -1; break;
    }
  }
  return Base; 
} 

BaseSort<int>* elegir_ordenacion(Vector<int> vector) {
  int opcion = -1;
  float reduccion = 0;
  std::cout << "\n[0] Inserción\n[1] QuickSort\n[2] ShellSort\n";
  BaseSort<int>* Base = NULL;
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: return Base = new Insercion<int>(vector);
    case 1: return Base = new QuickSort<int>(vector);
    case 2: 
    std::cout << "\nIntroduzca la constante de reducción alpha: ";
    reduccion = control_errores_float();
    return Base = new ShellSort<int>(vector, reduccion);
    default: 
    std::cout << "\nError, seleccione 2, 1 o 0.\n";
    opcion = -1; break;
    }
  }  
  return Base;
}

void visualizar_traza(BaseSort<int>* metodo_traza) {
  int opcion = -1;
  std::cout << "\n[0] Visualizar la traza.\n[1] No visualizar la traza.\n";
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: metodo_traza->SortTraza(); break;
    case 1: 
    std::cout << "\n\nEstado incial del vector: " << metodo_traza->get_vector() << "\n";
    metodo_traza->Sort();
    std::cout << "\n\nResultado final: " << metodo_traza->get_vector() << "\n"; break;
    default: 
      std::cout << "\nError, seleccione 1 o 0.\n";
      opcion = -1; break;
    }
  }
}

int control_errores_int(void) {
  std::string param;
  std::cin >> param;
  do {
    if (!isdigit(param[0])) {
      if (param[0] == '-' && param.length() > 1) {
        if (isdigit(param[1])) {
          break;
        }
      } else {
        std::cout << "\nSe ha introducido una opción no válida\n";
        std::cout << "Introduzca una opción otra vez: ";
        std::cin >> param;
      }
    } 
  } while (!isdigit(param[0]));
  int number = stoi(param);
  return number;
}


unsigned control_errores_unsigned(int number) {
  while (number < 0) {
    std::cout << "El número introducido es negativo.\nIntentelo de nuevo.";
    number = control_errores_int();
  }
  return (unsigned)number;  
}

float control_errores_float(void) {
  std::string param;
  std::cin >> param;
  do {
    if (!isdigit(param[0])) {
      std::cout << "\nSe ha introducido una opción no válida\n";
      std::cout << "Introduzca una opción otra vez: ";
      std::cin >> param;
    } 
  } while (!isdigit(param[0]));
  float number = stof(param);
  return number;
}



//#########################################################################    
BaseSort<Clave>* elegir_contenedor(int modo_clave) {
  BaseSort<Clave>* metodo;
  std::cout << "Elija un tamaño para el vector: ";
  unsigned size = control_errores_int();
  std::cout << "\nSe le asignarán Claves aleatorios.\n";
  Vector<Clave> vector(size);
  for (unsigned i = 0; i < size; i++) {
    Clave clave;
    vector[i] = clave;
  }
  metodo = elegir_ordenacion(size, 1);
  return metodo;
}

BaseSort<Clave>* elegir_ordenacion(Vector<Clave> vector, int modo_clave) {
  int opcion = -1;
  float reduccion = 0;
  std::cout << "\n[0] Inserción\n[1] QuickSort\n[2] ShellSort\n";
  BaseSort<Clave>* Base = NULL;
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: return Base = new Insercion<Clave>(vector);
    case 1: return Base = new QuickSort<Clave>(vector);
    case 2: 
    std::cout << "\nIntroduzca la constante de reducción alpha: ";
    reduccion = control_errores_float();
    return Base = new ShellSort<Clave>(vector, reduccion);
    default: 
    std::cout << "\nError, seleccione 2, 1 o 0.\n";
    opcion = -1; break;
    }
  }  
  return Base;
}

void visualizar_traza(BaseSort<Clave>* metodo_traza) {
  int opcion = -1;
  std::cout << "\n[0] Visualizar la traza.\n[1] No visualizar la traza.\n";
  while (opcion == -1) {
    std::cout << "\tSeleccione uno: ";
    opcion = control_errores_int();
    switch (opcion) {
    case 0: 
    std::cout << "\n\n Vector inicial: " << metodo_traza->get_vector() << "\n";
    metodo_traza->SortTraza(); break;
    case 1: 
    std::cout << "\n\n Vector inicial: " << metodo_traza->get_vector() << "\n";
    metodo_traza->Sort();
    std::cout << "\n\nResultado final: " << metodo_traza->get_vector() << "\n"; break;
    default: 
      std::cout << "\nError, seleccione 1 o 0.\n";
      opcion = -1; break;
    }
  }
}