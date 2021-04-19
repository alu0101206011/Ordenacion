#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define UNDERLINE "\033[4m"  /* Underline text */
#define BOLD "\033[1m"

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



struct TrazaInfo {
  int pivote;
  std::vector<int> i, f;  // Son posiciones
  int ini, fin;
  std::vector<Vector<int>> sec;
};


class TrazaQuickSort : public Traza {
 private:
  std::vector<TrazaInfo> traza_info_;
 public:
  TrazaQuickSort(unsigned size_Vector) : Traza(size_Vector) {}

  Vector<int> get_Vector_traza(int indice_traza_info, int indice) const {
    return traza_info_[indice_traza_info].sec[indice];
  }

  int get_i(int indice_traza_info, int indice) const {
    return traza_info_[indice_traza_info].i[indice];
  }

  int get_f(int indice_traza_info, int indice) const {
    return traza_info_[indice_traza_info].f[indice];
  }

  bool pos_igual_i(int indice_traza_info, int indice_i, int indice_vec) const {
    return get_Vector_traza(indice_traza_info,indice_i)[get_i(indice_traza_info,indice_i)] 
           == get_Vector_traza(indice_traza_info,indice_i)[indice_vec];
  }

  bool pos_igual_f(int indice_traza_info, int indice_f, int indice_vec) const {
    return get_Vector_traza(indice_traza_info,indice_f)[get_f(indice_traza_info,indice_f)] 
           == get_Vector_traza(indice_traza_info,indice_f)[indice_vec];
  }

  void introduce_traza(const Vector<int> sec, int pivote, int i, int f, int ini, int fin) {
    TrazaInfo aux;
    aux.sec.push_back(sec);
    aux.pivote = pivote;
    aux.i.push_back(i);
    aux.f.push_back(f);
    aux.ini = ini;
    aux.fin = fin;
    traza_info_.push_back(aux);
  }

  void modifica_traza(const Vector<int> sec, int pivote, int i, int f, int ini, int fin) {
    for (unsigned indice = 0; indice < traza_info_.size(); indice++) {
      if (pivote == traza_info_[indice].pivote && ini == traza_info_[indice].ini && fin == traza_info_[indice].fin) {
        traza_info_[indice].i.push_back(i);
        traza_info_[indice].f.push_back(f);
        traza_info_[indice].sec.push_back(sec);
      }
    }
  }

  std::ostream& mostrar(std::ostream& os) const {
    os << "\n\nEmpieza la traza: \n\n";
    for (unsigned i = 0; i < traza_info_.size(); i++) {
      os <<"Pivote: " <<traza_info_[i].pivote << "\tini: " << traza_info_[i].ini << "\tfin: " << traza_info_[i].fin << "\n";
      for (unsigned j = 0; j < traza_info_[i].sec.size(); j++) {
        for (unsigned k = 0; k < get_Vector_traza(i,j).get_sz(); k++) {
          if (pos_igual_i(i,j,k) || pos_igual_f(i,j,k)) {
            os << BOLD << RED << UNDERLINE  << " " << get_Vector_traza(i,j)[k] << RESET << UNDERLINE << " |";
          } else if ((int)k >= traza_info_[i].ini && (int)k <= traza_info_[i].fin) {
            os << UNDERLINE << " " << get_Vector_traza(i,j)[k] << RESET << UNDERLINE  << " |";
          } else {
            os << RESET << " " << get_Vector_traza(i,j)[k] <<  " |";
          }
        }
        os << RESET << "\n";
      }
    }
    return os;
  }
};


struct BusquedaTraza {
  Vector<int> traza;
  std::vector<int> indices;
};

struct Delta_info {
  int delta;
  std::vector<BusquedaTraza> busqueda_traza;
};

class TrazaShellSort : public Traza {
 private: 
  std::vector<Delta_info> vector_delta;
 public:
  TrazaShellSort(unsigned size_Vector) : Traza(size_Vector) {}

  int encuentra_delta (int delta) {
    for (unsigned i = 0; i < vector_delta.size(); i++)
      if (vector_delta[i].delta == delta)
        return i;
    return -1;
  }

  void introduce_indice_de_traza_delta(int indice_traza, int indice_delta, int indice) {
    bool indice_existe = 0;
    for (int element : vector_delta[indice_delta].busqueda_traza[indice_traza].indices) 
      if (element == indice)
        indice_existe = 1;
    if (!indice_existe)
      vector_delta[indice_delta].busqueda_traza[indice_traza].indices.push_back(indice);
  }

  void introduce_vector_delta(const Vector<int> sec, int delta) {
    Delta_info aux;
    aux.delta = delta;
    BusquedaTraza aux2;
    aux2.traza = sec;
    aux.busqueda_traza.push_back(aux2);
    vector_delta.push_back(aux);
  }


  void RecogerTraza(const Vector<int> sec, int delta, int indice1, int indice2) {
    int indice_delta = encuentra_delta(delta);
    if (indice_delta == -1) {
      introduce_vector_delta(sec, delta);
      introduce_indice_de_traza_delta(vector_delta[vector_delta.size() - 1].busqueda_traza.size() - 1, vector_delta.size() - 1, indice1);
      introduce_indice_de_traza_delta(vector_delta[vector_delta.size() - 1].busqueda_traza.size() - 1, vector_delta.size() - 1, indice2);
      return;
    }
    int indice_traza = -1;
    for (unsigned i = 0; i < vector_delta[indice_delta].busqueda_traza.size(); i++) 
      if (vector_delta[indice_delta].busqueda_traza[i].traza == sec) 
        indice_traza = i;
    if (indice_traza == -1) {
      BusquedaTraza traza;
      traza.traza = sec;
      vector_delta[indice_delta].busqueda_traza.push_back(traza);
      indice_traza = vector_delta[indice_delta].busqueda_traza.size() - 1;
    }
    introduce_indice_de_traza_delta(indice_traza, indice_delta, indice1);
    introduce_indice_de_traza_delta(indice_traza,indice_delta,indice2);
  }

  bool busca_indice(unsigned i, unsigned j, int indice) const {
    for (unsigned k = 0; k < vector_delta[i].busqueda_traza[j].indices.size(); k++) 
      if (vector_delta[i].busqueda_traza[j].indices[k] == indice) 
        return true;
    return false;
  }

  std::ostream& mostrar(std::ostream& os) const {
    for (unsigned i = 0; i < vector_delta.size(); i++) {
      os << "Delta: " << vector_delta[i].delta << "\n";
      for (unsigned j = 0; j < vector_delta[i].busqueda_traza.size(); j++) {
        for (unsigned k = 0; k < vector_delta[i].busqueda_traza[j].traza.get_sz(); k++) {
          if (busca_indice(i,j,k)) {
            os << BOLD << RED << vector_delta[i].busqueda_traza[j].traza[k] << RESET << " ";
          } else {
            os << vector_delta[i].busqueda_traza[j].traza[k] << " ";
          }
        }
        os << "\n";
      }
    }
    return os;
  }
};