#pragma once
#include "Entidad.h"
class Mono :public Entidad {
private:
public:
	Mono(int x, int y) :Entidad(x, y, 40, 40, 10) {
		ultDireccion = Ninguna;
		dx = dy = indX=indY= 0; vel = 5;
		aumento = 1;
	}
	~Mono(){}

	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		switch (direccion)
		{
		case Ninguna:
			indX = 0;
			indY = 0;
			break;
		case Abajo:
			break;
		case Arriba:
			break;
		case Izquierda:
			break;
		case Derecha:
			break;
		case ArrDer:
			break;
		case ArrIzq:
			break;
		case AbDer:
			break;
		case AbIzq:
			break;
		default:
			break;
		}
	}
};