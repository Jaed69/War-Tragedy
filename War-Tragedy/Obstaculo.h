#pragma once
#include "Entidad.h"

class Obstaculo :public Entidad {
private:


public:
	Obstaculo() {}
	Obstaculo(int x, int y) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		Rx = Ry = 20;
		Rancho = Ralto = 20;
	}
	~Obstaculo() {}

	void animar(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ Obstaculo = gcnew Bitmap("assets/Obstaculo/Obstaculo.png");


		dibujar(bg, Obstaculo);
	}







};