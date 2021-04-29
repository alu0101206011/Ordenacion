template <class Clave> class Vector;
template <class Clave> std::ostream& operator<<(std::ostream&, const Vector<Clave>&);

template <class Clave>
class Vector {
 private:
  Clave* vector_;
  unsigned sz_;
 public:
  Vector(void);
  Vector(unsigned);
  Vector(const Vector<Clave>&);

  ~Vector();

  Clave* get_vector(void) const;
  unsigned get_sz(void) const;

  void set_sz(const unsigned);
  void swap(unsigned, unsigned);

  Vector<Clave>& operator=(const Vector<Clave>&);
  bool operator==(const Vector<Clave>&);
  Clave& operator[](const unsigned&);
  Clave operator[](const unsigned&) const;


  friend std::ostream& operator<<(std::ostream& os, const Vector<Clave>& kVector) {
    if (kVector.get_sz() > 0) 
      os << kVector[0];
    for (unsigned i = 1; i < kVector.get_sz(); i++) {
      os << " ";
      os << kVector[i];
    }
    return os;
  }
};