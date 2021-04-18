#include <iostream>
#include <random>

#include "../include/vector.h"
#include "../include/traza.h"

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
};


template<class Clave>
class Insercion : public BaseSort<Clave> {
  TrazaInsercion trazai_;
 public:
  Insercion(const Vector<Clave>& kVector) : BaseSort<Clave>(kVector), trazai_(kVector.get_sz()) {
    this->traza_ = &trazai_;
  }
  Insercion(const unsigned& kSize) : BaseSort<Clave>(kSize), trazai_(kSize) {
    this->traza_ = &trazai_;
  }

  void Sort(void) {
    for (unsigned i = 1; i < this->vector_.get_sz(); i++) {
      insertar(this->vector_,i,this->vector_[i]);
    }
    trazai_.RecogerTraza(this->vector_, this->vector_.get_sz());
  }

  void insertar(Vector<Clave>& vector_ordenado, int i, const Clave nuevo_elemento) {
    int j = i - 1;
    trazai_.RecogerTraza(vector_ordenado, i);
    while ((j >= 0) && (nuevo_elemento < vector_ordenado[j])) {
      vector_ordenado[j + 1] = vector_ordenado[j];
      j--;
    }
    vector_ordenado[j + 1] = nuevo_elemento;
    trazai_.Recoger_j(j + 1);
  }
}; 


template<class Clave>
class QuickSort : public BaseSort<Clave> {
  TrazaQuickSort trazaq_;
 public:
  QuickSort(const Vector<Clave>& kVector) : BaseSort<Clave>(kVector),  trazaq_(kVector.get_sz()) {
    this->traza_ = &trazaq_;
  }
  QuickSort(const unsigned& kSize) : BaseSort<Clave>(kSize),  trazaq_(kSize) {
    this->traza_ = &trazaq_;
  }

  void Sort(void) {
    int ini = 0, fin = this->vector_.get_sz() - 1;
    QSort(this->vector_,ini,fin);
  }

  void QSort(Vector<Clave>& sec, int ini, int fin) {
    int i = ini, f = fin;
    Clave p = sec[(i + f) / 2];
    while (i <= f) {
      trazaq_.set_pivote_info(sec, p, i, f, ini, fin);
      while (sec[i] < p) i++;
      while (sec[f] > p) f--;
      if (i <= f) {
        this->vector_.swap(i,f);
        i++;
        f--;
      }
    }
    if (ini < f) QSort(sec, ini, f);
    if (i < fin) QSort(sec, i, fin);
  }

};