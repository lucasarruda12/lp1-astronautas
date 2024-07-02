#ifndef REGISTRO_H
#define REGISTRO_H

#include <map>
using std::map;

#include <optional>
using std::optional;
using std::nullopt;

#include "astronauta.hpp"
#include "voo.hpp"

class registro {
  private:
    static map<string, astronauta*> astronautas;

  public:
    static void adicionar(astronauta& a);
    static void listar_mortos();
    static optional<astronauta*> buscar(const string& cpf);
};

#endif
