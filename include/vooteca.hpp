#ifndef VOOTECA_H
#define VOOTECA_H

#include <map>
using std::map;

#include <optional>
using std::optional;
using std::nullopt;

#include "voo.hpp"

class vooteca{
  private:
    static map<int, voo*> voos;

  public:
    static void adicionar(voo& v);
    static void listar();
    static optional<voo*> buscar(const int& codigo);
};

#endif
