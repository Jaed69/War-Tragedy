#pragma once
#include "Jugador.h"
#include "Tejado.h"
#include "Edificio.h"
#include "Prado.h"

enum Niveles { Tejado, Edificio, Prado };

class Juego
{
private:
	Niveles nivel;
	Jugador* jugador;
	int time;
	Rectangle margen;
	Rectangle margen2;
	Rectangle borde;
public:
	Juego(Niveles nivel) {
		this->nivel = nivel;
		jugador = new Jugador(620, 400);
		time = 0;
		margen = Rectangle(256, 144, 768, 432);
		margen2 = Rectangle(256, 176, 768, 432);
		borde = Rectangle(0, 0, 1280, 720);

		
	}
	~Juego(){}

	void sumTime() { 
		if (jugador->getDash() == false) {
			time++;
			if (time > 5) {
				time = 0;
				jugador->setDash(true);
			}
		}
	}

	void disparar(int x,int y) {
		jugador->disparar(x, y);
	}

	void movJugador(bool teclapres, Keys tecla) {

		if (teclapres)
		{
			switch (tecla)
			{
			case Keys::I:jugador->disparar(100, 100); break;
			case Keys::W:jugador->setDireccion(Arriba); break;
			case Keys::A: jugador->setDireccion(Izquierda); break;
			case Keys::S: jugador->setDireccion(Abajo); break;
			case Keys::D: jugador->setDireccion(Derecha); break;

			case Keys::Space: 
				if (jugador->getDash()) { 
					jugador->setDireccion(Dash);
					jugador->setDash(false); 
				} 
				break;

			default:
				break;

			}
		}
		else {
			jugador->setDireccion(Ninguna);
		}

	}

	void animar(BufferedGraphics^ bf) {
		animarFn(bf);
		animarPl(bf);
	}



	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/Nivel1.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);

		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);

	}

	void animarPl(BufferedGraphics^ bf) {
		jugador->mover(bf, margen);
		jugador->moverB(bf, borde);
	}

};
