#pragma once
#include "Entidad.h"

class Flama :public Entidad {
private:


public:
	Flama() {}
	Flama(int x, int y) :Entidad(x, y, 64, 64, 20) {//poner ancho alto bien y determinar vida
	}
	~Flama() {}

	void animar(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ Flama = gcnew Bitmap("assets/Efectos/Flama.png");
		Rx = 20;
		Ry = 30;
		Rancho = 25;
		Ralto = 30;

		if (indX >= 0 && indX < 120) indX++;
		else activo = false;

		dibujar(bg, Flama);
		delete Flama;
	}


};