class Clave {
 private:
  char letra1_, letra2_;
  int* numeros_;

 public:
  Clave(void);
  Clave(const Clave& kNewClave);

  char get_letra1(void) const;
  char get_letra2(void) const;
  int* get_numeros(void) const;

  Clave& operator=(const Clave&);

  bool operator==(const Clave&) const;
  bool operator!=(const Clave&) const;
  bool operator<(const Clave&) const;
  bool operator>(const Clave&) const;  

  friend std::ostream& operator<<(std::ostream&, const Clave&);

 private:
  void build(void);
};