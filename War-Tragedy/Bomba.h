#pragma once
#include "Entidad.h"

class Bomba :public Entidad {
private:
	bool exploto;
	int Ex, Ey;

public:
	Bomba() {}
	Bomba(int x, int y) :Entidad(x, y, 5, 8, 20) {//poner ancho alto bien y determinar vida
		exploto = false;
		Ex = x - 30;
		Ey = y - 40;
	}
	~Bomba() {}

	void animar(BufferedGraphics^ bg) {
		Bitmap^ bom = gcnew Bitmap("assets/Enemigo/Bomba.png");
		Bitmap^ nap = gcnew Bitmap("assets/Efectos/Napal.png");

		if (!exploto){
			dibujar(bg, bom);
			if (indX >= 0 && indX < 7) indX++;
			else { exploto = true; indX = 0; }

			
		} else {
			x = Ex; y = Ey;
			ancho = 64; alto = 64;
			dibujar(bg, nap);
			indX++;
			if (indX >= 0 && indX < 4) {
				Rx = 27; Ry = 37;
				Rancho = Ralto = 10;
			}
			else if (indX >= 4 && indX < 12) {
				Rx = 24; Ry = 34;
				Rancho = 15; Ralto = 17;
			}
			else if (indX >= 12 && indX < 25) {
				Rx = 17; Ry = 32;
				Rancho = 30; Ralto = 23;
			}
			else if (indX >= 25 && indX < 42) {
				Rx = 27; Ry = 37;
				Rancho = Ralto = 10;
			}
			else if (indX >= 42 && indX < 52) {
				Rx = Ry = 0;
				Rancho = Ralto = 0;
			}
			else{ activo = false; }
			
		}

		delete bom; delete nap;
	}


};