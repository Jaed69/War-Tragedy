#pragma once
#include "Entidad.h"

class Explosion :public Entidad {
private:


public:
	Explosion() {}
	Explosion(int x, int y) :Entidad(x, y, 48, 48, 0) {//poner ancho alto bien y determinar vida
		indX = 0;
		indY = 0;
		Rx = 0;
		Ry = 0;
		Rancho = 48;
		Ralto = 48;
		aumento = 2;
		activo = true;
		dx = 1;
	}
	~Explosion() {}


	void animar(BufferedGraphics^ bg) {
		Bitmap^ exp = gcnew Bitmap("assets/Obstaculo/Explosion 2 SpriteSheet.png");
		indX+=dx*0.1;
		if (indX >= 18)dx *= -1;
		if (indX < -1)activo = false;
		dibujar(bg, exp);
		delete exp;
	}


};