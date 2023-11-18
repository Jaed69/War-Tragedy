#pragma once
#include "Entidad.h"

class Soldado :public Entidad {
private:
	vector<Bala*> vBala;

public:
	Soldado(int x, int y) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		//margen = Rectangle(256, 144, 768, 432);
		//borde = Rectangle(0, 0, 1280, 720);

		if (x <= 256 && y + alto <= 144)direccion = AbDer;
		else if (x >= 768 && y + alto <= 144)direccion = AbIzq;
		else if (x  <= 256 && y >= 432)direccion = ArrDer;
		else if (x >= 768 && y >= 432)direccion = ArrIzq;
		else if (x > 256 && x + ancho < 768 && y + alto < 144)direccion = Abajo;
		else if (x + ancho < 256 && y>144 && y + alto < 432)direccion = Derecha;
		else if (x > 768 && y > 144 && y + alto < 432)direccion = Izquierda;
		else if (x > 256 && x + ancho < 768 && y > 432)direccion = Arriba;
		vel = 6;
	}
	~Soldado() {}

	bool intersectAreajugador() {
		Rectangle margen = Rectangle(256, 144, 768, 432);
		return hitbox.IntersectsWith(margen);
	}

	void mover(BufferedGraphics^ bg, Rectangle cont) {
		Bitmap^ bm = gcnew Bitmap("assets/Enemigo/soldado.png");
		
		switch (direccion)
		{
		case Ninguna:
			indX = indY = 0; dx = 0; dy = 0; ultDireccion = Ninguna;
			break;
		case Abajo:
			dx = 0; dy = 1; ultDireccion = Abajo;
			break;
		case Arriba:
			dx = 0; dy = -1; ultDireccion = Arriba;
			break;
		case Izquierda:
			dx = -1; dy = 0; ultDireccion = Izquierda;
			break;
		case Derecha:
			dx = 1; dy = 0; ultDireccion = Derecha;
			break;
		case ArrDer:
			dx = 1; dy = -1; ultDireccion = ArrDer;
			break;
		case ArrIzq:
			dx = -1; dy = -1; ultDireccion = ArrIzq;
			break;
		case AbDer:
			dx = 1; dy = 1; ultDireccion = AbDer;
			break;
		case AbIzq:
			dx = -1; dy = 1; ultDireccion = AbIzq;
			break;
		default:
			break;
		}

		if (Container(cont)&&!intersectAreajugador()) {
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

/*

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
*/