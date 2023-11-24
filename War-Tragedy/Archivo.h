#pragma once

#include "Juego.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Archivo {
	ofstream arch;
	ifstream archl;
	int vida;
	int armadura;
	int X, Y;
	int nivel;
	int direcion;
	int ultdirecion;
	int t_evento;
	Niveles niv;

public:
	Archivo() {}
	~Archivo() {}

	Niveles getN() { return niv; }

	void save(Juego* ju) {
		vida = ju->getVidaJu();
		armadura = ju->getChalJu();
		X = ju->getXJu();
		Y = ju->getYJu();
		switch (ju->getNivel()) {
		case NTejado:
			nivel = 0; break;
		case NEdificio:
			nivel = 1; break;
		case NPrado:
			nivel = 2; break;
		default:
			nivel = 3;
			break;
		}
		switch (ju->getDir()) {
		case Ninguna:
			direcion = 0; break;
		case Abajo:
			direcion = 1; break;
		case Arriba:
			direcion = 2; break;
		case Izquierda:
			direcion = 3; break;
		case Derecha:
			direcion = 4; break;
		default:
			direcion = 0;
			break;
		}
		switch (ju->getUltDir()) {
		case Ninguna:
			ultdirecion = 0; break;
		case Abajo:
			ultdirecion = 1; break;
		case Arriba:
			ultdirecion = 2; break;
		case Izquierda:
			ultdirecion = 3; break;
		case Derecha:
			ultdirecion = 4; break;
		default:
			ultdirecion = 0;
			break;
		}

		t_evento = ju->getT_Evento();

		arch.open("guardar.txt", ios::app);

		if (arch.is_open()) {
			arch << vida << endl;
			arch << armadura << endl;
			arch << X << endl;
			arch << Y << endl;
			arch << nivel << endl;
			arch << direcion << endl;
			arch << ultdirecion << endl;
			arch << t_evento << endl;
			arch.close();
		}
	}

	void load(Juego* ju) {
		archl.open("guardar.txt", ios::in);

		if (archl.is_open()) {
			archl >> vida;
			archl >> armadura;
			archl >> X;
			archl >> Y;
			archl >> nivel;
			archl >> direcion;
			archl >> ultdirecion;
			archl >> t_evento;
			archl.close();
		}

		ju->setVidaJu(vida);
		ju->setChalJu(armadura);
		ju->setXJu(X);
		ju->setYJu(Y);
		switch (nivel) {
		case 0:
			ju->setNivel(NTejado);
			niv = NTejado;
			break;
		case 1:
			ju->setNivel(NEdificio);
			niv = NEdificio;
			break;
		case 2:
			niv = NPrado;
			ju->setNivel(NPrado); break;
		default:
			niv = FinalM;
			ju->setNivel(FinalM); break;
			break;
		}
		switch (direcion) {
		case 1:
			ju->setDir(Abajo); break;
		case 2:
			ju->setDir(Arriba); break;
		case 3:
			ju->setDir(Izquierda); break;
		case 4:
			ju->setDir(Derecha); break;
		case 0:
		default:
			ju->setDir(Ninguna);
			break;
		}
		switch (ultdirecion) {
		case 1:
			ju->setUltDir(Abajo); break;
		case 2:
			ju->setUltDir(Arriba); break;
		case 3:
			ju->setUltDir(Izquierda); break;
		case 4:
			ju->setUltDir(Derecha); break;
		case 0:
		default:
			ju->setUltDir(Ninguna);
			break;
		}

		ju->setT_Evento(t_evento);

	}

};