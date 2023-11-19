#pragma once
#include "Recursos.h"

class PanFinal
{
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;

	bool termino;
public:
	PanFinal() {
		t_evento = 0;
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);

		termino = false;
	}

	~PanFinal() {}

	bool verTer() { return termino; }

	void animarFinal(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		delete fondo;
	}

};