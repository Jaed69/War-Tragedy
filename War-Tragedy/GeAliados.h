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
	GeAliado() {
		t_evento = 0;
	}
	~GeAliado() {}

	void T_Evento(Jugador* ju, Rectangle margen) {
		t_evento++;
		//colision de kami está en mover porqye no tiene sentido que no esté ahi para que haga daño a la entidad
		if (t_evento == 5) {
			crearRandomPower(margen);
		}
		if (t_evento % 50 == 0) {
			crearRandomPower(margen);
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
	void crearBanana(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X+margen.Width), r.Next(margen.Y, margen.Y + margen.Height), banana);//poner random x y
		Powers.push_back(pow);
	}
	void crearBotiquin(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X + margen.Width), r.Next(margen.Y, margen.Y + margen.Height), botiquin);
		Powers.push_back(pow);
	}
	void crearArmadura(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X + margen.Width), r.Next(margen.Y, margen.Y + margen.Height), armadura);
		Powers.push_back(pow);

	}
	void crearRadio(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X + margen.Width), r.Next(margen.Y, margen.Y + margen.Height), radio);
		Powers.push_back(pow);
	}
	void crearArma(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X + margen.Width), r.Next(margen.Y, margen.Y + margen.Height), arma);
		Powers.push_back(pow);
	}
	void crearAmmo(Rectangle margen) {
		Random r;
		Power* pow = new Power(r.Next(margen.X, margen.X + margen.Width), r.Next(margen.Y, margen.Y + margen.Height), municion);
		Powers.push_back(pow);
	}
	void crearRandomPower(Rectangle margen) {
		Random randi;
		switch (randi.Next(1, 8))
		{
		case 1:
			crearAmmo(margen);
			break;
		case 2:
			crearArma(margen);
			break;
		case 3:
			crearArmadura(margen);
			break;
		case 4:
			crearBanana(margen);
			break;
		case 5:
			crearBotiquin(margen);
			break;
		case 6:
			crearRadio(margen);
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
		if (Kamis.size() > 0) {
			if (colKami(enem->getFHB())) {
				enem->resDano(20);
			}
		}
		for (int i = 0; i < Kamis.size(); i++) {
			if (Kamis.at(i)->getActivo()) {
				Kamis.at(i)->mover(enem, bg);
			}
			else {
				Kamis.erase(Kamis.begin() + i);
			}
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
				if (Kamis.at(i)->Colision(ajeno)) {
					Kamis.at(i)->setActivo(false);
					return true;
				}
				else return false;
			}
		
	}

	void DispararMono() {
		Random r;
		for (int i = 0; i < Monos.size(); i++) {
			if (Monos.at(i)->getModoDisparar()) {
				Monos.at(i)->disparar(r.Next(1280), r.Next(720));
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
					//agregar velocida de disparo o mas daño nose
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