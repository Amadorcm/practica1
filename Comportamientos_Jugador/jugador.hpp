#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){fil=99,col=99,brujula=0,ultimaAccion=actIDLE,girar_derecha=false,bien_situado=false;}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
    int fil, col, brujula; 
    Action ultimaAccion;
    bool girar_derecha, bien_situado;
  
  // Declarar aquí las variables de estado

};

#endif
