#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Este" << endl; break;
		case 2: cout << "Sur " << endl; break;
		case 3: cout << "Oeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;

	//Codigo nuuevo
	switch (ultimaAccion){
		case actFORWARD:
			switch (brujula){
				case 0: // Norte
					fil--; break;
				case 1: // Este
					col++; break;
				case 2: // Sur
					fil++; break;
				case 3: // Oeste
					col--; break;
			}
			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			girar_derecha=(rand()%2 ==0);
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha=(rand()%2 ==0);
			break;
	}
	//Regla que captura los valores de fila y columna en estas casillas
	if (sensores.terreno[0]=='G' && !bien_situado){
		fil = sensores.posF;
		col= sensores.posC;
		bien_situado = true;
	}

	if (bien_situado){
		mapaResultado[fil][col]=sensores.terreno[0];
	}
	// determinamos el siguiente paso: 

	if ((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G') and (sensores.superficie[2]=='_')){
		accion = actFORWARD;
	}
	else if (!girar_derecha){
		accion = actTURN_L;
	}
	else{
		accion = actTURN_R;	
	}

	// Determinar el efecto de la ultima accion enviada
	ultimaAccion=accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
