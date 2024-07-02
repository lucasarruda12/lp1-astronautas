#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
using std::string;

#include <ostream>
using std::ostream;
using std::endl;

#include <unordered_set>
using std::unordered_set;

class astronauta {
  private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
    unordered_set<int> voos;

  public:
    astronauta(const string& cpf, const string& nome, const int& idade);

    string ler_cpf();
    bool esta_vivo();
    bool esta_disponivel();
    void matar();
    void deixar_indisponivel();
    void deixar_disponivel();
    void adicionar_voo(int codigo);
    friend ostream& operator<< (ostream& o, const astronauta& a);
};

#endif
