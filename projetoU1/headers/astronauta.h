#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <ostream>

using namespace std;

class astronauta
{
  private:
    string cpf;
    string nome;
    int idade;
    bool disponivel;

  public:
    astronauta(string cpf, string nome, int idade);
    bool esta_disponivel();
    string get_cpf();
    friend ostream& operator<<(ostream &o, astronauta const astronauta);
};

#endif
