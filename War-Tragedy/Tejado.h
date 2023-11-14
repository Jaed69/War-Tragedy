#pragma once
#include "GeAliados.h"
#include "GeEnemigos.h"
#include "Obstaculos.h"

class Tejado
{
private:
	int time;
	Rectangle margen;
	Rectangle borde;

public:
	Tejado(){
		time = 0;
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);
	}
	~Tejado(){}

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);

	}

};
