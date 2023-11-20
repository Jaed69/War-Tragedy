#pragma once
#include "Recursos.h"

class Escena
{
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;

	bool termino;
public:
	Escena() {
		t_evento = 0;
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);

		termino = false;
	}

	~Escena() {}

	bool verTer() { return termino; }

	void animarFinal(BufferedGraphics^ bf, Keys tecla) {
		Bitmap^ rex = gcnew Bitmap("assets/PF/rip_exit.png");
		Bitmap^ rpa = gcnew Bitmap("assets/PF/rip_play_again.png");

		switch (tecla)
		{
		case Keys::S:
			bf->Graphics->DrawImage(rex, borde, borde, GraphicsUnit::Pixel);
			break;
		case Keys::W:
		default:
			bf->Graphics->DrawImage(rpa, borde, borde, GraphicsUnit::Pixel);
			break;
		}





		delete rex; delete rpa;
	}

};