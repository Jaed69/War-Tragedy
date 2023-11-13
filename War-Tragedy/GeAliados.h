#pragma once
#include "Entidad.h"
#include "Mono.h"
#include "Bala.h"
#include <vector>
using namespace std;
class GeAliado {
private:
	int contador;
	vector<Mono*>listaMono;
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

	void moverMono(BufferedGraphics^ bg, Bitmap^ monoBM, Rectangle monoE, Bitmap^bala, Rectangle balaE, int avX, int avY) {
		for (int i = 0; i < listaMono.size(); i++) {
			listaMono.at(i)->mover(bg, monoBM, monoE);
			if (contador % 6 == 0) {
				listaMono.at(i)->disparar(avX, avY);
			}
			listaMono.at(i)->moverB(bg, bala, balaE);
		}
	}
};