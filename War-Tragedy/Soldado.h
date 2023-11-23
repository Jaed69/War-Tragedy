#pragma once
#include "Entidad.h"

class Soldado :public Entidad {
private:
	vector<Bala*> vBala;
	bool estatico;
public:
	Soldado(int x, int y) :Entidad(x, y, 32, 48, 10) {//poner ancho alto bien y determinar vida
		estatico = false;
		if (x <= 256 && y + alto <= 144)direccion = AbDer;
		else if (x >= 768 && y + alto <= 144)direccion = AbIzq;
		else if (x <= 256 && y >= 432)direccion = ArrDer;
		else if (x >= 768 && y >= 432)direccion = ArrIzq;
		else if (x > 256 && x + ancho < 768 && y + alto < 144)direccion = Abajo;
		else if (x + ancho < 256 && y>144 && y + alto < 432)direccion = Derecha;
		else if (x > 768 && y > 144 && y + alto < 432)direccion = Izquierda;
		else if (x > 256 && x + ancho < 768 && y > 432)direccion = Arriba;
		Rx = 10; Ry = 9;
		Rancho = 10;
		Ralto = 28;
		aumento = 1;
		vel = 6;
	}
	~Soldado() {}

	bool intersectAreajugador() {
		Rectangle margen = Rectangle(256, 144, 768, 432);
		return Fhitbox.IntersectsWith(margen);
	}

	bool getEstatico() { return estatico; }

	void apuntarJugador(int jx, int jy) {
		if (x == jx && jy < y) ultDireccion = Arriba;
		if (x == jx && jy > y) ultDireccion = Abajo;
		if (x < jx && jy == y) ultDireccion = Derecha;
		if (x > jx && jy == y) ultDireccion = Izquierda;
		if (x > jx && jy < y) ultDireccion = ArrIzq; 
		if (x < jx && jy < y) ultDireccion = ArrDer;
		if (x > jx && jy > y) ultDireccion = AbIzq;
		if (x < jx && jy > y) ultDireccion = AbDer;
		direccion = Ninguna;
	}

	void mover(BufferedGraphics^ bg, Rectangle cont) {
		Bitmap^ bm = gcnew Bitmap("assets/Enemigo/soldado2.png");

		switch (direccion)
		{
		case Ninguna:
			switch (ultDireccion)
			{
			case Abajo: indX = 4; indY = 2; break;
			case Arriba: indX = 4; indY = 0; break;
			case Izquierda:	indX = 1; indY = 1; break;
			case Derecha: indX = 7; indY = 1; break;
			case ArrDer: indX = 7; indY = 0; break;
			case ArrIzq: indX = 1; indY = 0; break;
			case AbDer:	indX = 7; indY = 2; break;
			case AbIzq:	indX = 1; indY = 2; break;
			}
			dx = 0; dy = 0;
			break;
		case Abajo:
			indY = 2;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;
			dx = 0; dy = 1; ultDireccion = Abajo;
			break;
		case Arriba:
			indY = 0;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;
			dx = 0; dy = -1; ultDireccion = Arriba;
			break;
		case Izquierda:
			indY = 1;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;
			dx = -1; dy = 0; ultDireccion = Izquierda;
			break;
		case Derecha:
			indY = 1;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;
			dx = 1; dy = 0; ultDireccion = Derecha;
			break;
		case ArrDer:
			indY = 0;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;
			dx = 1; dy = -1; ultDireccion = ArrDer;
			break;
		case ArrIzq:
			indY = 0;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;
			dx = -1; dy = -1; ultDireccion = ArrIzq;
			break;
		case AbDer:
			indY = 2;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;
			dx = 1; dy = 1; ultDireccion = AbDer;
			break;
		case AbIzq:
			indY = 2;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;
			dx = -1; dy = 1; ultDireccion = AbIzq;
			break;
		default:
			break;
		}

		if (Container(cont) && !intersectAreajugador()) {
			x += dx * vel;
			y += dy * vel;
		}
		else {
			direccion = Ninguna;
			estatico = true;
		}
		dibujar(bg, bm);
		delete bm;
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
			if (vBala.at(i)->colBal(objetivo)) return true;
		}
		return false;
	}
};
