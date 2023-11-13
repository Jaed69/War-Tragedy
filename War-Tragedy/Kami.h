#pragma once
#include "Entidad.h"
#include "Jugador.h"

class Kami :public Entidad {
private:

public:
	Kami(int _x, int _y):Entidad(_x, _y, 40, 40, 1) {
		indX = indY = 0;
		direccion = Abajo;
		aumento = 2;
		vel = 10;
	}
	~Kami() {}

	void mover(Jugador* ju, BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		switch (direccion)
		{
		case Ninguna:
			indX = 0; indY = 0;
			break;
		case Abajo:
			indX = 0; indY = 1;
			dx = 0;
			dy = 1;
			break;
		case Arriba:
			indX = 0; indY = 0;
			dx = 0;
			dy = -1;
			break;
		case Izquierda:
			indX = 1; indY = 1;
			dx = -1;
			dy = 0;
			break;
		case Derecha:
			indX = 1; indY = 0;
			dx = 1;
			dy = 0;
			break;
		case ArrDer:
			indX = 1; indY = 0;
			dx = 1;
			dy = -1;
			break;
		case ArrIzq:
			indX = 1; indY = 1;
			dx = -1;
			dy = -1;
			break;
		case AbDer:
			indX = 1; indY = 0;
			dx = 1;
			dy = 1;
			break;
		case AbIzq:
			indX = 1; indY = 1;
			dx = -1;
			dy = 1;
			break;
		}
		if (x > ju->getx()&&y>ju->gety()) {
			direccion = AbDer;			
		}
		else {
			direccion = ArrIzq;
		}
		if (x > ju->getx() && y < ju->gety()) {
			direccion = ArrDer;
		}
		else {
			direccion = AbIzq;
		}
		if (y == ju->gety()) {
			if (x > ju->getx()) {
				direccion = Izquierda;
			}
			else {
				direccion = Derecha;
			}
		}
		if (x == ju->getx()) {
			if (y > ju->gety()) {
				direccion = Arriba;
			}
			else {
				direccion = Abajo;
			}
		}	
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, bm);
	}

};