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
	vector<Kami*> listaka;
public:
	GeEnemigos(){
		contador = 0;
	}
	~GeEnemigos(){}

	void sumCont() {
		contador += 1;
		if (contador % 150 == 0) {
			crearKami();
		}
	}
	void crearKami() {
		Kami* k = new Kami(0, 0);
		listaka.push_back(k);
	}

	void MoverKami(Jugador* ju, BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < listaka.size(); i++) {
			listaka.at(i)->mover(ju,bg, bm, rec);
		}
	}

};
