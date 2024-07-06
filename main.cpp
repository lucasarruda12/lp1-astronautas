#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "astronauta.hpp"
#include "astronoteca.hpp"
#include "voo.hpp"
#include "vooteca.hpp"

class interface {
  public:
    static void cadastrar_astronauta(){
      string nome, cpf;
      int idade;
      cout << "Nome: ";
      cin >> nome;
      cout << "cpf: ";
      cin >> cpf;
      cout << "idade: ";
      cin >> idade;

      astronauta* novo = new astronauta(cpf, nome, idade);
      astronoteca::adicionar(*novo);

      return;
    }
    
    static void cadastrar_voo(){
      voo* novo = new voo;
      vooteca::adicionar(*novo);

      cout << "Novo voo adicionado com sucesso." << endl;
      cout << "O código do voo é " << novo->ler_codigo() << endl;
    }

    static void adicionar_astronauta_a_voo(){
      string cpf;
      int codigo;
      cout << "cpf: ";
      cin >> cpf;

      optional<astronauta *> maybe_astronauta = astronoteca::buscar(cpf);
      if (not maybe_astronauta.has_value()){
        cout << "Astronauta não encontrado." << endl;
        return;
      }

      cout << "Código de voo: ";
      cin >> codigo;

      optional<voo *> maybe_voo = vooteca::buscar(codigo);
      if (not maybe_voo.has_value()){
        cout << "Voo não encotrado." << endl;
        return;
      }

      maybe_voo.value()->adicionar_passageiro(*maybe_astronauta.value());
    }

    static void remover_astronauta_de_voo(){
      string cpf;
      int codigo;
      cout << "cpf: ";
      cin >> cpf;

      optional<astronauta *> maybe_astronauta = astronoteca::buscar(cpf);
      if (not maybe_astronauta.has_value()){
        cout << "Astronauta não encontrado." << endl;
        return;
      }

      cout << "Código de voo: ";
      cin >> codigo;

      optional<voo *> maybe_voo = vooteca::buscar(codigo);
      if (not maybe_voo.has_value()){
        cout << "Voo não encotrado." << endl;
        return;
      }

      maybe_voo.value()->remover_passageiro(*maybe_astronauta.value());
    }

    static void lancar_voo(){
      int codigo;
      cout << "Código de voo: ";
      cin >> codigo;
      
      optional<voo*> maybe_voo = vooteca::buscar(codigo);
      if (not maybe_voo.has_value()){
        cout << "Voo não encontrado." << endl;
        return;
      }

      maybe_voo.value()->lancar();
    }

    static void finalizar_voo(){
      int codigo;
      cout << "Código de voo: ";
      cin >> codigo;
      
      optional<voo*> maybe_voo = vooteca::buscar(codigo);
      if (not maybe_voo.has_value()){
        cout << "Voo não encontrado." << endl;
        return;
      }

      maybe_voo.value()->finalizar();
    }

    static void explodir_voo(){
      int codigo;
      cout << "Código de voo: ";
      cin >> codigo;
      
      optional<voo*> maybe_voo = vooteca::buscar(codigo);
      if (not maybe_voo.has_value()){
        cout << "Voo não encontrado." << endl;
        return;
      }

      maybe_voo.value()->explodir();
    }
};

int main(void){
  int x = 5;

  while(x < 10 & x > 0){
    cout << "==== Bem Vindo(a)! ====" << endl;
    cout << "Escolha uma opção para continuar:" << endl;
    cout << "1 - Cadastrar um Astronauta" << endl;
    cout << "2 - Cadastrar um Voo" << endl;
    cout << "3 - Adicionar passageiro a um Voo" << endl;
    cout << "4 - Remover passageiro de um Voo" << endl;
    cout << "5 - Lançar um Voo" << endl;
    cout << "6 - Explodir um Voo" << endl;
    cout << "7 - Finalizar um Voo" << endl;
    cout << "8 - Listar todos os Voos" << endl;
    cout << "9 - Listar todos os astronautas mortos" << endl;
    cout << "  - Qualquer outro dígito para sair" << endl;

    cin >> x;

    switch (x) {
      case 1:
        interface::cadastrar_astronauta();
        break;
      
      case 2:
        interface::cadastrar_voo();
        break;

      case 3:
        interface::adicionar_astronauta_a_voo();
        break;

      case 4:
        interface::remover_astronauta_de_voo();
        break;

      case 5:
        interface::lancar_voo();
        break;

      case 6:
        interface::explodir_voo();
        break;

      case 7:
        interface::finalizar_voo();
        break;

      case 8:
        vooteca::listar();
        break;

      case 9:
        astronoteca::listar_mortos();
        break;
    }
  }

 return 0; 
}
