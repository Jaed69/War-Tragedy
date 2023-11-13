#pragma once
#include "Entidad.h"
#include "Mono.h"
#include "Bala.h"
#include <vector>
#include "AvionAliado.h"
using namespace std;
class GeAliado {
private:
	int contador;
	vector<Mono*>listaMono;
	AvionAliado* avion;

public:
	GeAliado(){
		contador = 0;
	}
	~GeAliado(){}

	void sumCont() {
		contador += 1;
	}

	void crearmono() {
		Mono* mono = new Mono(260, 210);
		listaMono.push_back(mono);
	}
	/*
	* void moverAliados(BufferedGraphics^ bg, Bitmap^ monoBM, Rectangle monoE, Bitmap^ bala, Rectangle balaE, int avX, int avY) {
		moverMono(bg,monoBM,monoE,bala,balaE,avX,avY);
		moverAvion();
	}
	*/

	void moverMono(BufferedGraphics^ bg, Bitmap^ monoBM, Rectangle monoE, Bitmap^bala, Rectangle balaE, int avX, int avY) {
		for (int i = 0; i < listaMono.size(); i++) {
			listaMono.at(i)->mover(bg, monoBM, monoE);
			if (contador % 6 == 0) {
				listaMono.at(i)->disparar(avX, avY);
			}
			listaMono.at(i)->moverB(bg, bala, balaE);
		}
	}
	void moverAvion(BufferedGraphics^ bg, Bitmap^ aviBM, Rectangle aviE, Bitmap^ bala, Rectangle balaE) {
		avion->mover(bg,aviBM,aviE);
		if (contador % 8 == 0) {
			avion->disparar();
		}
	}
};