#pragma once
#include "Entidad.h"
#include "Bala.h"
class Helicoptero :public Entidad {
private:
	vector<Bala*> vBala;

public:
	Helicoptero() {}
	Helicoptero(int x) :Entidad(x,550,40,40,10) {//poner ancho alto bien y determinar vida
		if (x + ancho < 180|| x>980) {
			direccion = Arriba;
		}
		else {
			direccion = Derecha;
		}
		ultDireccion = Ninguna;
		dx = 0;
		dy = 0; aumento = 2; vel = 10;

		Rx = Ry = 0;
		Rancho = Ralto = 20;
	}
	~Helicoptero() {}

	
	void mover(BufferedGraphics^ bg, Rectangle cont) {	
		Bitmap^ heli = gcnew Bitmap("assets/Enemigo/heli.png");

		switch (direccion)
		{
		case Ninguna:
			indX = indY=0;
			break;
		case Abajo:

			dx = 0; dy = 1;
			indY = 2;
			for (int i = 0; i < 3; i++) {
				indX = i;
			}
			
			break;
		case Arriba:
			
			dx = 0; dy = -1;
			indY = 0;
			for (int i = 0; i < 3; i++) {
				indX = i;
			}
			
			break;
		case Izquierda:
			
			dx = -1; dy = 0;
			indY = 3;
			for (int i = 0; i < 3; i++) {
				indX = i;
			}

			break;
		case Derecha:
			
			dx = 1; dy = 0;
			indY = 1;
			for (int i = 0; i < 3; i++) {
				indX = i;
			}

			break;
		default:
			break;
		}

		x += dx * vel;
		y += dy * vel;
				
		dibujar(bg,heli);
		if (!Colision(cont)) activo = false;
	}

	void disparar(int fx, int fy) {
		Bala* oBala = new Bala(x, y, fx, fy);
		oBala->setRnRl(10, 10);
		vBala.push_back(oBala);
	}

	void moverB(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->Container(rec)) vBala.at(i)->mover(bg);
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

