#include <astronauta.h>
#include <voo.h>
#include <registro.h>

astronauta* registro::astronautas[10] = { NULL };

void registro::adicionar_astronauta(astronauta* novo_astronauta)
{
  for(int i = 0; i < 10; i++)
  {
    if(registro::astronautas[i] == NULL)
    {
      registro::astronautas[i] = novo_astronauta;
      break;
    }
  }
}
