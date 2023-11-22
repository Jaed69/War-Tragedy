#pragma once
#include "objetosmenu.h"
class GeObjetosM {
private:
	int t_evento;
	vector<objetosMenu*>obj;
	int indXlibro;
public:
	GeObjetosM() {
		t_evento = 0;
		indXlibro = 0;
	}
	~GeObjetosM(){}

	void T_Evento(Jugador* ju) {
		t_evento++;
	}

	void crearObj() {
		objetosMenu* estan = new objetosMenu(789, 66, estanteria);
		objetosMenu* mesaa = new objetosMenu(222, 120, mesa);
		objetosMenu* paapel1 = new objetosMenu(613, 291, papel1);
		objetosMenu* paapel2 = new objetosMenu(490, 356, papel2);
		objetosMenu* paapel3 = new objetosMenu(579, 446, papel3);
		objetosMenu* paapel4 = new objetosMenu(697, 391, papel4);
		objetosMenu* paapel5 = new objetosMenu(881, 328, papel5);
		obj.push_back(estan);
		obj.push_back(mesaa);
		obj.push_back(paapel1);
		obj.push_back(paapel2);
		obj.push_back(paapel3);
		obj.push_back(paapel4);
		obj.push_back(paapel5);
	}
	void animarlibro(BufferedGraphics^ bg) {
		if (indXlibro < 16)indXlibro += 1;
		Bitmap^ libroro = gcnew Bitmap("assets/Nivel/librooo.png");
		Rectangle arealibro = Rectangle(indXlibro * 1280, 0, 1280, 720);
		Rectangle libror = Rectangle(1, 1, 1280, 720);
		bg->Graphics->DrawImage(libroro, libror, arealibro, GraphicsUnit::Pixel);
		delete libroro;
	}
	void colisiones(BufferedGraphics^bg, Jugador*ju) {
		for (int i = 0; i < obj.size(); i++) {
			if (obj.at(i)->Colision(ju->getFHB())) {
				if (obj.at(i)->getTipo() == estanteria) {
					ju->setdx(0);
					ju->setdy(0);
					animarlibro(bg);
				}
				if (obj.at(i)->getTipo() == mesa) {
					ju->setdx(0);
					ju->setdy(0);
				}
				if (obj.at(i)->getTipo() == papel1) {

				}
				if (obj.at(i)->getTipo() == papel2) {

				}
				if (obj.at(i)->getTipo() == papel3) {

				}
				if (obj.at(i)->getTipo() == papel4) {

				}
				if (obj.at(i)->getTipo() == papel5) {

				}
			}
			obj.at(i)->dibujarr(bg);
		}

	}
};