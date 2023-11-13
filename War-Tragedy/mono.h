#pragma once
#include "Entidad.h"
#include "Bala.h"
class Mono :public Entidad {
private:
	vector<Bala*> vBala;
	int ammo;
public:
	Mono(int x, int y) :Entidad(x, y, 32, 32, 10) {
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
	~Mono() {}

	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		switch (direccion)
		{
		case Ninguna:
			indX = 0; indY = 0;
			dx = 0; dy = 0;
			ultDireccion = Ninguna;
			break;
		case Abajo:
			indX = 0; indY = 0;
			dx = 0; dy = 0; ultDireccion = Abajo;
			break;
		case Arriba:
			indX = 0; indY = 0;
			dx = 0; dy = 0; ultDireccion = Arriba;
			break;
		case Izquierda:
			indX = 0; indY = 0;
			dx = 0; dy = 0; ultDireccion = Izquierda;
			break;
		case Derecha:
			indX = 0; indY = 0;
			dx = 0; dy = 0; ultDireccion = Derecha;
			break;
		case ArrDer:
			indX = 0; indY = 0;
			ultDireccion = ArrDer;
			if (Container(bg, rec, 1, -1)) {
				dx = 1; dy = -1;
			}
			else {
				direccion = ArrIzq;
				dx = 0; dy = 0;
			}

			break;
		case ArrIzq:
			indX = 0; indY = 0;
			ultDireccion = ArrIzq;
			if (Container(bg, rec, -1*vel, -1 * vel)) {
				dx = -1; dy = -1;
			}
			else {
				direccion = AbIzq;
				dx = 0; dy = 0;
			}
			break;
		case AbDer:
			indX = 0; indY = 0;
			ultDireccion = AbDer;
			if (Container(bg, rec, 1 * vel, 1 * vel)) {
				dx = 1; dy = 1;
			}
			else {
				direccion = ArrDer;
				dx = 0; dy = 0;
			}
			break;
		case AbIzq:
			indX = 0; indY = 0;
			ultDireccion = AbIzq;
			if (Container(bg, rec, -1 * vel, 1 * vel)) {
				dx = -1; dy = 1;
			}
			else {
				direccion = AbDer;
				dx = 0; dy = 0;
				
			}
			break;
		}
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, bm);
	}

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
		ammo--;
	}

	void moverB(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++)
		{
			if (vBala.at(i)->getActivo()) vBala.at(i)->mover(bg, bm, rec);
			else vBala.erase(vBala.begin() + i);
		}
	}
};