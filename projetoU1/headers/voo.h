#ifndef VOO_H
#define VOO_H

#include <string>
#include <ostream>

using namespace std;

enum status {planejamento, andamento, finalizado, explodido};

class voo
{
  private:
    int codigo;
    astronauta* passageiros[10];
    status status_atual;

  public:
    voo(int codigo);
    int adicionar_passageiro(astronauta* novo_passageiro);
    int remover_passageiro(string cpf);
    int lancar();
    int explodir;
    int finalizar;
    friend ostream& operator<<(ostream &o, voo const voo);
};

#endif
