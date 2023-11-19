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

	void mover(Entidad* enem, BufferedGraphics^ bg) {
		Bitmap^ bm = gcnew Bitmap("assets/Enemigo/Avion/image.png");
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
		if (x > enem->getx()&&y>enem->gety()) {
			direccion = ArrIzq;
		}
		if (x < enem->getx()&&y< enem->gety()) {
			direccion = AbDer;
		}		
		if (x > enem->getx() && y < enem->gety()) {
			direccion = AbIzq;
		}
		if (x < enem->getx() && y > enem->gety()) {
			direccion = ArrDer;
		}
				
		if (y > enem->gety()- (enem->getalto() / 2) && y < enem->gety()+(enem->getalto()/2)) {
			if (x > enem->getx()) {
				direccion = Izquierda;
			}
			else {
				direccion = Derecha;
			}
		}
		if (x > enem->getx()- (enem->getancho() / 2) &&x< enem->getx()+(enem->getancho()/2)) {
			if (y > enem->gety()) {
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