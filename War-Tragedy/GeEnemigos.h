#pragma once

#include "Soldado.h"
#include "Bomba.h"
#include "Helicoptero.h"
#include "Avion.h"
#include "Serpiente.h"
#include "Flama.h"
#include "Explosion.h"


class GeEnemigos
{
private:
	int t_evento;
	int lim_hel;
	int cont_hel;

	vector<Soldado*> soldados;
	vector<Bomba*> bombas;
	vector<Helicoptero*> helicopteros;
	vector<Avion*> aviones;
	vector<Serpiente*> serpientes;
	vector<Flama*> flamas;
	vector<Explosion*> explosiones;
	int sArriba, sAbajo, sDerecha, sIzquierda;
	int sLimArriba, sLimAbajo, sLimDerecha, sLimIzquierda;
	int cantHeli, limCantHeli;

public:
	GeEnemigos() {
		t_evento = 0;
		sArriba = sAbajo = sDerecha = sIzquierda = 0;
		sLimArriba = sLimAbajo = sLimDerecha = sLimIzquierda = 3;
		cantHeli = 0; limCantHeli = 2;
		lim_hel = 2;
	}
	~GeEnemigos() {}

	void setlimiteHeli(int limite) { limCantHeli = limite; }
	int getTamHeli() { return helicopteros.size(); }

	void T_Evento(Jugador* ju) {
		t_evento++;
		if (colFla(ju->getFHB())) {
			ju->Dano();
			ju->resDano(1);
		}

		if (colBalaSol(ju->getHB())) ju->resDano(5);

		colBalJuAvi(ju);
		colBalJuHel(ju);
		colBalJuSer(ju);
		colBalJuSol(ju);


		/*if (colBalaSer(ju->getFHB())) {
			ju->Dano();
			ju->resDano(1);
		}*/
		/*if (colBalaSol(ju->getFHB())) {
			ju->Dano();
			ju->resDano(1);
		}*/
	/*	if (colBom(ju->getFHB())) {
			ju->Dano();
			ju->resDano(1);
		}*/
		if (colSer(ju->getFHB())) {
			ju->resDano(1);
		}
		
		
	}

	int getTAvi() { return aviones.size(); }
	int getLimCantHeli() { return limCantHeli; }

	void crearSol() {
		Random r;
		int _x, _y;
		
		if (sArriba < sLimArriba) {
			_y = 1; _x = r.Next(1, 1245);
			sArriba += 1;
			Soldado* sol = new Soldado(_x, _y,3);
			soldados.push_back(sol);
		}
		else if (sAbajo < sLimAbajo) {
			_y = 669; _x = r.Next(1, 1245);
			sAbajo += 1;
			Soldado* sol = new Soldado(_x, _y,4);
			soldados.push_back(sol);
		}
		else if (sDerecha < sLimDerecha) {
			_x = 1244; _y = r.Next(1, 670);
			sDerecha += 1;
			Soldado* sol = new Soldado(_x, _y,1);
			soldados.push_back(sol);
		}
		else if (sIzquierda < sLimIzquierda) {
			_x = 1; _y = r.Next(1, 670);
			sIzquierda += 1;
			Soldado* sol = new Soldado(_x, _y,2);
			soldados.push_back(sol);
		}
		
	}

	bool colBalJuSer(Jugador* ju) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (ju->colBala(serpientes.at(i)->getHB())) {
				serpientes.at(i)->resDano(1);
				return true;
			}
		}
		return false;
	}

	bool colBalJuHel(Jugador* ju) {
		for (int i = 0; i < helicopteros.size(); i++) {
			if (ju->colBala(helicopteros.at(i)->getHB())) {
				helicopteros.at(i)->resDano(1);
				return true;
			}
		}
		return false;
	}

	bool colBalJuSol(Jugador* ju) {
		for (int i = 0; i < soldados.size(); i++) {
			if (ju->colBala(soldados.at(i)->getHB())) {
				soldados.at(i)->resDano(20);
				return true;
			}
		}
		return false;
	}

	bool colBalJuAvi(Jugador* ju) {
		for (int i = 0; i < aviones.size(); i++) {
			if (ju->colBala(aviones.at(i)->getHB())) {
				aviones.at(i)->resDano(1);
				return true;
			}
		}
		return false;
	}

	void crearBom(int x, int y) {
		Bomba* b = new Bomba(x, y);
		bombas.push_back(b);
	}
	void crearHel() {
		if ( helicopteros.size() < lim_hel) {
			Helicoptero* h = new Helicoptero(400, 50);
			helicopteros.push_back(h);
		}
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
			y = 660;
			break;
		case Izquierda:
			x = 1235;
			y = 360;
			break;
		case Derecha:
			x = 0;
			y = 360;
			break;
		default:
			break;
		}
		Avion* a = new Avion(x, y, d);
		aviones.push_back(a);
	}

	void crearSer() {
		Serpiente* s = new Serpiente(500, 500);
		serpientes.push_back(s);
	}

	void crearLla(int x, int y) {
		Flama* lla = new Flama(x, y);
		flamas.push_back(lla);
	}
	void crearExplosion(int x, int y) {
		Explosion* exp = new Explosion(x, y);
		explosiones.push_back(exp);
	}
	void animarExplosiones(BufferedGraphics^ bg) {		
		for (int i = 0; i < explosiones.size(); i++) {
			if (explosiones.at(i)->getActivo())
				explosiones.at(i)->animar(bg);
			else
				explosiones.erase(explosiones.begin() + i);
		}
	}

	void animarSol(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados.at(i)->getActivo())
				soldados.at(i)->mover(bg, con);
			else {
				crearExplosion(soldados.at(i)->getx(), soldados.at(i)->gety());
				if (soldados.at(i)->getx() <=256&&sDerecha - 1 >= 0)sDerecha--;
				else if (soldados.at(i)->getx() >= 768 && sIzquierda-1>=0)sIzquierda--;
				else if (soldados.at(i)->gety() <= 144&&sArriba - 1 >= 0)sArriba--;
				else if (soldados.at(i)->gety() >= 432&&sAbajo - 1 >= 0)sAbajo--;
				soldados.erase(soldados.begin() + i);
			}

		}
	}

	void animarBom(BufferedGraphics^ bg) {
		for (int i = 0; i < bombas.size(); i++) {
			if (bombas.at(i)->getActivo())
				bombas.at(i)->animar(bg);
			else
				bombas.erase(bombas.begin() + i);
		}
	}

	void animarHel(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < helicopteros.size(); i++) {
			if (helicopteros.at(i)->getActivo())
				helicopteros.at(i)->mover(bg, con);
			else {
				crearExplosion(helicopteros.at(i)->getx(), helicopteros.at(i)->gety());
				helicopteros.erase(helicopteros.begin() + i);
				lim_hel++;
			}
		}
	}

	void animarAvi(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < aviones.size(); i++) {
			if (aviones.at(i)->getActivo())
				aviones.at(i)->mover(bg, con);
			else {
				crearExplosion(aviones.at(i)->getx(), aviones.at(i)->gety());
				aviones.erase(aviones.begin() + i);
			}
		}
	}

	void animarSer(BufferedGraphics^ bg, Rectangle con, vector<Obstaculo*> obstaculos) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->getActivo())
				serpientes.at(i)->mover(bg, con, obstaculos);
			else
				serpientes.erase(serpientes.begin() + i);
		}
	}

	void animarLla(BufferedGraphics^ bg, Rectangle con) {
		for (int i = 0; i < flamas.size(); i++) {
			if (flamas.at(i)->getActivo())
				flamas.at(i)->animar(bg, con);
			else
				flamas.erase(flamas.begin() + i);
		}
	}

	bool colBalaSol(Rectangle ajeno) {
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados.at(i)->colBala(ajeno)) return true;
		}
		return false;
	}

	bool colBom(Rectangle ajeno) {
		for (int i = 0; i < bombas.size(); i++) {
			if (bombas.at(i)->Colision(ajeno)) return true;
		}
		return false;
	}

	bool colBalaHel(Rectangle ajeno) {
		for (int i = 0; i < helicopteros.size(); i++) {
			if (helicopteros.at(i)->colBala(ajeno)) return true;
		}
		return false;
	}

	bool colBalaSer(Rectangle ajeno) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->colBala(ajeno)) return true;
		}
		return false;
	}

	bool colSer(Rectangle ajeno) {
		for (int i = 0; i < serpientes.size(); i++) {
			if (serpientes.at(i)->Colision(ajeno)) return true;
		}
		return false;
	}
	void coordsserpent(int fx, int fy) {
		for (int i = 0; i < serpientes.size(); i++) {
			serpientes.at(i)->setfxfy(fx, fy);
		}
	}

	void conAvi(Rectangle ajeno) {
		for (int i = 0; i < aviones.size(); i++) {
			if (aviones.at(i)->Container(ajeno)) {
				crearLla(aviones.at(i)->getx(), aviones.at(i)->gety());
			}
		}
	}

	bool colFla(Rectangle recjg) {
		for (int i = 0; i < flamas.size(); i++) {
			if (flamas.at(i)->Colision(recjg)) return true;
		}
		return false;
	}

	void SeguirMovSoldado(int x, int y) {
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados.at(i)->getEstatico()) {
				soldados.at(i)->apuntarJugador(x,y);
			}
		}
	}

	void dispararSol(int fx, int fy) {
		for (int i = 0; i < soldados.size(); i++) {
			//soldados.at(i)->disparar(fx, fy);
			if (soldados.at(i)->getEstatico()) {
				soldados.at(i)->disparar(fx, fy);
			}
		}		
	}
	void dispararHeli(int fx, int fy) {
		for (int i = 0; i < helicopteros.size(); i++) {
			helicopteros.at(i)->disparar(fx, fy);
		}
	}
	void moverBalasHeli(BufferedGraphics^ bg, Rectangle valido, Jugador* ju){
		for (int i = 0; i < helicopteros.size(); i++) {
			helicopteros.at(i)->moverB(bg,valido);
			if (helicopteros.at(i)->colBala(ju->getHB())) {
				ju->resDano(5);
			}
		}
	}
	void moverBalasSoldado(BufferedGraphics^ bg, Rectangle valido) {
		for (int i = 0; i < soldados.size(); i++) {
			soldados.at(i)->moverB(bg, valido);
		}
	}
	Entidad* getRandomEnem() {
		if (soldados.size() > 0) {
			return soldados.at(0);
		}
		else {
			if (helicopteros.size() > 0) {
				return helicopteros.at(0);
			}
			else {
				if (serpientes.size() > 0) {
					return serpientes[0];
				}
				else {
					return new Entidad(0, 0, 10, 10, 1);
				}
			}
		}
	}

};

