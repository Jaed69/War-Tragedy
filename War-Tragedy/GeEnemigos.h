#pragma once
#include "Soldado.h"
#include "Bomba.h"
#include "Helicoptero.h"
#include "Avion.h"
#include "Serpiente.h"
#include "Kami.h"

class GeEnemigos{
private:
	int contador;
	vector<Soldado*> soldados;
	vector<Bomba*> bombas;
	vector<Helicoptero*> helicopteros;
	vector<Avion*> aviones;
	vector<Serpiente*> serpientes;
	vector<Kami*> listaka;
	
public:
	GeEnemigos(){
		Helicoptero* h = new Helicoptero(0);
		helicopteros.push_back(h);
		contador = 0;
	}
	~GeEnemigos(){}

	void sumCont() {
		contador += 1;
		if (contador % 150 == 0) {
			crearKami();
		}
		if (contador % 500 == 0) {
			crearHeli();
		}
	}
	void crearKami() {
		Kami* k = new Kami(0, 0);
		listaka.push_back(k);
	}
	void crearHeli() {
		Helicoptero* h = new Helicoptero(0);
		helicopteros.push_back(h);
	}

	void MoverKami(Jugador* ju, BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < listaka.size(); i++) {
			listaka.at(i)->mover(ju,bg, bm, rec);
		}
	}
	void MoverHeli(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < helicopteros.size(); i++) {
			helicopteros.at(i)->mover(bg, rec);
		}
	}

};
