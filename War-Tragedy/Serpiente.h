#pragma once
#include "Entidad.h"
#include <math.h>
#include "Bala.h"
#include "Obstaculo.h"

class Serpiente :public Entidad {
private:
	float posx, posy;
	int fx, fy;
	float difx, dify;
	float mayor;
	vector<Bala*> vBala;

public:
	Serpiente() {}
	Serpiente(int x, int y) :Entidad(x, y, 64, 64, 500) {//poner ancho alto bien y determinar vida
		/*
		
		*/
		indX = 4;
		indY = 2;
		aumento = 1;
		vel = 3;
		Rx = ancho/2;
		Ry = 0;
		Rancho = ancho/2;
		Ralto = alto;
		direccion = Abajo;	
		this->fx = 0;
		this->fy = 0;

	}
	~Serpiente() {}

	void setfxfy(int afx, int afy) {
		this->fx = afx;
		this->fy = afy;
	}


	void mover(BufferedGraphics^ bg, Rectangle rec, vector<Obstaculo*> obstaculos) {
		Bitmap^ ser = gcnew Bitmap("assets/Enemigo/death snake.png");//conseguir asset de serpiente	
		indX++;
		if (indX >= 4) { indX = 0; }
		for (int i = 0; i < obstaculos.size(); i++) {				
			if (obstaculos.at(i)->Colision(Fhitbox)) {
				switch (direccion)
				{
				case Abajo:
					indY = 0;
					dx = 1;
					dy = 0;

					Rx = ancho / 4;
					Rancho = ancho / 2;

					break;
				case Arriba:
					indY = 3;
					dx = -1;
					dy = 0;

					Rx = ancho / 4;
					Rancho = ancho / 2;

					break;
				case Izquierda:
					indY = 1;
					dx = 0;
					dy = -1;

					Rx = 0;
					Rancho = ancho / 2;

					break;
				case Derecha:
					indY = 2;
					dx = 0;
					dy = 1;

					Rx = ancho / 2;
					Rancho = ancho / 2;

					break;
				}			
			}
			else {
				switch (direccion)
				{
				case Abajo:
					indY = 0;
					dx = 0;
					dy = 1;

					Rx = ancho / 4;
					Rancho = ancho / 2;

					break;
				case Arriba:
					indY = 3;
					dx = 0;
					dy = -1;

					Rx = ancho / 4;
					Rancho = ancho / 2;

					break;
				case Izquierda:
					indY = 1	;
					dx = -1;
					dy = 0;

					Rx = 0;
					Rancho = ancho / 2;

					break;
				case Derecha:
					indY = 2;
					dx = 1;
					dy = 0; 
					
					Rx = ancho / 2;
					Rancho = ancho / 2;

					break;
				}
			}
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
			if (vBala.at(i)->Colision(objetivo)) return true;
		}
		return false;
	}


};