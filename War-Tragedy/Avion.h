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
			break;
		case Arriba:
			indX = 0; indY = 0;
			dx = 0;
			dy = -1;
			break;
		case Izquierda:
			indX = 1; indY = 1;
			dx = -1;
			dy = 0;
			break;
		case Derecha:
			indX = 1; indY = 0;
			dx = 1;
			dy = 0;
			break;
		case ArrDer:
			indX = 1; indY = 0;
			dx = 1;
			dy = -1;
			break;
		case ArrIzq:
			indX = 1; indY = 1;
			dx = -1;
			dy = -1;
			break;
		case AbDer:
			indX = 1; indY = 0;
			dx = 1;
			dy = 1;
			break;
		case AbIzq:
			indX = 1; indY = 1;
			dx = -1;
			dy = 1;
			break;
		}
		x += dx * vel;
		y += dy * vel;
		dibujar(bg, avi);
		//if (!Colision(rec)) activo = false;
	}



};

