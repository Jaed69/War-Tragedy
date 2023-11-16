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

	~Juego(){}

	void T_Evento() { 
		t_evento++;
		geEs->T_Escenarios();


		if (jugador->getDash() == false) {
			
			if (t_evento > 5) {
				t_evento = 0;
				jugador->setDash(true);
			}
		}
	}

	void setNivel(Niveles nivel) { geEs->setNivel(nivel); }

	void disparar(int x,int y) {
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

	void animarPl(BufferedGraphics^ bf) {
		jugador->animar(bf, geEs->getMargen());
		jugador->moverB(bf, geEs->getBorde());
	}

	void jugar(BufferedGraphics^ bf) {
		geEs->Escenario(bf);
		animarPl(bf);
	}

};
