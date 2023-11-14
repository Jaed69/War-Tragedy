#pragma once
#include "Soldado.h"
#include "Bomba.h"
#include "Helicoptero.h"
#include "Avion.h"
#include "Serpiente.h"

class GeEnemigos{
private:
	int contador;
	vector<Soldado*> soldados;
	vector<Bomba*> bombas;
	vector<Helicoptero*> helicopteros;
	vector<Avion*> aviones;
	vector<Serpiente*> serpientes;
	
public:
	GeEnemigos(){
		contador = 0;
	}
	~GeEnemigos(){}

	void sumCont() {
		contador += 1;
		if (contador % 500 == 0) {
			crearHel();
		}
	}
	void crearSol() {
		Soldado* sol = new Soldado();
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
	
	void MoverHeli(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < helicopteros.size(); i++) {
			helicopteros.at(i)->mover(bg, rec);
		}
	}

};
