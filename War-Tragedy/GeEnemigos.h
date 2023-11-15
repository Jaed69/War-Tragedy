#pragma once
#include "Soldado.h"
#include "Bomba.h"
#include "Helicoptero.h"
#include "Avion.h"
#include "Serpiente.h"

class GeEnemigos{
private:
	int t_evento;
	vector<Soldado*> soldados;
	vector<Bomba*> bombas;
	vector<Helicoptero*> helicopteros;
	vector<Avion*> aviones;
	vector<Serpiente*> serpientes;
	
public:
	GeEnemigos(){
		t_evento = 0;
	}
	~GeEnemigos(){}

	void T_Evento() {
		t_evento++;
	}

	void crearSol() {
		Soldado* sol = new Soldado(100,100);
		soldados.push_back(sol);
	}
	void crearBom() {
		Bomba* b = new Bomba(500, 500, 1000, 1000);
		bombas.push_back(b);
	}
	void crearHel() {
		Helicoptero* h = new Helicoptero(0);
		helicopteros.push_back(h);
	}
	void crearAvi() {
		Avion* a = new Avion(600, 0);
		aviones.push_back(a);
	}
	void crearSer() {
		Serpiente* s = new Serpiente(500, 500, 1000, 1000);
		serpientes.push_back(s);
	}
	
	void animarSol(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados.at(i)->getActivo())
				soldados.at(i)->mover(bg, con);
			else
				soldados.erase(soldados.begin() + i);
		}
	}

	void animarBom(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < bombas.size(); i++) {
			if (bombas.at(i)->getActivo())
				bombas.at(i)->mover(bg, con);
			else
				bombas.erase(bombas.begin() + i);
		}
	}

	void animarHel(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < helicopteros.size(); i++) {
			if (helicopteros.at(i)->getActivo())
				helicopteros.at(i)->mover(bg, con);
			else
				helicopteros.erase(helicopteros.begin() + i);			
		}
	}

	void animarAvi(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < aviones.size(); i++) {
			if (aviones.at(i)->getActivo())
				aviones.at(i)->mover(bg, con);
			else
				aviones.erase(aviones.begin() + i);
		}
	}

	void animarSer(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->getActivo())
				serpientes.at(i)->mover(bg, con);
			else
				serpientes.erase(serpientes.begin() + i);
		}
	}

	void colBom(Rectangle ajeno) {
		for (int i = 0; i < bombas.size(); i++)
		{
			bombas.at(i)->Colision(ajeno);
		}
	}

};
