#pragma once
#include "Tejado.h"
#include "Edificio.h"
#include "Prado.h"
#include "Escena.h"
#include "HabitacionS.h"
class GeEscenarios
{
private:
	Niveles nivel;

	Tejado* nivel1;
	Edificio* nivel2;
	Prado* nivel3;
	HabitacionS* nivel0;
	Escena* esce;

	int t_evento;
	Keys tecla;

public:
	GeEscenarios(){
		nivel1 = new Tejado();
		nivel2 = new Edificio();
		nivel3 = new Prado();
		nivel0 = new HabitacionS();
		esce = new Escena();

		t_evento = 0;
		tecla = Keys::W;
	}

	~GeEscenarios(){}

	void T_Evento(Jugador* ju) {
		t_evento++;

		if (ju->getvida() <= 0) nivel = FinalM;
		


		switch (nivel)
		{
		case habitacionS:
			nivel0->T_Evento(ju); 
			ju->setaumento(2); ju->setvel(15);
			if (nivel0->verTer()) nivel = habitacionS;
			break;
		case NTejado:
			nivel1->T_Evento(ju);
			ju->setaumento(1); ju->setvel(8);
			if (nivel1->verTer()) nivel = NEdificio;
			break;
		case NEdificio:
			ju->setaumento(1);
			nivel2->T_Evento(ju); ju->setvel(8);
			if (nivel2->verTer()) nivel = NPrado;
			break;
		case NPrado:
			ju->setaumento(1);
			nivel3->T_Evento(ju); ju->setvel(8);
			if (nivel3->verTer()) nivel = FinalM;
			break;
		case FinalM:
			break;
		case FinalB:
			break;
		case FinalMS:
			break;
		case FinalBS:
			break;
		default:
			break;
		}

	}

	void setNivel(Niveles nivel) { this->nivel = nivel; }
	Niveles getNivel() { return nivel; }

	Rectangle getMargen(){
		switch (nivel)
		{
		case habitacionS:
			return nivel0->getMargen();
			break;
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
		case habitacionS:
			return nivel0->getBorde();
			break;
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

	bool movPF(Keys entrada, Jugador* ju) { 
		switch (entrada)
		{
		case Keys::W:
		case Keys::S:
			tecla = entrada;
			break;
		case Keys::Enter:
			switch (tecla)
			{
			case Keys::W:
				ju->setvida(100);
				nivel = NTejado;
				break;
			case Keys::S:
				return true;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		return false;
	}

	void Escenario(BufferedGraphics^ bf, Jugador*ju) {
		switch (nivel)
		{
		case habitacionS:
			nivel0->animarFn(bf);
			nivel0->animarOb(bf, ju);
			break;
		case NTejado:
			nivel1->animarFn(bf);
			nivel1->animarEn(bf, ju);
			nivel1->animarAl(bf);
			//nivel1->animarAl(bf);
			break;
		case NEdificio:
			nivel2->animarFn(bf);
			nivel2->animarEn(bf, ju);
			nivel2->animarAl(bf);
			break;
		case NPrado:
			nivel3->animarFn(bf);
			nivel3->animarEn(bf, ju);
			nivel3->animarAl(bf);
			break;
		case FinalM:
			esce->animarFinal(bf, tecla);
			break;
		case FinalB:
			break;
		case FinalMS:
			break;
		case FinalBS:
			break;
		default:
			break;
		}
	}


};
