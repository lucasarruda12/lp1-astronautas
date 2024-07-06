#include "astronauta.hpp"

ostream& operator<< (ostream& o, const astronauta& a){
  o << a.nome << "  " << a.cpf << " " << a.idade;
  o << endl << "voos que participou: " << endl;
  
  for (const int& codigo: a.voos){
    o << codigo << " ";
  }

  return o;
}

astronauta::astronauta(const string& cpf, const string& nome, const int& idade){
  this->nome = nome;
  this->idade = idade;
  this->cpf = cpf;
  this->vivo = true;
  this->disponivel = true;
}

string astronauta::ler_cpf(){
  return this->cpf;
}

bool astronauta::esta_vivo(){
  return this->vivo;
}

bool astronauta::esta_disponivel(){
  return this->disponivel;
}

void astronauta::matar(){
  this->vivo = false;
}

void astronauta::deixar_indisponivel(){
  this->disponivel = false;
}

void astronauta::deixar_disponivel(){
  this->disponivel = true;
}

void astronauta::adicionar_voo(int codigo){
  this->voos.insert(codigo);
}
