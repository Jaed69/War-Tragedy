#pragma once
#include "GeAliados.h"
#include "GeEnemigos.h"
#include "Obstaculo.h"

class Prado
{
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	GeAliado* geA;
	GeEnemigos* geE;
	vector<Obstaculo*> obstaculos;

public:
	Prado() {
		t_evento = 0;
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);
		geA = new GeAliado();
		geE = new GeEnemigos();
	}
	~Prado() {}

	void T_Evento() {
		t_evento++;
	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel3.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		delete fondo;
	}

	//Zona en qeu se codifica el comportamiento de los enemigos
	void animarEn(BufferedGraphics^ bf) {
		//geE->animarHel(bf,);
		geE->animarAvi(bf, borde);
	}

};
