#include <iostream>
#include <string>

#include "astronauta.h"
#include "voo.h"

using namespace std;

voo::voo(int codigo) 
{
  this->codigo = codigo;
  this->status_atual = planejamento;

  for (int i = 0; i < 10; i++)
  {
    this->passageiros[i] = NULL;
  }
}

int voo::adicionar_passageiro(astronauta* novo_passageiro)
{
  if(this->status_atual != planejamento) return 1;
  if(novo_passageiro->esta_disponivel() == false) return 2;

  for(int i = 0; i < 10; i++)
  {
    if (this->passageiros[i] == NULL)
    {
      this->passageiros[i] = novo_passageiro;
      return 0;
    }
  }

  return 3;
}

int voo::remover_passageiro(string cpf_do_novo_passageiro)
{
  if(this->status_atual != planejamento) return 1;

  for(int i = 0; i < 10; i++)
  {
    if(this->passageiros[i] == NULL) continue;
    if(this->passageiros[i]->get_cpf() == cpf_do_novo_passageiro)
    {
      this->passageiros[i] = NULL;
      return 0;
    }
  }
  return 3;
}

ostream& operator<<(ostream &o, voo const voo)
{
  o << "voo número: "
    << voo.codigo
    << ", status: "
    << voo.status_atual
    << " - passageiros: {";

  for (int i = 0; i < 10; i++)
  {
    if(voo.passageiros[i] != NULL){
      o << *(voo.passageiros[i]);
    }
  }

  o << "}";

  return o;
}
