#pragma once
#include "GeAliados.h"
#include "GeEnemigos.h"
#include "Obstaculo.h"

class Edificio
{
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	GeAliado* geA;
	GeEnemigos* geE;
	vector<Obstaculo*> obstaculos;

public:
	Edificio() {
		t_evento = 0;
		margen = Rectangle(256, 176, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);
		geA = new GeAliado();
		geE = new GeEnemigos();
		crearObs(356, 276, 50, 50);
		crearObs(356, 476, 50, 50);
		crearObs(656, 276, 50, 50);
		crearObs(656, 476, 50, 50);
		geE->crearSer();
	}
	~Edificio() {}

	void T_Evento(Jugador* ju) {
		t_evento++;
		if (t_evento%75 == 0) geE->crearBom(440, 360);
		if (t_evento == 101) geE->crearBom(840, 360);
		if (t_evento == 102) geE->crearBom(640, 260);
		if (t_evento == 103) geE->crearBom(640, 460);
		geE->coordsserpent(ju->getx(), ju->gety());
	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel2.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		delete fondo;
	}

	//Zona en qeu se codifica el comportamiento de los enemigos
	void animarEn(BufferedGraphics^ bf,Jugador* ju) {
		//geE->animarHel(bf,);
		geE->animarBom(bf);
		geE->animarSer(bf, borde, obstaculos);
		animarObs(bf);
	}

	void crearObs(int x, int y, int ancho, int alto) {
		Obstaculo* obs = new Obstaculo(x, y, ancho, alto);
		obstaculos.push_back(obs);
	}

	void animarObs(BufferedGraphics^ bg) {
		for (int i = 0; i < obstaculos.size(); i++) {
			if (obstaculos.at(i)->getActivo())
				obstaculos.at(i)->animar(bg);
			else
				obstaculos.erase(obstaculos.begin() + i);
		}
	}

};
