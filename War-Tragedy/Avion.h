#pragma once
#include "Entidad.h"

class Avion :public Entidad {
private:
public:
	Avion(int x, int y, Direcciones d) :Entidad(x,y,40, 40, 1) {
		indX = indY = 0;
		direccion = d;
		aumento = 2;
		vel = 5;

	}
	~Avion() {}

	void mover(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ avi = gcnew Bitmap("assets/Enemigo/Avion/image.png");

		switch (direccion)
		{
		case Ninguna:
			indX = 0; indY = 0;
			break;
		case Abajo:
			indX = 0; indY = 1;
			dx = 0;
			dy = 1;

			Rx = 31; Ry = 18;
			Rancho = 7; Ralto = 22;
			break;
		case Arriba:
			indX = 0; indY = 0;
			dx = 0;
			dy = -1;

			Rx = 34; Ry = 14;
			Rancho = 6; Ralto = 23;
			break;
		case Izquierda:
			indX = 1; indY = 1;
			dx = -1;
			dy = 0;

			Rx = 14; Ry = 32;
			Rancho = 23; Ralto = 6;
			break;
		case Derecha:
			indX = 1; indY = 0;
			dx = 1;
			dy = 0;

			Rx = 18; Ry = 33;
			Rancho = 22; Ralto = 7;
			break;
		default:
			break;
		}
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, avi);
		if (!Colision(rec)) activo = false;
	}



};

