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
		geA = new GeAliado();
		geE = new GeEnemigos();
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);
		geA = new GeAliado();
		geE = new GeEnemigos();
		geE->setlimiteHeli(1);
	}
	~Prado() {}

	void T_Evento(Jugador* ju) {
		t_evento++;
		if (t_evento % 40 == 0) geE->crearHel();
		if (t_evento % 17==0) geE->crearSol();
		if (t_evento % 50 == 0)geE->dispararHeli(ju->getx(),ju->gety());
		if (t_evento % 51 == 0)geE->dispararHeli(ju->getx(),ju->gety());
		if (t_evento % 52 == 0)geE->dispararHeli(ju->getx(),ju->gety());
		if (t_evento % 30 == 0)geE->dispararSol(ju->getx(), ju->gety());
		if (t_evento % 50 == 0) geA->crearMon();
		
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
	void animarEn(BufferedGraphics^ bf, Jugador*ju) {
		//geE->animarHel(bf,);
		geE->animarAvi(bf, borde);
		geE->animarHel(bf, borde);
		geE->animarSol(bf, borde);
		geE->SeguirMovSoldado(ju->getx(), ju->gety());
		geE->moverBalasHeli(bf, borde);
		geE->moverBalasSoldado(bf, borde);
		//geA->moverMono(bf,borde);
	}

};
