#pragma once
#include "objetosmenu.h"

class GeObjetosM {
private:
	int t_evento;
	vector<objetosMenu*>obj;
	int indXlibro;
	int indX;
	Seleccion seleccion;
public:
	GeObjetosM() {
		t_evento = 0;
		indXlibro = 0;
		indX = 0;
		seleccion = ninguna;
	}
	~GeObjetosM(){}

	void T_Evento(Jugador* ju) {
		t_evento++; 
	}

	void setseleccion(Seleccion seleccion) { this->seleccion = seleccion; }
	Seleccion getSeleccion() { return seleccion; }

	void setIndX(int indX) { this->indX = indX; }
	int getIndX() { return indX; }

	void crearObj() {
		objetosMenu* estan = new objetosMenu(789, 66, estanteria);
		objetosMenu* mesaa = new objetosMenu(222, 120, mesa);
		objetosMenu* paapel1 = new objetosMenu(613, 291, papel1);
		objetosMenu* paapel2 = new objetosMenu(490, 356, papel2);
		objetosMenu* paapel3 = new objetosMenu(697, 391, papel3);
		objetosMenu* paapel4 = new objetosMenu(881, 328, papel4);
		obj.push_back(estan);
		obj.push_back(mesaa);
		obj.push_back(paapel1);
		obj.push_back(paapel2);
		obj.push_back(paapel3);
		obj.push_back(paapel4);
	}
	void animarnotitas(BufferedGraphics^ bf, int i) {
		Bitmap^ notaa = gcnew Bitmap("assets/Nivel/papel.png");
		Rectangle areanotas = Rectangle(i * 366,0, 366, 414);
		Rectangle notas = Rectangle(100, 360, 366*0.75, 0.75*414);
		bf->Graphics->DrawImage(notaa, notas, areanotas, GraphicsUnit::Pixel);
		delete notaa;

	}
	void animarlibro(BufferedGraphics^ bg, int i) {
		/*if (indXlibro < 16)indXlibro += 1;*/
		Bitmap^ libroro = gcnew Bitmap("assets/Nivel/libro.png");
		Rectangle arealibro = Rectangle(i * 800, 0, 800, 400);
		Rectangle libror = Rectangle(230, 290, 800, 400); 
		bg->Graphics->DrawImage(libroro, libror, arealibro, GraphicsUnit::Pixel);
		delete libroro;
	}

	void animarr(BufferedGraphics^ bg) {
		Bitmap^ general = gcnew Bitmap("assets/Nivel/papeles2.png");
		Rectangle areaG = Rectangle(indX * 1280, 0, 1280, 720);
		Rectangle aumento = Rectangle(0, 0, 1280, 720);
		bg->Graphics->DrawImage(general, aumento, areaG, GraphicsUnit::Pixel);
	}
	objM colisionmenu(Jugador* ju) {
		for (int i = 0; i < obj.size(); i++) {
			if (obj.at(i)->Colision(ju->getFHB())) {
				if (obj.at(i)->getTipo() == estanteria) {
					return estanteria;
				}
				if (obj.at(i)->getTipo() == mesa) {
					return mesa;
				}
				if (obj.at(i)->getTipo() == papel1) {
					return papel1;
				}
				if (obj.at(i)->getTipo() == papel2) {
					return papel2;
				}
				if (obj.at(i)->getTipo() == papel3) {
					return papel3;

				}
				if (obj.at(i)->getTipo() == papel4) {
					return papel4;

				}
			}
			else
				seleccion = ninguna;
		}
	}


	void colisiones(BufferedGraphics^bg, Jugador*ju) {
		for (int i = 0; i < obj.size(); i++) {
			if (obj.at(i)->Colision(ju->getFHB())) {
				if (obj.at(i)->getTipo() == estanteria) {
					animarlibro(bg, 1);
				}
				if (obj.at(i)->getTipo() == mesa) {
					animarlibro(bg, 2);
					seleccion = partidaG;
				}
				if (obj.at(i)->getTipo() == papel1) {
					animarnotitas(bg, 0);
				}
				if (obj.at(i)->getTipo() == papel2) {
					animarnotitas(bg, 1);
					seleccion = nnivel1;
				}
				if (obj.at(i)->getTipo() == papel3) {
					animarnotitas(bg, 2);
					seleccion = nnivel2;

				}
				if (obj.at(i)->getTipo() == papel4) {
					animarnotitas(bg, 3);
					seleccion = nnivel3;

				}
			}
			else
				seleccion = ninguna;
			obj.at(i)->dibujarr(bg);
		}

	}
};