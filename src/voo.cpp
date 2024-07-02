#include "voo.hpp"
using std::endl;

int voo::codigos = 0;

ostream& operator<< (ostream& o, voo& a){
  o << "Bem-vindo(a) ao voo: " << a.codigo << endl;
  o << "Status: " << a.status << endl;
  o << "Passageiros: " << endl;
  for (const string& cpf: a.passageiros){
    o << cpf << endl;
  }
  return o;
}

voo::voo(){
  this->codigo = voo::codigos;
  this->status = 'P';
  voo::codigos += 1;
}

void voo::adicionar_passageiro(astronauta& a){
  if (this->status != 'P'){
    cout << "Não é possível adicionar passageiros a um voo em curso" << endl;
    return;
  }

  this->passageiros.insert(a.ler_cpf());
}

void voo::remover_passageiro(astronauta& a){
  if (this->status != 'P'){
    cout << "não é possível remover passageiros de um voo em curso" << endl;
    return;
  }

  this->passageiros.erase(a.ler_cpf());
}

void voo::lancar(){
  if (this->passageiros.size() < 1){
    cout << "É necessário ao menos um piloto para lançar um voo" << endl;
    return;
  }

  for (const string& cpf: this->passageiros){
    optional<astronauta*> maybe_astronauta = registro::buscar(cpf);

    if (not maybe_astronauta.has_value() or not maybe_astronauta.value()->esta_disponivel()){
      cout << "É necessário que todos os passageiros estejam disponíveis" << endl;
    }
  }

  for (const string& cpf: this->passageiros){
    optional<astronauta*> maybe_astronauta = registro::buscar(cpf);
    
    if (not maybe_astronauta.has_value()){
      continue;
    } else {
      maybe_astronauta.value()->deixar_indisponivel();
      maybe_astronauta.value()->adicionar_voo(this->codigo); 
    }
  }

  this->status = 'C';
}

void voo::explodir(){
  if (this->status != 'C'){
    cout << "Não é possível explodir um voo que não esteja em curso" << endl;
    return;
  }

  for (const string&cpf: this-> passageiros) {
    optional<astronauta*> maybe_astronauta = registro::buscar(cpf);

    if (not maybe_astronauta.has_value()){
      continue;
    } else {
      maybe_astronauta.value()->matar();
    }
  }
}

void voo::finalizar(){
  if (this->status != 'C'){
    cout << "Não é possível finalizar um voo que não esteja em curso" << endl;
    return;
  }

  for (const string& cpf: this->passageiros){
    optional<astronauta*> maybe_astronauta = registro::buscar(cpf);

    if (not maybe_astronauta.has_value()){
      continue;
    } else {
      maybe_astronauta.value()->deixar_disponivel();
    }
  }
}
