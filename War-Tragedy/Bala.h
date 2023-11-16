#pragma once
#include "Entidad.h"
#include <math.h>

class Bala :public Entidad {
private:
	float posx, posy;
	int fx, fy;

	float difx, dify;
	float mayor;

public:
	Bala() {}
	Bala(int x,int y,int fx,int fy) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		direccion = Ninguna;
		posx = x;
		posy = y;
		this->fx = fx;
		this->fy = fy;
		
		mayor = 0, 0;
		difx = dify = 0, 0;

		difx = fx - x;
		dify = fy - y;

		mayor = fmaxf(fabsf(difx),fabsf(dify));

		dx = difx / mayor;
		dy = dify / mayor;
	}
	~Bala() {}


	void mover(BufferedGraphics^ bg) {
		Bitmap^ bala = gcnew Bitmap("assets/Bala/bala.png");

		vel = 15;
		posx += dx * vel;
		posy += dy * vel;
		
		x = roundf(posx);
		y = roundf(posy);

		dibujar(bg, bala);
	}







};