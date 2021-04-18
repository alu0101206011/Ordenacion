#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define UNDERLINE "\033[4m"  /* Underline text */

// Clase padre
class Traza {
 protected:
  std::vector<Vector<int>> traza_;
  unsigned size_Vector_;

 public:
  Traza(unsigned size_Vector): size_Vector_(size_Vector) {}

  std::vector<Vector<int>> get_traza(void) const { return traza_; }

  virtual std::ostream& mostrar(std::ostream& os) const = 0;

  friend std::ostream& operator<<(std::ostream& os, const Traza& kTraza) {
    kTraza.mostrar(os);
    return os;
  }

};


// Clase hija
class TrazaInsercion : public Traza {
 private:
  std::vector<int> i_, j_;

 public:
  TrazaInsercion(unsigned size_Vector) : Traza(size_Vector) {}

  std::vector<int> get_i(void) const { return i_; }
  std::vector<int> get_j(void) const { return j_; }

  void Recoger_j(const int& j) { j_.push_back(j); }

  void RecogerTraza(const Vector<int> sec, int i = -1, int j = -1) {
    i_.push_back(i);
    if (j != -1) j_.push_back(j);
    traza_.push_back(sec);
  }

  std::ostream& mostrar(std::ostream& os) const {
    for (unsigned i = 0; i < traza_.size(); i++) {
      os << "i = " << i_[i] << "\t";
      for (unsigned j = 0; j < traza_[i].get_sz(); j++) {
        if ((int)j < i_[i] || i == traza_.size() - 1) {
          os << GREEN << traza_[i][j] << " " << RESET;
        } else if ((int)j == i_[i]) {
          os << RED << traza_[i][j] << " " << RESET;
        } else {
          os << traza_[i][j] << " ";
        }
      }
      if (i != traza_.size() - 1) os << "\tj = " << j_[i] << "\n";
    }
    os << "\n";
    return os;
  }
};



struct PivoteInfo {
  int pivote;
  std::vector<int> i, f;
  int ini, fin;
  std::vector<Vector<int>> sec;
};


class TrazaQuickSort : public Traza {
 private:
  std::vector<PivoteInfo> pivote_info_;
 public:
  TrazaQuickSort(unsigned size_Vector) : Traza(size_Vector) {}
  void set_pivote_info(const Vector<int> sec, int pivote, int i, int f, int ini, int fin) {
    bool pivote_existe = false;
    for (unsigned k = 0; k < pivote_info_.size(); k++) {
      if (pivote_info_[k].pivote == pivote) {
        modifica_pivote(sec, i, f, k);
        pivote_existe = true;
      } 
    }
    if (!pivote_existe)
      pivote_info_.push_back(introduce_pivote(sec,pivote,i,f,ini,fin));
  }

  PivoteInfo introduce_pivote(const Vector<int> sec, int pivote, int i, int f, int ini, int fin) {
    PivoteInfo aux;
    aux.sec.push_back(sec);
    aux.pivote = pivote;
    aux.i.push_back(i);
    aux.f.push_back(f);
    aux.ini = ini;
    aux.fin = fin;
    return aux;
  }

  void modifica_pivote(const Vector<int> sec, int i, int f, int indice) {
    pivote_info_[indice].i.push_back(i);
    pivote_info_[indice].f.push_back(f);
    pivote_info_[indice].sec.push_back(sec);
  }


  std::ostream& mostrar(std::ostream& os) const {
    int pivote = - 1; 
    for (unsigned i = 0; i < pivote_info_.size(); i++) {
      if (pivote_info_[i].pivote != pivote) {
        for (unsigned j = 0; j < traza_[i].get_sz(); j++) 
          os << UNDERLINE << pivote_info_[i].sec[0][j] << " ";
        os << RESET << "\t Pivote: " << pivote_info_[i].pivote << "\n";
      }
      pivote = pivote_info_[i].pivote;
    }
    return os;
  }

};