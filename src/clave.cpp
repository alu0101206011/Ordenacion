#include <iostream>
#include <random>

#include "../include/clave.h"

const char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const unsigned num_size = 3;


void Clave::build(void) {
  numeros_ = new int[num_size]; 
}

Clave::Clave(void) {
  build();
  letra1_ = abecedario[rand() % (sizeof(abecedario) - 1)];
  for (unsigned i = 0; i < num_size; i++) 
    numeros_[i] = rand() % 10;
  letra2_ = abecedario[rand() % (sizeof(abecedario) - 1)];
}

Clave::Clave(const Clave& kNewClave) {
  build();
  *this = kNewClave;
}

char Clave::get_letra1(void) const {
  return letra1_;
}

char Clave::get_letra2(void) const {
  return letra2_;
}

int* Clave::get_numeros(void) const {
  return numeros_;
}

Clave& Clave::operator=(const Clave& kNewClave) {
  letra1_ = kNewClave.get_letra1();
  for (unsigned i = 0; i < num_size; i++) 
    numeros_[i] = kNewClave.get_numeros()[i];
  letra2_ = kNewClave.get_letra2();
  return *this;
}


bool Clave::operator==(const Clave& kNewClave) const {
  if (letra1_ != kNewClave.get_letra1()) return false;
  for (unsigned i = 0; i < num_size; i++) 
    if (numeros_[i] != kNewClave.get_numeros()[i]) return false;
  if (letra2_ != kNewClave.get_letra2()) return false;
  return true;
}


bool Clave::operator!=(const Clave& kNewClave) const {
  return !(*this == kNewClave);
}


bool Clave::operator<(const Clave& kNewClave) const {
  if (letra1_ < kNewClave.get_letra1()) {
    return true;
  } else if (letra1_ != kNewClave.get_letra1()) {
    return false;
  }
  for (unsigned i = 0; i < num_size; i++) {
    if (numeros_[i] < kNewClave.get_numeros()[i]) return true;
    else if (numeros_[i] != kNewClave.get_numeros()[i]) return false;
  }
  if (letra2_ < kNewClave.get_letra2()) 
    return true;
  return false;
}


bool Clave::operator>(const Clave& kNewClave) const {
  if (*this != kNewClave)
    return !(*this < kNewClave);
  return false;
}


std::ostream& operator<<(std::ostream& os, const Clave& kNewClave) {
  os << kNewClave.get_letra1();
  for (unsigned i = 0; i < num_size; i++) 
    os << kNewClave.get_numeros()[i];
  os << kNewClave.get_letra2();
  return os;
}