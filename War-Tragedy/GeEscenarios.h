#pragma once
#include "Tejado.h"
#include "Edificio.h"
#include "Prado.h"
#include "Escenario.h"

enum Niveles { NTejado, NEdificio, NPrado, FinalM, FinalB, FinalBS, FinalMS };

class GeEscenarios
{
private:
	Niveles nivel;

	Tejado* nivel1;
	Edificio* nivel2;
	Prado* nivel3;

	int t_evento;

public:
	GeEscenarios(){
		nivel1 = new Tejado();
		nivel2 = new Edificio();
		nivel3 = new Prado();

		t_evento = 0;
	}

	~GeEscenarios(){}

	void T_Evento(Jugador* ju) {
		t_evento++;

		switch (nivel)
		{
		case NTejado:
			nivel1->T_Evento(ju);
			break;
		case NEdificio:
			nivel2->T_Evento(ju);
			break;
		case NPrado:
			nivel3->T_Evento(ju);
			break;
		default:
			break;
		}

	}

	void setNivel(Niveles nivel) { this->nivel = nivel; }

	Rectangle getMargen(){
		switch (nivel)
		{
		case NTejado:
			return nivel1->getMargen();
			break;
		case NEdificio:
			return nivel2->getMargen();
			break;
		case NPrado:
			return nivel3->getMargen();
			break;
		default:
			break;
		}	
	}
	Rectangle getBorde() {
		switch (nivel)
		{
		case NTejado:
			return nivel1->getBorde();
			break;
		case NEdificio:
			return nivel2->getBorde();
			break;
		case NPrado:
			return nivel3->getBorde();
			break;
		default:
			break;
		}
	}


	void Escenario(BufferedGraphics^ bf) {
		switch (nivel)
		{
		case NTejado:
			nivel1->animarFn(bf);
			nivel1->animarEn(bf);
			break;
		case NEdificio:
			nivel2->animarFn(bf);
			nivel2->animarEn(bf);
			break;
		case NPrado:
			nivel3->animarFn(bf);
			nivel3->animarEn(bf);
			break;
		default:
			break;
		}
	}


};
