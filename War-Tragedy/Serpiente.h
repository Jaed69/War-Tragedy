#pragma once
#include "Entidad.h"
#include <math.h>

class Serpiente :public Entidad {
private:
	vector<Bala*> vBala;

	float posx, posy;
	int fx, fy;

	float difx, dify;
	float mayor;

public:
	Serpiente() {}
	Serpiente(int x, int y, int fx, int fy) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		direccion = Ninguna;
		posx = x;
		posy = y;
		this->fx = fx;
		this->fy = fy;

		mayor = 0, 0;
		difx = dify = 0, 0;

		difx = fx - x;
		dify = fy - y;

		mayor = fmaxf(fabsf(difx), fabsf(dify));

		dx = difx / mayor;
		dy = dify / mayor;
	}
	~Serpiente() {}


	void mover(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ Serpiente = gcnew Bitmap("assets/Serpiente/Serpiente.png");

		vel = 15;
		posx += dx * vel;
		posy += dy * vel;

		x = roundf(posx);
		y = roundf(posy);

		dibujar(bg, Serpiente);
	}

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
	}

	void moverB(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->Container(rec)) vBala.at(i)->mover(bg);
			else vBala.erase(vBala.begin() + i);
		}
	}

	bool colBala(Rectangle objetivo) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->Colision(objetivo)) return true;
			else return false;
		}
	}

};