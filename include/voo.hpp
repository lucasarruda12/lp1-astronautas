#ifndef VOO_H
#define VOO_H

#include "astronauta.hpp"
#include "registro.hpp"

#include <unordered_set>
using std::unordered_set;

#include <string>
using std::string;

#include <ostream>
using std::ostream;

#include <optional>
using std::nullopt;
using std::optional;

#include <iostream>
using std::cout;
using std::endl;

class voo {
  private:
    static int codigos;
    int codigo;
    char status;
    unordered_set<string> passageiros; 

  public:
    voo();
    void lancar();
    void explodir();
    void finalizar();
    void adicionar_passageiro(astronauta& a);
    void remover_passageiro(astronauta& a);

    friend ostream& operator<< (ostream& o, voo& a);
};

#endif
