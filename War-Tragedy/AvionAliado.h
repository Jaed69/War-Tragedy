#pragma once
#include "Entidad.h"
#include "bala.h"
class AvionAliado : public Entidad {
private:
	vector<Bala*> vBala;


public:
	AvionAliado(int x, int y) :Entidad(x, y, 40, 40, 1) {
		indX = indY = 0;
		direccion = Abajo;
		aumento = 2;
		vel = 10;
	}
	~AvionAliado() {}
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
	void disparar() {
		Bala* oBala = new Bala(x, y, x +20, y);
		oBala->setRnRl(10, 10);
		Bala* oBala2 = new Bala(x, y, x -20, y);	
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
		vBala.push_back(oBala2);
	}

	void moverB(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++)
		{
			if (vBala.at(i)->getActivo()) vBala.at(i)->mover(bg, bm, rec);
			else vBala.erase(vBala.begin() + i);
		}
	}
};