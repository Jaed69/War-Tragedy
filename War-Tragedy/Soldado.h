#pragma once
#include "Entidad.h"

class Soldado :public Entidad {
private:
	vector<Bala*> vBala;

public:
	Soldado(int x,int y) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		direccion = Derecha;
		dx = 1;
		dy = 0;
	}
	~Soldado() {}

	void mover(BufferedGraphics^ bg, Rectangle cont) {
		Bitmap^ bm = gcnew Bitmap("assets/Obstaculo/Obstaculo.png");

		if (x + dx + ancho > 1050) {
			dx = 0;
			dy = 1;
			direccion = Abajo;
		}
		if (x < 10) {
			dx = 0;
			dy = 1;
			direccion = Abajo;
		}
		if (y + alto + dy > 590) {
			dy *= -1;
			direccion = Arriba;
		}
		if (y < 5) {
			if (x > 500) {
				dx = -1;
				direccion = Izquierda;
			}
			else {
				dx = 1;
				direccion = Derecha;
			}
		}

		if (Container(cont)) {
			x += dx * vel;
			y += dy * vel;
		}

		dibujar(bg, bm);
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