#include "registro.hpp"

#include <iostream>
using std::endl;
using std::cout;

map<string, astronauta*> registro::astronautas;

void registro::adicionar(astronauta& a){
  registro::astronautas.insert({a.ler_cpf(), &a});
}

void registro::listar_mortos(){
  map<string, astronauta*>::iterator it;

  cout << "Em memória de: " << endl;

  for (const auto& [cpf, astronauta]: registro::astronautas){
    if (!astronauta->esta_vivo()){
      cout << *astronauta << endl;
    }
  }
}

optional<astronauta*> registro::buscar(const string& cpf){
  auto search = registro::astronautas.find(cpf);

  if (search == registro::astronautas.end()){
    return nullopt; 
  } 
  else{
    return search->second;
  }
}
