#pragma once
#include "Entidad.h"

class Obstaculo :public Entidad {
private:


public:
	Obstaculo() {}
	Obstaculo(int x, int y, int ancho, int alto) :Entidad(x, y, ancho, alto, 20) {//poner ancho alto bien y determinar vida
	}
	~Obstaculo() {}

	void animar(BufferedGraphics^ bg) {
		Bitmap^ Obstaculo = gcnew Bitmap("assets/Obstaculo/Fuego.png");
		indX = 25;
		
		dibujar(bg, Obstaculo);
		delete Obstaculo;
	}


};