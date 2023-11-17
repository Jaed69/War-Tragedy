#pragma once
#include "Entidad.h"
#include "Bala.h"

class Power :public Entidad {
private:
	vector<Bala*> vBala;
	int ammo;
public:
	Power(int x, int y) :Entidad(x, y, 32, 32, 10) {
		direccion = AbDer;
		ultDireccion = Ninguna;
		dx = dy = indX = indY = 0; vel = 5;
		Rx = 12;
		Ry = 10;
		Rancho = 11;
		Ralto = 11;
		aumento = 1;
		ammo = 50;

	}
	~Power() {}

	void mover(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ power = gcnew Bitmap("assets/Aliado/Power.png");

		
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, power);
		delete power;
	}

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
		ammo--;
	}

	void moverB(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++)
		{
			if (vBala.at(i)->getActivo()) vBala.at(i)->mover(bg);
			else vBala.erase(vBala.begin() + i);
		}
	}
};