#pragma once
#include "Jugador.h"
#include "GeEscenarios.h"
#include "UI.h"

class Juego
{
private:
	Jugador* jugador;
	GeEscenarios* geEs;
	UI* iu;

	int t_evento;

public:
	Juego() {
		jugador = new Jugador(620, 404);
		geEs = new GeEscenarios();
		iu = new UI();

		t_evento = 0;
	}

	~Juego() {}

	void T_Evento() {
		t_evento++;
		geEs->T_Evento(jugador);


		if (jugador->getDash() == false) {

			if (t_evento > 5) {
				t_evento = 0;
				jugador->setDash(true);
			}
		}
	}

	void setNivel(Niveles nivel) { geEs->setNivel(nivel); }

	void disparar(int x, int y) {
		jugador->disparar(x, y);
	}

	void movPF(Keys tecla) { geEs->movPF(tecla); }

	void movJugador(bool teclapres, Keys tecla) {

		if (teclapres)
		{
			switch (tecla)
			{
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

	void animarPl(BufferedGraphics^ bf) {
		jugador->animar(bf, geEs->getMargen());
		jugador->moverB(bf, geEs->getBorde());

	}
	void jugar(BufferedGraphics^ bf) {
		geEs->Escenario(bf, jugador);
		switch (geEs->getNivel())
		{
		case NTejado:
		case NPrado:
		case NEdificio:
			iu->movVida(bf, jugador->getvida());
			iu->movChaleco(bf, jugador->getchaleco());
			animarPl(bf);
			break;
		default:
			break;
		}

		
	}

	void animarBala() {

	}

	void vida(BufferedGraphics^ bg) {
		Bitmap^ vidaa = gcnew Bitmap("assets/UI/Vida.png");
		int BarraVida = 0;
		if (jugador->getvida() == 100) BarraVida = 10;
		if (jugador->getvida() < 100 && jugador->getvida() > 89) BarraVida = 9;
		if (jugador->getvida() <= 89 && jugador->getvida() > 78) BarraVida = 8;
		if (jugador->getvida() <= 78 && jugador->getvida() > 67) BarraVida = 7;
		if (jugador->getvida() <= 67 && jugador->getvida() > 56) BarraVida = 6;
		if (jugador->getvida() <= 56 && jugador->getvida() > 45) BarraVida = 5;
		if (jugador->getvida() <= 45 && jugador->getvida() > 34) BarraVida = 4;
		if (jugador->getvida() <= 34 && jugador->getvida() > 23) BarraVida = 3;
		if (jugador->getvida() <= 23 && jugador->getvida() > 10) BarraVida = 2;
		if (jugador->getvida() == 0) BarraVida = 1;
		Rectangle area = Rectangle(BarraVida * 96, 0 * 96, 96, 96);
		Rectangle zonaAumento = Rectangle(30, 0, 96, 96);
		bg->Graphics->DrawImage(vidaa, zonaAumento, area, GraphicsUnit::Pixel);
		delete vidaa;
	}


};
