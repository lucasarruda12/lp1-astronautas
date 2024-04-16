#ifndef REGISTRO_H 
#define REGISTRO_H

#include "voo.h"

class registro
{
  public:
    static voo* voos[10];
    static astronauta* astronautas[10];

    static void adicionar_voo(voo* novo_voo);
    static void adicionar_astronauta(astronauta* novo_atronauta);
};

#endif
