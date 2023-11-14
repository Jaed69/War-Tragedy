#pragma once
#include<vector>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha, ArrDer, ArrIzq, AbDer, AbIzq, Dash };

class Entidad
{
protected:
	int x, y;
	int Rx, Ry;
	int ancho, alto;
	int Rancho, Ralto;
	float dx, dy;
	int vel;
	int indX, indY;
	int vida;
	int aumento;
	bool activo;
	Direcciones ultDireccion;
	Direcciones direccion;
	Rectangle area;
	Rectangle zonaAumento;
	Rectangle hitbox;
	Rectangle Fhitbox;

public:
	Entidad(){}

	Entidad(int x, int y, int ancho, int alto, int vida){
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		dx = dy = 0;
		Rx = Ry = 0;
		Rancho = Ralto = 0;
		vel = 1;
		ultDireccion = Abajo;
		direccion = Ninguna;
		indX = 0;
		indY = 0;
		aumento = 1;
		activo = true;
		this->vida = vida;
	}

	~Entidad(){}

	void setDireccion(Direcciones d) { direccion = d; }
	int getx() { return this->x; }
	int gety() { return this->y; }
	int getdx() { return this->dx; }
	int getdy() { return this->dy; }
	int getvida() { return this->vida; }
	void setvida(int vidas) { this->vida = vidas; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }
	void setancho(int ancho) { this->ancho = ancho; }
	void setalto(int alto) { this->alto = alto; }

	bool getActivo() { return this->activo; }
	void setActivo(bool activo) { this->activo = activo; }

	void setRxRy(int rx, int ry) {
		this->Rx = rx;
		this->Ry = ry;
	}

	void setRnRl(int Rancho, int Ralto) {
		this->Rancho = Rancho;
		this->Ralto = Ralto;
	}

	bool Container(BufferedGraphics^ bg, Rectangle container, int dx, int dy) {
		Fhitbox = Rectangle(x + Rx + dx, y + Ry + dy, Rancho, Ralto);
		return (container.Contains(Fhitbox));
	}

	Rectangle getHB() { return hitbox; }

	bool Colision(Rectangle ajeno) {
		return hitbox.IntersectsWith(ajeno);
	}

	void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		if (activo)
		{
			area = Rectangle(indX * ancho, indY * alto, ancho, alto);
			zonaAumento = Rectangle(x, y, ancho * aumento, alto * aumento);
			hitbox = Rectangle(x + Rx, y + Ry, Rancho, Ralto);
			


			bg->Graphics->DrawRectangle(gcnew Pen(Color::Green), Fhitbox);
			bg->Graphics->DrawRectangle(gcnew Pen(Color::Blue), hitbox);
			//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), zonaAumento);
			bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);

		}

	}


};

/*
 void mover(BufferedGraphics^ bg, Bitmap^ bm) {

		switch (direccion)
		{
		case Abajo:
			indY = 0;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			dx = 0;
			dy = 10;
			ultimaTecla = Abajo;
			break;
		case Arriba:
			indY = 3;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			dx = 0;
			dy = -10;
			ultimaTecla = Arriba;
			break;
		case Izquierda:
			indY = 1;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			dx = -10;
			dy = 0;
			ultimaTecla = Izquierda;
			break;
		case Derecha:
			indY = 2;
			if (indX >= 0 && indX < 3) {
				indX++;
			}
			else {
				indX = 0;
			}
			dx = 10;
			dy = 0;
			ultimaTecla = Derecha;
			break;
		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Abajo:
				indY = 0;
				indX = 0;
				break;
			case Arriba:
				indY = 3;
				indX = 0;
				break;
			case Izquierda:
				indY = 1;
				indX = 0;
				break;
			case Derecha:
				indY = 2;
				indX = 0;
				break;

			}

		}
		dibujar(bg, bm);

	}
 
 */