#pragma once
#include "Entidad.h"
#include "Bala.h"
class Mono :public Entidad {
private:
	vector<Bala*> vBala;
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

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
	}

	void moverB(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++)
		{
			if (vBala.at(i)->getActivo()) vBala.at(i)->mover(bg, bm, rec);
			else vBala.erase(vBala.begin() + i);
		}
	}
};