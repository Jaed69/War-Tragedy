#pragma once
#include "Entidad.h"
class Avion :public Entidad {
private:
public:
	Avion(int x, int y) :Entidad(x,y,40, 40, 1) {
		indX = indY = 0;
		direccion = Abajo;
		aumento = 2;
		vel = 10;
	}
	~Avion() {}
	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {

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
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, bm);
	}
};

/*
Random r;
		int a = r.Next(1, 9);
		int b = r.Next(1, 3);
		int x1 = r.Next(1, 1000);
		int x2 = r.Next(1, 400);
		int x3 = r.Next(400, 900);
		int y1 = r.Next(1, 560);
		int y2 = r.Next(1, 300);
		int y3 = r.Next(300, 560);
		switch (a)
		{
		case 1: y = 0; x = x1; direccion = Abajo; break;
		case 2: y = 560; x = x1; direccion = Arriba; break;
		case 3: x = 0; y = y1; direccion = Derecha; break;
		case 4: x = 990; y = y1; direccion = Izquierda; break;
		case 5:
			if (b == 1) {
				y = 560; x = x2;
			}
			else {
				x = 0; y = y3;
			}
			direccion = ArrDer;
			break;
		case 6:
			if (b == 1) {
				y = 560; x =x3;
			}
			else {
				x = 900; y = y3;
			}
			direccion = ArrIzq;
			break;
		case 7:
			if (b == 1) {
				y = 0; x = x2;
			}
			else {
				x = 0; y = y2;
			}
			direccion = AbDer;
		case 8:
			if (b == 1) {
				y = 0; x =x3;
			}
			else {
				x = 0; y = y2;
			}
			direccion = AbIzq;
		}

*/