#pragma once
#include "GeAliados.h"
#include "GeEnemigos.h"
#include "Obstaculo.h"

class Tejado
{
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	GeAliado* geA;
	GeEnemigos* geE;
	vector<Obstaculo*> obstaculos;

public:
	Tejado(){
		t_evento = 0;
		geA = new GeAliado();
		geE = new GeEnemigos();
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);
	}
	~Tejado(){}

	void T_Evento() {
		t_evento++;
		geA->T_Evento();
		geE->T_Evento();
		if (t_evento == 20) geE->crearAvi(Arriba);
		
		if (t_evento == 50) t_evento = 0;
	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);

	}

	//Zona en qeu se codifica el comportamiento de los enemigos
	void animarEn(BufferedGraphics^ bf) {  
		//geE->animarHel(bf,);
		geE->animarAvi(bf, borde);
	}

};
