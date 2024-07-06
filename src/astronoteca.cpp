#include "astronoteca.hpp"

#include <iostream>
using std::endl;
using std::cout;

map<string, astronauta*> astronoteca::astronautas;

void astronoteca::adicionar(astronauta& a){
  if (astronoteca::astronautas.find(a.ler_cpf()) != astronoteca::astronautas.end()){
    cout << "Já existe astronauta registrado com esse CPF!" << endl;
    return;
  }

  astronoteca::astronautas.insert({a.ler_cpf(), &a});
}

void astronoteca::listar_mortos(){
  map<string, astronauta*>::iterator it;

  cout << "Em memória de: " << endl;

  for (const auto& [cpf, astronauta]: astronoteca::astronautas){
    if (!astronauta->esta_vivo()){
      cout << *astronauta << endl;
    }
  }
}

optional<astronauta*> astronoteca::buscar(const string& cpf){
  auto search = astronoteca::astronautas.find(cpf);

  if (search == astronoteca::astronautas.end()){
    return nullopt; 
  } 
  else{
    return search->second;
  }
}
