#pragma once
#include "Jugador.h"
#include "GeEscenarios.h"

class Juego
{
private:
	Jugador* jugador;
	GeEscenarios* geEs;

	int t_evento;

public:
	Juego() {
		jugador = new Jugador(620, 404);
		geEs = new GeEscenarios();
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

	void movJugador(bool teclapres, Keys tecla) {

		if (teclapres)
		{
			switch (tecla)
			{
			case Keys::I:; break;
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

	void vida(BufferedGraphics^ bg) {
		Bitmap^ vidaa = gcnew Bitmap("assets/Nivel/UI/ui x1.png");
		int BarraVida=0;
		if (jugador->getvida() ==100) BarraVida = 10;
		if (jugador->getvida() < 100 && jugador->getvida() > 89) BarraVida = 9;
		if (jugador->getvida() <= 89 && jugador->getvida() > 78) BarraVida = 8;
		if (jugador->getvida() <= 78 && jugador->getvida() > 67) BarraVida = 7;
		if (jugador->getvida() <= 67 && jugador->getvida() > 56) BarraVida = 6;
		if (jugador->getvida() <= 56 && jugador->getvida() > 45) BarraVida = 5;
		if (jugador->getvida() <= 45 && jugador->getvida() > 34) BarraVida = 4;
		if (jugador->getvida() <= 34 && jugador->getvida() > 23) BarraVida = 3;
		if (jugador->getvida() == 0) BarraVida = 1;
		Rectangle area = Rectangle(BarraVida * 31.8, 0 * 32, 31.8, 32);
		Rectangle zonaAumento = Rectangle(30, 0, 31.8*3, 32*3);
		bg->Graphics->DrawImage(vidaa, zonaAumento, area, GraphicsUnit::Pixel);
		delete vidaa;
	}
	void animarPl(BufferedGraphics^ bf) {
		jugador->animar(bf, geEs->getMargen());
		jugador->moverB(bf, geEs->getBorde());
	}
	void jugar(BufferedGraphics^ bf) {
		geEs->Escenario(bf, jugador);
		animarPl(bf);
	}

};
