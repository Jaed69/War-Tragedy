#pragma once
#include "Entidad.h"
#include <math.h>
#include "Bala.h"

class Serpiente :public Entidad {
private:
	float posx, posy;
	int fx, fy;
	float difx, dify;
	float mayor;
	vector<Bala*> balas;

public:
	Serpiente() {}
	Serpiente(int x, int y) :Entidad(x, y, 32, 48, 20) {//poner ancho alto bien y determinar vida
		/*
		
		*/
		indX = 4;
		indY = 2;
		aumento = 1;
		vel = 3;
		Rx = Ry = 5;
		Rancho = Ralto = 20;
		direccion = Abajo;
		this->fx = 0;
		this->fy = 0;

	}
	~Serpiente() {}

	void setfxfy(int afx, int afy) {
		this->fx = afx;
		this->fy = afy;
	}


	void mover(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ ser = gcnew Bitmap("assets/Personaje/Personaje.png");//conseguir asset de serpiente		
		switch (direccion)
		{
		case Abajo:
			dx = 0;
			dy=1;
			break;
		case Arriba:
			dx = 0;
			dy=-1;
			break;
		case Izquierda:
			dx=-1;
			dy = 0;
			break;
		case Derecha:
			dx =1;	
			dy = 0;
			break;
		}
		if (x > (fx - 20)) {
			direccion = Izquierda;
		}
		if (x < (fx + 20)) {
			direccion = Derecha;
		}
		if (x >= (fx - 20) && x <= (fx + 20)) {
			if (y > fy - 20) {
				direccion = Arriba;
			}
			if (y < (fy + 20)) {
				direccion = Abajo;
			}
		}
		x += dx*vel;
		y += dy*vel;

		dibujar(bg, ser);
		delete ser;
	}


};