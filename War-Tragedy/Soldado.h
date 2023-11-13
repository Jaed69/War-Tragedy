#pragma once
#include "Entidad.h"

class Soldado :public Entidad {
private:


public:
	Soldado() {}
	/* ta en comentario porque no me dejaba compilar xdxdxdxdhkbasfvhasfvbhi
	Soldado() :Entidad(0, 0, 32, 48, 20) {//poner ancho alto bien y determinar vida
		direccion = Derecha;
		dx = 1;
		dy = 0;
	}
	~Soldado() {}*/
	


	void Mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
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
		x += dx;
		y += dy;
		dibujar(bg, bm);
	}







};