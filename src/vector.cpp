#include <iostream>

#include "../include/vector.h"

template <class Clave>
Vector<Clave>::Vector(void): sz_(0) { 
  vector_ = 0;
}


template <class Clave>
Vector<Clave>::Vector(unsigned sz): sz_(sz) {
  vector_ = new Clave[sz_];
  fill_number(0);
}


template <class Clave> 
Vector<Clave>::Vector(const Vector<Clave>& kNewVector) {
  sz_ = kNewVector.get_sz();
  vector_ = new Clave[sz_];
  for (unsigned i = 0; i < sz_; i++) {
    (*this)[i] = kNewVector[i];
  }  
}


template <class Clave> 
Vector<Clave>::~Vector() {
  delete[] vector_;
}


template <class Clave> 
Vector<Clave>& Vector<Clave>::operator=(const Vector<Clave>& kNewVector) {
  delete[] vector_;
  sz_ = kNewVector.get_sz();
  vector_ = new Clave[sz_];
  for (unsigned i = 0; i < sz_; i++) {
    (*this)[i] = kNewVector[i];
  }  
  return *this;
}


template <class Clave> 
bool Vector<Clave>::operator==(const Vector<Clave>& kNewVector) {
  if (kNewVector.get_sz() != sz_) return false;
  for (unsigned i = 0; i < sz_; i++)
    if (vector_[i] != kNewVector.get_vector()[i])
      return false;
  return true;
}


template <class Clave> 
Clave& Vector<Clave>::operator[](const unsigned& i) {
  if (i < 0 || i >= sz_) {
    std::cout << "Vector fuera de rango.\n";
    exit(1);
  } else {
    return vector_[i];
  }
}


template <class Clave> 
Clave Vector<Clave>::operator[](const unsigned& i) const {
  if (i < 0 || i >= sz_) {
    std::cout << "Vector fuera de rango.\n";
    exit(1);
  } else {
    return vector_[i];
  }
}


template <class Clave>
Clave* Vector<Clave>::get_vector(void) const {
  return vector_;
}


template <class Clave>
unsigned Vector<Clave>::get_sz(void) const {
  return sz_;
}


template <class Clave>
void Vector<Clave>::set_sz(const unsigned kNewsz)  {
  sz_ = kNewsz;
}


template <class Clave>
void Vector<Clave>::swap(unsigned x, unsigned y) {
  Clave aux = (*this)[x];
  (*this)[x] = (*this)[y];
  (*this)[y] = aux; 
}


template <class Clave>
void Vector<Clave>::fill_number(int number) {
  for (unsigned i = 0; i < sz_; i++)
    vector_[i] = number;
}


// Declaración explicita de instanciación de template class
template class Vector<int>;