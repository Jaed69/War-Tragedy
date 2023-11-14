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
	vector<AvionAliado*> listaAviones;

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
	void crearAvion() {
		AvionAliado* avi = new AvionAliado(100, 0);
		listaAviones.push_back(avi);
	}
	/*
	* void moverAliados(BufferedGraphics^ bg, Bitmap^ monoBM, Rectangle monoE, Bitmap^ bala, Rectangle balaE, int avX, int avY) {
		moverMono(bg,monoBM,monoE,bala,balaE,avX,avY);
		moverAvion();
	}
	*/

	void moverMono(BufferedGraphics^ bg, Rectangle monoE, Rectangle balaE, int avX, int avY) {
		for (int i = 0; i < listaMono.size(); i++) {
			listaMono.at(i)->mover(bg, monoE);
			if (contador % 6 == 0) {
				listaMono.at(i)->disparar(avX, avY);
			}
			listaMono.at(i)->moverB(bg, balaE);
		}
	}
	void moverAvion(BufferedGraphics^ bg, Rectangle aviE, Rectangle balaE) {
		for (int i = 0; i < listaAviones.size(); i++) {
			listaAviones.at(i)->mover(bg, aviE);
			if (contador % 8 == 0) {
				listaAviones.at(i)->disparar();
			}
			listaAviones.at(i)->moverB(bg, balaE);
		}	
		
	}
};