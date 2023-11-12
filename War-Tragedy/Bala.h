#pragma once
#include "Entidad.h"
#include <math.h>

class Bala :public Entidad {
private:
	float posx, posy;
	int fx, fy;

	float difx, dify;
	float menor;

public:
	Bala() {}
	Bala(int x,int y,int fx,int fy) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		direccion = Ninguna;
		posx = x;
		posy = y;
		this->fx = fx;
		this->fy = fy;
		
		menor = 0, 0;
		difx = dify = 0, 0;

		difx = fx - x;
		dify = fy - y;

		menor = fabsf(fminf(difx, dify));

		dx = difx / menor;
		dy = dify / menor;
	}
	~Bala() {}


	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		


		posx += dx;
		posy += dy;

		
		x = roundf(posx);
		y = roundf(posy);

		dibujar(bg, bm);
	}







};