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

	bool termino;

public:
	Tejado(){
		t_evento = 0;
		geA = new GeAliado();
		geE = new GeEnemigos();
		margen = Rectangle(256, 144, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);

		termino = false;
		//geE->crearSer();
	}
	~Tejado(){}

	bool verTer() { return termino; }

	//Zona para la creacion de eventos segun el tiempo
	void T_Evento(Jugador* ju) {//añadir jugador
		t_evento++;
		geE->T_Evento(ju);
		geA->T_Evento(ju, margen);
		//geE->coordsserpent(ju->getx(),ju->gety());
		if(t_evento%2 == 0) geE->conAvi(margen);
		if (t_evento == 20) geE->crearAvi(Arriba);
		if (t_evento == 120) geE->crearAvi(Izquierda);
		//if (t_evento == 20) geE->crearAvi(Derecha);
		if (t_evento % 40 == 0) geE->crearHel(); 
		if (t_evento % 50 == 0)geE->dispararHeli(ju->getx(), ju->gety());
		if (t_evento % 51 == 0)geE->dispararHeli(ju->getx(), ju->gety());
		if (t_evento % 52 == 0)geE->dispararHeli(ju->getx(), ju->gety());
		
		if (t_evento == 5) {
			geA->crearRandomPower(margen);
		}
		if (t_evento % 50 == 0) {
			geA->crearRandomPower(margen);
		}

		if (t_evento == 400)termino = true;
	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Red), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		delete fondo;
	}

	//Zona en qeu se codifica el comportamiento de los enemigos
	void animarEn(BufferedGraphics^ bf, Jugador* ju) {  
		geE->animarHel(bf,borde);
		geE->animarLla(bf, borde);
		geE->animarAvi(bf, borde);
		geE->moverBalasHeli(bf, borde, ju);
		//geE->animarSer(bf, borde);
	}
	void animarAl(BufferedGraphics^ bf) { //agregar todos los aliados
		geA->moverKami(geE->getRandomEnem(), bf);
		geA->moverMono(bf, borde);
		geA->animarpUp(bf);
		geA->moverAvion(bf, borde);
	}

};
