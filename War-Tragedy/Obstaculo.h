#pragma once
#include "Entidad.h"

class Obstaculo :public Entidad {
private:


public:
	Obstaculo() {}
	Obstaculo(int x, int y) :Entidad(x, y, 64, 64, 20) {//poner ancho alto bien y determinar vida
	}
	~Obstaculo() {}

	void animar(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ Obstaculo = gcnew Bitmap("assets/Obstaculo/Fuego.png");
		indX = 25;
		Rx = 20;
		Ry = 30;
		Rancho = 25;
		Ralto = 30;
		
		dibujar(bg, Obstaculo);
		delete Obstaculo;
	}


};