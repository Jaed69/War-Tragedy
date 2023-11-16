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

	//Zona para la creacion de eventos segun el tiempo
	void T_Evento(Jugador* ju) {//a�adir jugador
		t_evento++;
		geA->T_Evento();
		geE->T_Evento();
		if (t_evento == 20) geE->coordsserpent(ju->getx(),ju->gety());
		if (t_evento == 20) geE->crearAvi(Derecha);
		if (t_evento%40==0) geE->crearHel();
		/*if (t_evento == 50) geE->crearAvi(Derecha);
		if (t_evento == 80) geE->crearAvi(Abajo);
		if (t_evento == 110) geE->crearAvi(Izquierda);


		if (t_evento == 150) t_evento = 0;*/

		
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
		geE->animarHel(bf, borde);
	}


};
