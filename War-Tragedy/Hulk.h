#pragma once

using namespace System::Drawing;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };

class Hulk {
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Direcciones ultimaTecla;
	Direcciones direccion;

public:
	Hulk() {

	}

	Hulk(int x, int y) {
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		ultimaTecla = Abajo;
		direccion = Ninguna;
		ancho = 40;
		alto = 56;
		indiceX = 0;
		indiceY = 0;
	}

	~Hulk() {

	}

	void setDireccion(Direcciones d) {
		direccion = d;
	}

	void mover(BufferedGraphics^ bg, Bitmap^ bm) {

		switch (direccion)
		{
		case Abajo:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 3) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = 0;
			dy = 10;
			ultimaTecla = Abajo;
			break;
		case Arriba:
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 3) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = 0;
			dy = -10;
			ultimaTecla = Arriba;
			break;
		case Izquierda:
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 3) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = -10;
			dy = 0;
			ultimaTecla = Izquierda;
			break;
		case Derecha:
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 3) {
				indiceX++;
			}
			else {
				indiceX = 0;
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
				indiceY = 0;
				indiceX = 0;
				break;
			case Arriba:
				indiceY = 3;
				indiceX = 0;
				break;
			case Izquierda:
				indiceY = 1;
				indiceX = 0;
				break;
			case Derecha:
				indiceY = 2;
				indiceX = 0;
				break;

			}

		}
		dibujar(bg, bm);

	}

	void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};