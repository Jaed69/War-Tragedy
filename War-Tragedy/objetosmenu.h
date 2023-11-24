#pragma once
#include "Entidad.h"
enum objM{papel1,papel2,papel3,papel4,estanteria,info,mesa, notas};
class objetosMenu : public Entidad {
private:
	objM tipo;
public:
	objetosMenu(int x, int y, objM tipo) :Entidad(x, y, 0, 0, 1) {
		dx = dy = Rx = Ry = vel = indX = indY = 0;
		direccion = ultDireccion = Abajo;
		this->tipo = tipo;
		Rancho = ancho;
		Ralto = alto;
		activo = true;
	}
	~objetosMenu() {}
	
	objM getTipo() { return tipo; }

	void dibujarr(BufferedGraphics^ bg) {
		switch (tipo)
		{
		case papel1:
			ancho = Rancho = 50;
			alto = Ralto = 40;
			break;
		case papel2:
			ancho = Rancho = 56;
			alto = Ralto = 40;
			break;
		case papel3:
			ancho = Rancho = 60;
			alto = Ralto = 40;
			break;
		case papel4:
			ancho = Rancho = 45;
			alto = Ralto = 36;
			break;
		case estanteria:
			ancho = Rancho = 250;
			alto = Ralto = 170;
			break;
		case info:
			ancho = Rancho = 600*0.75;
			alto = Ralto = 300*0.75;
			break;
		case mesa:
			ancho = Rancho = 420;
			alto = Ralto = 110;
			break;
		case notas:
			ancho = Rancho = 200;
			alto = Ralto = 300;
			break;
		default:
			break;
		}
		Rectangle area = Rectangle(ancho, alto, ancho, alto);
		Rectangle zonaaumento = Rectangle(x, y, ancho, alto);
		hitbox = Rectangle(x + Rx, y + Ry, Rancho * aumento, Ralto * aumento);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Orange), zonaaumento);

	}

};

/*
//mesa = Rectangle(222, 120, 420, 110);
		//estanteria = Rectangle(789, 66, 250, 170);
		//papel1 = Rectangle(613,291,50,40);
		//papel2 = Rectangle(490,356,56,40);
		//papel3 = Rectangle(579,446,60,40);
		//papel4 = Rectangle(697,391,45,36);
		//papel5 = Rectangle(881,328,45,35);
		//cama = Rectangle(193,428,120,199);
		//info = Rectangle(780, 485, 600*0.75, 300*0.75);
		//notas = Rectangle(100,360,200,300);

*/