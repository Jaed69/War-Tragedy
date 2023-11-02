#pragma once
#include"Entidad.h"

class Jugador:public Entidad
{
private:
	int chaleco;
public:
	Jugador(){}
	Jugador(int x,int y):Entidad(x,y,32,48,1){
		indX = 4;
		indY = 2;
	}
	~Jugador(){}
	int getchaleco() { return this->chaleco; }
	void setchaleco(int chaleco) { this->chaleco = chaleco; }

	void mover(BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		switch (direccion)
		{
		case Ninguna:
			indX = 4;
			indY = 2;
			dx = 0; dy = 0;
			switch (ultDireccion)
			{
			case Abajo:
				indX = 4;
				indY = 2;
				break;
			case Arriba:
				indX = 4;
				indY = 0;
				break;
			case Izquierda:
				indX = 1;
				indY = 1;
				break;
			case Derecha:
				indX = 7;
				indY = 1;
				break;
			default:
				break;
			}
			break;
		case Abajo:
			indY = 2;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;
			if (Container(bg, rec, x, y, 0, 10)) {
				dx = 0; dy = 10; ultDireccion = Abajo;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Abajo;
			}
			break;
		case Arriba:
			indY = 0;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;
			if (Container(bg, rec, x, y, 0, -10)) {
				dx = 0; dy = -10; ultDireccion = Arriba;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Arriba;
			}
			break;
		case Izquierda:
			indY = 1;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;
			if (Container(bg, rec, x, y, -10, 0)) {
				dx = -10; dy = 0; ultDireccion = Izquierda;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Izquierda;
			}
			break;
		case Derecha:
			indY = 1;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;
			if (Container(bg, rec, x, y, 10, 0)) {
				dx = 10; dy = 0; ultDireccion = Derecha;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Derecha;
			}
			break;

		}
		dibujar(bg, bm);
	}

	void Dash(BufferedGraphics^ bg, Rectangle rec) {
		switch (ultDireccion) {
		case Arriba:
			if (!Container(bg, rec, x, y, 0, -(alto * 2))) {
				//dead or smth
			}
			else			{
				y -= alto * 2;
			}
			break;
		case Abajo:
			if (!Container(bg, rec, x, y, 0, (alto * 2))) {
				//dead or smth
			}
			else {
				y += alto * 2;
			}			
			break;
		case Derecha:
			if (Container(bg, rec, x, y, ancho * 2, 0)) {
				//dead or smth
			}
			else {
				x += ancho * 2;
			}
			break;
		case Izquierda:
			if (Container(bg, rec, x, y, -(ancho * 2), 0)) {
				//dead or smth
			}
			else {
				x += ancho * 2;
			}
			break;
		}

	}

};
