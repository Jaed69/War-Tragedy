#pragma once
#include "Entidad.h"
#include "Jugador.h"

class Kami :public Entidad {
private:

public:
	Kami(int _x, int _y):Entidad(_x, _y, 40, 40, 1) {
		indX = indY = 0;
		direccion = Ninguna;
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
			direccion = ArrIzq;
		}
		if (x < ju->getx()&&y<ju->gety()) {
			direccion = AbDer;
		}		
		if (x > ju->getx() && y < ju->gety()) {
			direccion = AbIzq;
		}
		if (x < ju->getx() && y > ju->gety()) {
			direccion = ArrDer;
		}
				
		if (y > ju->gety()- (ju->getalto() / 2) && y < ju->gety()+(ju->getalto()/2)) {
			if (x > ju->getx()) {
				direccion = Izquierda;
			}
			else {
				direccion = Derecha;
			}
		}
		if (x > ju->getx()- (ju->getancho() / 2) &&x<ju->getx()+(ju->getancho()/2)) {
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