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
		crearBotiquin();
		crearAmmo();
		//crearArmadura();
		crearBanana();
		crearRadio();
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
	void crearBanana() {
		Power* pow = new Power(400, 450, banana);//poner random x y
		Powers.push_back(pow);
	}
	void crearBotiquin() {
		Power* pow = new Power(450, 450, botiquin);//poner random x y
		Powers.push_back(pow);
	}
	void crearArmadura() {
		Power* pow = new Power(500, 450, armadura);//poner random x y
		Powers.push_back(pow);
	}
	void crearRadio() {
		Power* pow = new Power(550, 450, radio);//poner random x y
		Powers.push_back(pow);
	}
	void crearArma() {
		Power* pow = new Power(600, 450, arma);//poner random x y
		Powers.push_back(pow);
	}
	void crearAmmo() {
		Power* pow = new Power(650, 450, municion);//poner random x y
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
	void animarpUp( BufferedGraphics^ bg) {
		for (int i = 0; i < Powers.size(); i++) {
			Powers.at(i)->mover(bg);
		}
	}

	void moverMono(BufferedGraphics^ bg, Rectangle monoE, Rectangle balaE, int avX, int avY) {
		for (int i = 0; i < Monos.size(); i++) {
			Monos.at(i)->mover(bg, monoE);
			if (t_evento % 6 == 0) {
				Monos.at(i)->disparar(avX, avY);
			}
			Monos.at(i)->moverB(bg, balaE);
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