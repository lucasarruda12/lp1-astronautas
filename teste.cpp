#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <optional>
using std::optional;

#include "astronauta.hpp"
#include "registro.hpp"
#include "voo.hpp"

int main(void){
//    cout << "==== Bem Vindo(a)! ====" << endl;
//    cout << "Escolha uma opção para continuar:" << endl;
//    cout << "1 - Cadastrar um Astronauta" << endl;
//    cout << "2 - Cadastrar um Voo" << endl;
//    cout << "3 - Adicionar passageiro a um Voo" << endl;
//    cout << "4 - Remover passageiro de um Voo" << endl;
//    cout << "5 - Lançar um Voo" << endl;
//    cout << "6 - Explodir um Voo" << endl;
//    cout << "7 - Finalizar um Voo" << endl;
//    cout << "8 - Listar todos os Voos" << endl;
//    cout << "9 - Listar todos os astronautas mortos" << endl;

  voo teste;
  astronauta lucas("125", "lucas", 20);
  registro::adicionar(lucas);

  teste.adicionar_passageiro(lucas);
  teste.lancar();
  teste.finalizar();

  cout << lucas << endl;
  
}
