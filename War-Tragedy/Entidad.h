#pragma once

using namespace System::Drawing;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha, ArrDer, ArrIzq, AbDer, AbIzq };

class Entidad
{
protected:
	int x, y;
	int ancho, alto;
	int dx, dy;
	int vel;
	int indX, indY;
	int vida;
	Direcciones ultDireccion;
	Direcciones direccion;

public:
	Entidad(){}

	Entidad(int x, int y, int ancho, int alto, int vida){
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		dx = dy = 0;
		vel = 1;
		ultDireccion = Abajo;
		direccion = Ninguna;
		indX = 0;
		indY = 0;
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

	Rectangle getRec() {
		return Rectangle(x, y, ancho, alto);
	}

	bool Container(BufferedGraphics^ bg, Rectangle container, int x, int y, int dx, int dy) {
		Rectangle _r = Rectangle(x + dx, y + dy, ancho, alto);
		bg->Graphics->DrawRectangle(gcnew Pen(Color::Blue), _r);
		return (container.Contains(_r));
	}
	
	bool Colision(BufferedGraphics^ bg, Rectangle ajeno) {
		return getRec().IntersectsWith(ajeno);
	}

	void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indX * ancho, indY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		x += dx * vel;
		y += dy * vel;
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