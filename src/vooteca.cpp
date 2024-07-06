#include "vooteca.hpp"

map<int, voo*> vooteca::voos;

void vooteca::adicionar(voo& v){
  vooteca::voos.insert({v.ler_codigo(), &v});
};

void vooteca::listar(){
  map<int, voo*>::iterator it;

  cout << "=== Voos em preparo: ===" << endl;

  for (const auto& [codigo, voo]: vooteca::voos){
    if (voo->ler_status() == 'P'){
      cout << *voo << endl;
    }
  }

  cout << "=== Voos em curso: ===" << endl;

  for (const auto& [codigo, voo]: vooteca::voos){
    if (voo->ler_status() == 'C'){
      cout << *voo << endl;
    }
  }

  cout << "=== Voos Finalizados ===" << endl;

  for (const auto& [codigo, voo]: vooteca::voos){
    if (voo->ler_status() == 'F'){
      cout << *voo << endl;
    }
  }

  cout << "=== Voos que falharam ===" << endl;

  for (const auto& [codigo, voo]: vooteca::voos){
    if (voo->ler_status() == 'E'){
      cout << *voo << endl;
    }
  }
}

optional<voo*> vooteca::buscar(const int& codigo){
  auto search = vooteca::voos.find(codigo);

  if (search == vooteca::voos.end()){
    return nullopt; 
  } 
  else{
    return search->second;
  }
}
