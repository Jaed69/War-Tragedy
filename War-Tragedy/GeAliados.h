#pragma once
#include "Mono.h"
#include "AvionAliado.h"
#include "Power.h"
#include "Kami.h"
#include "GeEnemigos.h"
class GeAliado {
private:
	int t_evento;
	vector<Mono*>Monos;
	vector<AvionAliado*> Aliados;
	vector<Power*> Powers;
	vector<Kami*> Kamis;

public:
	GeAliado(){
		t_evento = 0;
		crearRandomPower();

	}
	~GeAliado(){}

	void T_Evento(Jugador* ju) {
		t_evento++;
		//agregar colision de kami
		if (t_evento % 50 == 0) {
			crearRandomPower();
		}
		colPUp(ju);

	}

	void crearMon() {
		Mono* mono = new Mono(260, 210);
		Monos.push_back(mono);
	}
	void crearAvi() {
		AvionAliado* avi = new AvionAliado(100, 0);
		Aliados.push_back(avi);
	}
	void crearBanana() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), banana);//poner random x y
		Powers.push_back(pow);
	}
	void crearBotiquin() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), botiquin);//poner random x y
		Powers.push_back(pow);
	}
	void crearArmadura() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), armadura);//poner random x y
		Powers.push_back(pow);

	}
	void crearRadio() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), radio);//poner random x y
		Powers.push_back(pow);
	}
	void crearArma() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), arma);//poner random x y
		Powers.push_back(pow);
	}
	void crearAmmo() {
		Random r;
		Power* pow = new Power(r.Next(256, 1020), r.Next(176, 608), municion);//poner random x y
		Powers.push_back(pow);
	}
	void crearRandomPower() {
		Random randi;
		switch (randi.Next(1,8))
		{
		case 1:
			crearAmmo();
			break;
		case 2:
			crearArma();
			break;
		case 3:
			crearArmadura();
			break;
		case 4:
			crearBanana();
			break;
		case 5:
			crearBotiquin();
			break;
		case 6:
			crearRadio();
			break;
		default:
			break;
		}
	}
	void crearKami() {
		Kami* k = new Kami(0, 0);
		Kamis.push_back(k);
	}

	void moverKami(Entidad* enem, BufferedGraphics^ bg) {
		for (int i = 0; i < Kamis.size(); i++) {
			Kamis.at(i)->mover(enem, bg);
		}
	}
	void animarpUp(BufferedGraphics^ bg) {
		for (int i = 0; i < Powers.size(); i++) {
			if (Powers.at(i)->getActivo()) {
				Powers.at(i)->mover(bg);
			}
			else {
				Powers.erase(Powers.begin() + i);
			}
		}
	}

	void moverMono(BufferedGraphics^ bg, Rectangle espacio) {
		for (int i = 0; i < Monos.size(); i++) {
			Monos.at(i)->mover(bg, espacio);
		}
	}
	void moverAvion(BufferedGraphics^ bg, Rectangle aviE, Rectangle balaE) {
		for (int i = 0; i < Aliados.size(); i++) {
			Aliados.at(i)->mover(bg, aviE);
			if (t_evento % 8 == 0) {
				Aliados.at(i)->disparar();
			}
			Aliados.at(i)->moverB(bg, balaE);
		}			
	}
	bool colKami(Rectangle ajeno) {
		for (int i = 0; i < Kamis.size(); i++) {
			if (Kamis.at(i)->Colision(ajeno)) return true;
			else return false;
		}
	}

	void DispararMono() {
		Random r;
		for (int i = 0; i < Monos.size(); i++) {
			if (Monos.at(i)->getModoDisparar()) {
				Monos.at(i)->disparar(r.Next(1280),r.Next(720));
			}
		}
	}
	void colPUp(Jugador* ju) {
		for (int i = 0; i < Powers.size(); i++) {
			if (Powers.at(i)->Colision(ju->getFHB())) {
				Powers.at(i)->setActivo(false);
				switch (Powers.at(i)->gettype())
				{
				case banana:
					crearMon();
					break;
				case botiquin:
					ju->setvida(ju->getvida() + 1);//corregir puede
					break;
				case arma:
					//agregar velocida de disparo
					break;
				case armadura:
					ju->setchaleco(ju->getchaleco() + 1);
					//agregar mas armor
					break;
				case radio:
					crearKami();
					break;
				case municion:
					ju->masBalas();
					break;
				default:
					break;
				}

			}
		}
	}

};