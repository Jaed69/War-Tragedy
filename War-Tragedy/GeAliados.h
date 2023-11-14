#pragma once
#include "Mono.h"
#include "AvionAliado.h"
#include "Power.h"
#include "Kami.h"

class GeAliado {
private:
	int contador;
	vector<Mono*>Monos;
	vector<AvionAliado*> Aliados;
	vector<Power*> Powers;
	vector<Kami*> Kamis;

public:
	GeAliado(){
		contador = 0;
	}
	~GeAliado(){}

	void sumCont() {
		contador += 1;
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
	void crearKam() {
		Kami* k = new Kami(0, 0);
		Kamis.push_back(k);
	}

	void MoverKami(Jugador* ju, BufferedGraphics^ bg, Bitmap^ bm, Rectangle rec) {
		for (int i = 0; i < Kamis.size(); i++) {
			Kamis.at(i)->mover(ju, bg, bm, rec);
		}
	}

	void moverMono(BufferedGraphics^ bg, Rectangle monoE, Rectangle balaE, int avX, int avY) {
		for (int i = 0; i < Monos.size(); i++) {
			Monos.at(i)->mover(bg, monoE);
			if (contador % 6 == 0) {
				Monos.at(i)->disparar(avX, avY);
			}
			Monos.at(i)->moverB(bg, balaE);
		}
	}
	void moverAvion(BufferedGraphics^ bg, Rectangle aviE, Rectangle balaE) {
		for (int i = 0; i < Aliados.size(); i++) {
			Aliados.at(i)->mover(bg, aviE);
			if (contador % 8 == 0) {
				Aliados.at(i)->disparar();
			}
			Aliados.at(i)->moverB(bg, balaE);
		}	
		
	}
};