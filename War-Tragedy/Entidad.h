#pragma once

using namespace System::Drawing;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };

class Entidad
{
protected:
	int x, y;
	int ancho, alto;
	int dx, dy;
	int vel;
	int indX, indY;
	Direcciones ultimaTecla;
	Direcciones direccion;

public:
	Entidad(){}

	Entidad(int x, int y){
		this->x = x;
		this->y = y;
		dx = dy = 0;
		vel = 1;
		ultimaTecla = Abajo;
		direccion = Ninguna;
		ancho = 40;
		alto = 56;
		indX = 0;
		indY = 0;
	}

	~Entidad(){}

	void setDireccion(Direcciones d) { direccion = d; }

	int getX() { return x; }

	int getY() { return y; }

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

	void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indX * ancho, indY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		x += dx * vel;
		y += dy * vel;
	}


};