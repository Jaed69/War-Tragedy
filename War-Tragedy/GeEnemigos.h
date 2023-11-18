#pragma once

#include "Soldado.h"
#include "Bomba.h"
#include "Helicoptero.h"
#include "Avion.h"
#include "Serpiente.h"


class GeEnemigos
{
private:
	int t_evento;
	vector<Rectangle*> lisrec;
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
		Random r;
		int _x, _y;
		if (r.Next(100) % 2 == 0) {
			if (r.Next(100) % 4 == 0)
				_x = 1;
			else
				_x = 1244;
			_y = r.Next(1,670);
		}
		else {
			if (r.Next(100) % 4 == 0)
				_y = 1;
			else
				_y = 669;
			_x = r.Next(1,1245);
		}
		Soldado* sol = new Soldado(_x, _y);
		soldados.push_back(sol);
	}
	void crearBom() {
		Bomba* b = new Bomba(500, 500, 1000, 1000);
		bombas.push_back(b);
	}
	void crearHel() {
		Helicoptero* h = new Helicoptero(400, 50);
		helicopteros.push_back(h);
	}
	void crearAvi(Direcciones d) {
		int x, y;
		x = y = 0;
		switch (d)
		{
		case Abajo:
			x = 640;
			y = 0;
			break;
		case Arriba:
			x = 640;
			y = 720;
			break;
		case Izquierda:
			x = 1280;
			y = 360;
			break;
		case Derecha:
			x = 0;
			y = 360;
			break;
		default:
			break;
		}
		Avion* a = new Avion(640, 360, d);
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

	bool colBalaSol(Rectangle ajeno) {
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados.at(i)->colBala(ajeno)) return true;
			else return false;
		}
	}

	bool colBom(Rectangle ajeno) {
		for (int i = 0; i < bombas.size(); i++) {
			if (bombas.at(i)->Colision(ajeno)) return true;
			else return false;
		}
	}

	bool colBalaHel(Rectangle ajeno) {
		for (int i = 0; i < helicopteros.size(); i++) {
			if (helicopteros.at(i)->colBala(ajeno)) return true;
			else return false;
		}
	}

	bool colBalaSer(Rectangle ajeno) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->colBala(ajeno)) return true;
			else return false;
		}
	}

	bool colSer(Rectangle ajeno) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->Colision(ajeno)) return true;
			else return false;
		}
	}

};
