#pragma once
#include "Entidad.h"
#include "Bala.h"
enum poderes {banana,botiquin, arma, armadura, radio, municion};

class Power :public Entidad {
private:
	poderes tipo;
public:
	Power(int x, int y, poderes type) :Entidad(x, y, 0, 0, 10) {
		direccion = AbDer;
		ultDireccion = Ninguna;
		dx = dy = indX = indY = 0; vel = 0;
		Rx = 0;
		Ry = 0;
		Rancho = alto;
		Ralto = ancho;
		aumento = 1;
		tipo = type;
		activo = true;
	}
	~Power() {}

	void mover(BufferedGraphics^ bg) {
		Bitmap^ Boti = gcnew Bitmap("assets/PowerUp/botiquin.png");
		Bitmap^ banan = gcnew Bitmap("assets/PowerUp/Banana.png");
		Bitmap^ gun = gcnew Bitmap("assets/PowerUp/minigun.png");
		Bitmap^ armonr = gcnew Bitmap("assets/PowerUp/radio.png");
		Bitmap^ rad = gcnew Bitmap("assets/PowerUp/radio.png");
		Bitmap^ muni = gcnew Bitmap("assets/PowerUp/ammo.png");
		switch (tipo)
		{
		case banana:
			ancho = 12;
			alto = 10; 
			Rancho = 12;
			Ralto = 10;
			dibujar(bg, banan);
			break;
		case botiquin:
			alto = 12;
			ancho = 16;
			Rancho = 12;
			Ralto = 16;
			dibujar(bg, Boti);
			break;
		case arma:
			ancho = 35;
			alto = 12;
			Rancho = 35;
			Ralto = 12;
			dibujar(bg, gun);

			break;
		case armadura:

			break;
		case radio:
			ancho = 9;
			alto = 14;
			Rancho = 9;
			Ralto = 14;
			dibujar(bg, rad);
			break;
		case municion:
			ancho = 23;
			alto = 12;
			Rancho = 23;
			Ralto = 12;
			dibujar(bg, muni);
			break;

		default:
			break;
		}
		delete Boti;
		delete banan;
		delete gun;
		delete armonr;
		delete rad;
		delete muni;
	}
	poderes gettype() {
		return tipo;		
	}

};