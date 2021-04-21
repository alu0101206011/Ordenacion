#include <iostream>
#include <random>

#include "../include/vector.h"
#include "../include/traza.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define UNDERLINE "\033[4m"  /* Underline text */
#define BOLD "\033[1m"


template<class Clave>
class BaseSort {
 protected:
  Vector<Clave> vector_;
  Traza* traza_;
 public:
  BaseSort(const Vector<Clave>& kVector) : vector_(kVector) {}
  BaseSort(const unsigned& kSize) : vector_(kSize) {
    srand(time(NULL));
    for (unsigned i = 0; i < vector_.get_sz(); i++)
      vector_[i] = (rand() % 1000) + 1;
  }

  Traza* get_traza(void) { return traza_; }
  Traza* get_traza(void) const { return traza_; }

  Vector<Clave> get_vector(void) const { return vector_; }

  virtual void Sort(void) = 0;
  virtual void SortTraza(void) = 0;

  
};


template<class Clave>
class Insercion : public BaseSort<Clave> {
 public:
  Insercion(const Vector<Clave>& kVector) : BaseSort<Clave>(kVector) {}
  Insercion(const unsigned& kSize) : BaseSort<Clave>(kSize) {}

  void Sort(void) {
    for (unsigned i = 1; i < this->vector_.get_sz(); i++)
      insertar(this->vector_,i,this->vector_[i]);
  }

  void insertar(Vector<Clave>& vector_ordenado, int i, const Clave nuevo_elemento) {
    int j = i - 1;
    while ((j >= 0) && (nuevo_elemento < vector_ordenado[j])) {
      vector_ordenado[j + 1] = vector_ordenado[j];
      j--;
    }
    vector_ordenado[j + 1] = nuevo_elemento;
  }

  void SortTraza(void) {
    for (unsigned i = 1; i < this->vector_.get_sz(); i++) 
      insertarTraza(this->vector_,i,this->vector_[i]);
    mostrar_traza(this->vector_.get_sz());
    std::cout << "\n";
  }

  void insertarTraza(Vector<Clave>& vector_ordenado, int i, const Clave nuevo_elemento) {
    int j = i - 1;
    mostrar_traza(i);
    while ((j >= 0) && (nuevo_elemento < vector_ordenado[j])) {
      vector_ordenado[j + 1] = vector_ordenado[j];
      j--;
    }
    vector_ordenado[j + 1] = nuevo_elemento;
    std::cout << "\tj = " << j + 1 << "\n";
  }

  void mostrar_traza(unsigned i) const {
    std::cout << "i = " << i << "\t";
    for (unsigned j = 0; j < this->vector_.get_sz(); j++) {
      if (j < i || i == this->vector_.get_sz()) {
        std::cout << GREEN << this->vector_[j] << " " << RESET;
      } else if (j == i) {
        std::cout << RED << this->vector_[j] << " " << RESET;
      } else {
        std::cout << this->vector_[j] << " ";
      }
    }
  }
}; 


template<class Clave>
class QuickSort : public BaseSort<Clave> {
 public:
  QuickSort(const Vector<Clave>& kVector) : BaseSort<Clave>(kVector) {}
  QuickSort(const unsigned& kSize) : BaseSort<Clave>(kSize) {}

  void Sort(void) {
    int ini = 0, fin = this->vector_.get_sz() - 1;
    QSort(this->vector_,ini,fin);
  }

  void QSort(Vector<Clave>& sec, int ini, int fin) {
    int i = ini, f = fin;
    Clave p = sec[(i + f) / 2];
    while (i <= f) {
      while (sec[i] < p) i++;
      while (sec[f] > p) f--;
      if (i <= f) {
        if (i != f) {
          this->vector_.swap(i,f);
        }
        i++;
        f--;
      }
    }
    if (ini < f) QSort(sec, ini, f);
    if (i < fin) QSort(sec, i, fin);
  }

  void SortTraza(void) {
    int ini = 0, fin = this->vector_.get_sz() - 1;
    QSortTraza(this->vector_,ini,fin);
  }

  void QSortTraza(Vector<Clave>& sec, int ini, int fin) {
    int i = ini, f = fin;
    Clave p = sec[(i + f) / 2];
    muestra_traza_pivote(sec, p, ini, fin, i, f);
    while (i <= f) {
      while (sec[i] < p) i++;
      while (sec[f] > p) f--;
      if (i <= f) {
        if (i != f) {
          this->vector_.swap(i,f);
          muestra_traza(sec, ini, fin, i, f);
        }
        i++;
        f--;
      }
    }
    if (ini < f) QSortTraza(sec, ini, f);
    if (i < fin) QSortTraza(sec, i, fin);
  }

  void muestra_traza(Vector<Clave> sec, int ini, int fin, int i, int f) {
    for (unsigned j = 0; j < this->vector_.get_sz(); j++) {
      if ((int)j == i || (int)j == f) {
        std::cout << BOLD << RED << UNDERLINE  << " " << this->vector_[j] << RESET << UNDERLINE << " |";
      } else if ((int)j >= ini && (int)j <= fin) {
        std::cout << UNDERLINE << " " << this->vector_[j] << RESET << UNDERLINE  << " |";
      } else {
        std::cout << RESET << " " << this->vector_[j] <<  " |";
      }
    }
    std::cout << RESET << "\n";
  }

  void muestra_traza_pivote(Vector<Clave> sec, int pivote, int ini, int fin, int i, int f) {
    std::cout <<"\nPivote: " << pivote << "\tini: " << ini << "\tfin: " << fin << "\n";
    muestra_traza(sec, ini, fin, i, f);
  }
};


template<class Clave>
class ShellSort : public BaseSort<Clave> {
 private:
  float reduccion_;
 public:
  ShellSort(const Vector<Clave>& kVector, float reduccion = 0.5): BaseSort<Clave>(kVector), reduccion_(reduccion) {}
  ShellSort(const unsigned& kSize, float reduccion = 0.5) : BaseSort<Clave>(kSize), reduccion_(reduccion) {}
  
  void Sort(void) {
    int delta = /* this->vector_.get_sz(); */ 10;
    delta *= reduccion_;
    while (delta > 1) {
      DeltaSort(delta, this->vector_, this->vector_.get_sz());
      delta *= reduccion_;
    }
  }

  void DeltaSort(int delta, Vector<Clave>& vector, int tam) {
    for (int i = delta; i < tam; i++) {
      Clave x = vector[i];
      int j = i;
      while ((j >= delta) && (x < vector[j - delta])) {
        vector[j] = vector[j - delta];
        j = j - delta;
      }
      vector[j] = x;
    }
  }

  void SortTraza(void) {
    int delta = /* this->vector_.get_sz(); */ 10;
    while (delta > 1) {
      delta *= reduccion_;
      DeltaSortTraza(delta, this->vector_, this->vector_.get_sz());
    }
  }

  void DeltaSortTraza(int delta, Vector<Clave>& vector, int tam) {
    std::cout << "\nDelta: " << delta << "\n";
    for (int i = delta; i < tam; i++) {
      Clave x = vector[i];
      int j = i;
      mostrar_traza(delta, j, x);
      while ((j >= delta) && (x < vector[j - delta])) {
        vector[j] = vector[j - delta];
        j = j - delta;
      }
      vector[j] = x;
    }
  }
  
  void mostrar_traza(int delta, int j, Clave x) {
    std::vector<int> marcados;
    int i = j;
    marcados.push_back(j);
    if (delta != 1) {
      while (j >= delta) {
        j -= delta;
        marcados.push_back(j);
      }
    }
    for (unsigned k = 0; k < this->vector_.get_sz(); k++) {
      if (marcados.back() == (int)k && (int)k < i && delta != 1) {
        std::cout << RED << UNDERLINE << " " << this->vector_[k];
        marcados.pop_back();
      } else if (marcados.back() == (int)k && !((int)k < i)) {
        std::cout << RESET << RED << " " << this->vector_[k];
        marcados.pop_back();
      } else if (((int)k < i)) {
        std::cout << RESET << UNDERLINE << " " << this->vector_[k];
      } else if (marcados.back() != (int)k && !((int)k < i)) {
        std::cout << RESET << " " << this->vector_[k];
      }
    }
    std::cout << RESET << "\n";
  }
}; 