#include <iostream>
#include <string>

#include "astronauta.h"
#include "registro.h"
#include "voo.h"

using namespace std;

astronauta::astronauta(string cpf, string nome, int idade)
{
  this->cpf = cpf;
  this->nome = nome;
  this->idade = idade;
  this->disponivel = true;

  registro::adicionar_astronauta(this);
}

bool astronauta::esta_disponivel()
{
  return this->disponivel;
}

string astronauta::get_cpf()
{
  return this->cpf;
}

ostream& operator<<(ostream &o, astronauta const astronauta)
{
  o 
    << "("
    << astronauta.cpf
    << ") "
    << astronauta.nome
    << ", "
    << astronauta.idade
    << " anos. "
    << (astronauta.disponivel ? "(disponivel)" : "(indisponivel)")
  ;
  return o;
}

