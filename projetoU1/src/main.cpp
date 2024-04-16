#include <iostream>
#include "astronauta.h"
#include "voo.h"
#include "registro.h"
#include "interface.h"

int main(void)
{
  interface::menu();

  astronauta lucas("125.676.914-21", "Lucas", 20);
  astronauta gabriel("123.456.789.10", "Gabriel", 20);

  voo primeiro_voo(1);
  primeiro_voo.adicionar_passageiro(&lucas);

  for(int i = 0; i < 10; i++)
  { 
    if(registro::astronautas[i] != NULL)
    {
    cout << *(registro::astronautas[i]) << endl;
    }
  }

  cout << primeiro_voo << endl;

  return 0;
}
