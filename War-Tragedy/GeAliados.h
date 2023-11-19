#pragma once
#include "Mono.h"
#include "AvionAliado.h"
#include "Power.h"
#include "Kami.h"
#include "GeEnemigos.h"
class GeAliado {
private:
	int t_evento;
	vector<Mono*>Monos;
	vector<AvionAliado*> Aliados;
	vector<Power*> Powers;
	vector<Kami*> Kamis;

public:
	GeAliado(){
		t_evento = 0;
		crearKami();
	}
	~GeAliado(){}

	void T_Evento(Jugador* ju) {
		t_evento++;
		//agregar colision de kami


	}

	void crearMon() {
		Mono* mono = new Mono(260, 210);
		Monos.push_back(mono);
	}
	void crearAvi() {
		AvionAliado* avi = new AvionAliado(100, 0);
		Aliados.push_back(avi);
	}
	void crearPow() {
		Power* pow = new Power(700, 700);
		Powers.push_back(pow);
	}
	void crearKami() {
		Kami* k = new Kami(0, 0);
		Kamis.push_back(k);
	}

	void moverKami(Entidad* enem, BufferedGraphics^ bg) {
		for (int i = 0; i < Kamis.size(); i++) {
			Kamis.at(i)->mover(enem, bg);
		}
	}

	void moverMono(BufferedGraphics^ bg, Rectangle espacio) {
		for (int i = 0; i < Monos.size(); i++) {
			Monos.at(i)->mover(bg, espacio);
		}
	}
	void moverAvion(BufferedGraphics^ bg, Rectangle aviE, Rectangle balaE) {
		for (int i = 0; i < Aliados.size(); i++) {
			Aliados.at(i)->mover(bg, aviE);
			if (t_evento % 8 == 0) {
				Aliados.at(i)->disparar();
			}
			Aliados.at(i)->moverB(bg, balaE);
		}			
	}
	bool colKami(Rectangle ajeno) {
		for (int i = 0; i < Kamis.size(); i++) {
			if (Kamis.at(i)->Colision(ajeno)) return true;
			else return false;
		}
	}
};