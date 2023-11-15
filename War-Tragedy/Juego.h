#pragma once
#include "Jugador.h"
#include "GeEscenarios.h"

class Juego
{
private:
	Jugador* jugador;
	GeEscenarios* Es;

	int t_evento;
	
public:
	Juego() {
		jugador = new Jugador(620, 404);
		Es = new GeEscenarios();
		t_evento = 0;
		
	}

	~Juego(){}

	void T_Evento() { 
		t_evento++;
		Es->T_Evento();


		if (jugador->getDash() == false) {
			
			if (t_evento > 5) {
				t_evento = 0;
				jugador->setDash(true);
			}
		}
	}

	void setNivel(Niveles nivel) { Es->setNivel(nivel); }

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
		jugador->animar(bf, Es->getMargen());
		jugador->moverB(bf, Es->getBorde());
	}

	void jugar(BufferedGraphics^ bf) {
		Es->Escenario(bf);
		animarPl(bf);
	}

};
