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

	void mover(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ mono = gcnew Bitmap("assets/Aliado/mono.png");

		switch (direccion)
		{
		case Ninguna:
			indX = 0; indY = 0;
			dx = 0; dy = 0;

			ultDireccion = Ninguna;
			break;
		case Abajo:
			indX = 0; indY = 0;
			dx = 0; dy = 1;

			ultDireccion = Abajo;
			break;
		case Arriba:
			indX = 0; indY = 0;
			dx = 0; dy = -1;

			ultDireccion = Arriba;
			break;
		case Izquierda:
			indX = 0; indY = 0;
			dx = -1; dy = 0; 

			ultDireccion = Izquierda;
			break;
		case Derecha:
			indX = 0; indY = 0;
			dx = 1; dy = 0;

			ultDireccion = Derecha;
			break;
		case ArrDer:
			indX = 0; indY = 0;
			dx = 1; dy = -1;

			ultDireccion = ArrDer;
			break;
		case ArrIzq:
			indX = 0; indY = 0;
			dx = -1; dy = -1;

			ultDireccion = ArrIzq;
			break;
		case AbDer:
			indX = 0; indY = 0;
			dx = 1; dy = 1;

			ultDireccion = AbDer;
			break;
		case AbIzq:
			indX = 0; indY = 0;
			dx = -1; dy = 1;

			ultDireccion = AbIzq;
			break;
		}

		if (Container(rec))
		{
			x += dx * vel;
			y += dy * vel;
		}

		dibujar(bg, mono);
		
	}

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
	}

	void moverB(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->Colision(rec)) vBala.at(i)->mover(bg);
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