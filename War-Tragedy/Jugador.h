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
				indX = 0;
				indY = 0;
				break;
			case Arriba:
				indX = 0;
				indY = 3;
				break;
			case Izquierda:
				indX = 0;
				indY = 1;
				break;
			case Derecha:
				indX = 0;
				indY = 2;
				break;
			default:
				break;
			}
			break;
		case Abajo:
			indY = 0;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			if (Container(bg, rec, x, y, 0, 10)) {
				dx = 0; dy = 10; ultDireccion = Abajo;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Abajo;
			}
			break;
		case Arriba:
			indY = 3;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			if (Container(bg, rec, x, y, 0, -10)) {
				dx = 0; dy = -10; ultDireccion = Arriba;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Arriba;
			}
			break;
		case Izquierda:
			indY = 1;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			if (Container(bg, rec, x, y, -10, 0)) {
				dx = -10; dy = 0; ultDireccion = Izquierda;
			}
			else {
				dx = 0; dy = 0; ultDireccion = Izquierda;
			}
			break;
		case Derecha:
			indY = 2;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
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
};
