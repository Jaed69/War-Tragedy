#pragma once
#include "Entidad.h"
class Helicoptero :public Entidad {
private:
	

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
		dy = 0; aumento = 2; vel = 15;
	}
	~Helicoptero() {}
	
	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {	
		switch (direccion)
		{
		case Ninguna:
			indX = indY=0;
			break;
		case Abajo:
			if (Container(bg, rec, 0, 10)) {
				dx = 0; dy = 1;
				indY = 2;
				for (int i = 0; i < 3; i++) {
					indX = i;
				}
			}
			else if (x < 200) {
				direccion = Derecha;
				dx = dy = 0;
			}
				
			else if (x > 200) {
				direccion = Izquierda;
				dx = dy = 0;
			}
			
			break;
		case Arriba:
			if (Container(bg, rec, 0, -10)) {
				dx = 0; dy = -1;
				indY = 0;
				for (int i = 0; i < 3; i++) {
					indX = i;
				}
			}
			else if (x < 200) {
				direccion = Derecha;
				dx = dy = 0;
			}

			else if (x > 200) {
				direccion = Izquierda;
				dx = dy = 0;
			}
			
			break;
		case Izquierda:
			if (Container(bg, rec, -10, 0)) {
				dx = -1; dy = 0;
				indY = 3;
				for (int i = 0; i < 3; i++) {
					indX = i;
				}
			}
			else if (y < 200) {
				direccion = Abajo;
				dx = dy = 0;
			}
				
			else if (y > 200) {
				direccion = Arriba;
				dx = dy = 0;
			}

			break;
		case Derecha:
			if (Container(bg, rec, 10, 0)) {
				dx = 1; dy = 0;
				indY = 1;
				for (int i = 0; i < 3; i++) {
					indX = i;
				}

			}
			else if (y < 200) {
				direccion = Abajo;
				dx = dy = 0;
			}

			else if (y > 200) {
				direccion = Arriba;
				dx = dy = 0;
			}

			break;
		}
		
		x += dx;
		y += dy;
		dibujar(bg,bm);
	}

	





};


/*
if (x + dx + ancho > 1050) {
			dx = 0;
			dy = 1;
			direccion = Abajo;
		}
		if (x< 10) {
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