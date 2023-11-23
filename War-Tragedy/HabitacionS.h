#pragma once
#include "GeObjetosmenu.h"

class HabitacionS {
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	GeObjetosM* geO;
	Rectangle info;
	Rectangle info1;
	Rectangle info2;
	Rectangle info3;
	Rectangle info4;
	Rectangle info5;
	Rectangle info6;
	Rectangle explorar;
	int indXi, indXii, indXn;
	bool termino;
	bool libro;
	Seleccion nivelSeleccionado;

	Rectangle animacion;
	int indXa;
	bool intro;
public:
	HabitacionS() {
		t_evento = 0;


		indXi = indXii = indXn = 0;
		margen = Rectangle(193, 158, 892, 470);
		borde = Rectangle(0, 0, 1280, 720);
		geO = new GeObjetosM();
		info = Rectangle(780, 485, 600 * 0.75, 300 * 0.75);
		info1 = Rectangle(412, 88, 52, 75);
		info2 = Rectangle(894, 94, 52, 75);
		info3 = Rectangle(492, 308, 52, 75);
		info4 = Rectangle(610, 244, 52, 75);
		info5 = Rectangle(702, 336, 52, 75);
		info6 = Rectangle(890, 276, 52, 75);
		explorar = Rectangle(460, 26, 382, 80);
		nivelSeleccionado = geO->getSeleccion();
		intro = true;
		animacion = Rectangle(0, 0, 1280, 720);
		indXa = 0;
		//notas = Rectangle(100,360,200,300);
		//termino = false;
		//geE->crearSer();
	}
	~HabitacionS() {}

	bool verTer() { return termino; }

	GeObjetosM* getgeOb() {
		return geO;
	}
	//Zona para la creacion de eventos segun el tiempo
	void T_Evento(Jugador* ju) {//añadir jugador
		t_evento++;
		if (intro && t_evento >= 1&&indXa<39) {
			indXa++;
		}
		else if (intro && t_evento >= 1 && indXa == 39) {
			indXa = 0;
			t_evento = 0;
			intro = false;
		}
		if (!intro) {
			geO->T_Evento(ju);
			if (t_evento == 1) geO->crearObj();
			//if (t_evento == 1) geO->setIndX(0);
			/*if (t_evento == 400)termino = true;*/
			if (indXi < 60 && t_evento % 1 == 0)indXi++;
			if (indXi < 16)indXn++;
			else if (indXi == 16)indXn = 17;
			if (indXi == 60 && t_evento % 50 == 0)indXi++;
		}

	}

	Seleccion getNivel() { return nivelSeleccionado; }
	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }
	
	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/cuarto.png");
		Bitmap^ infoo = gcnew Bitmap("assets/Nivel/info.png");
		Bitmap^ infonot = gcnew Bitmap("assets/Nivel/exclamacion.png");
		Bitmap^ explorarr = gcnew Bitmap("assets/Nivel/explorar.png");
		Rectangle areainfo = Rectangle(indXi * 600, 0, 600, 300);
		Rectangle areaexclamacion = Rectangle(indXi * 52, 0, 52, 75);
		Rectangle areaexplorar = Rectangle(indXn* 382,0,382,80);
		Rectangle areaintro = Rectangle(indXa* 1280,0,1280,720);
		if (intro) {
			Bitmap^ introo = gcnew Bitmap("assets/Nivel/inicio.png");
			bf->Graphics->DrawImage(introo, animacion, areaintro, GraphicsUnit::Pixel);
			delete introo;
		}
		else {
			bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infoo, info, areainfo, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(explorarr, explorar, areaexplorar, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info1, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info2, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info3, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info4, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info5, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawImage(infonot, info6, areaexclamacion, GraphicsUnit::Pixel);
			bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
			bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);

		}
		
		delete explorarr;
		delete fondo;
		delete infoo;
		delete infonot;
	}


	void animarOb(BufferedGraphics^ bf, Jugador* ju) {

		geO->colisiones(bf,ju);
		
	}
};
/*Rectangle mesa;
Rectangle estanteria;
Rectangle papel1;
Rectangle papel2;
Rectangle papel3;
Rectangle papel4;
Rectangle papel5;
Rectangle cama;
Rectangle info;
Rectangle notas;
int indXm, indYm;
int indXe, indYe;
int indXi, indYi;
int indXn, indYn;
int indXl, indYl;*/


//margen = Rectangle(256, 144, 768, 432);
	//indXm = indYm = indXe = indYe =indYi=indXi= indXn= indYn= indXl= indYl = 0;
//mesa = Rectangle(222, 120, 420, 110);
		//estanteria = Rectangle(789, 66, 250, 170);
		//papel1 = Rectangle(613,291,50,40);
		//papel2 = Rectangle(490,356,56,40);
		//papel3 = Rectangle(579,446,60,40);
		//papel4 = Rectangle(697,391,45,36);
		//papel5 = Rectangle(881,328,45,35);
		//cama = Rectangle(193,428,120,199);
		// 
		// 
//if (geO->getIndX() >= 0 && t_evento < geO->getIndX()) geO->animarr(bf);
		/*Bitmap^ fondo = gcnew Bitmap("assets/Nivel/cuarto2.png");
		Bitmap^ mesaa = gcnew Bitmap("assets/Nivel/mesa.png");
		Bitmap^ notaa = gcnew Bitmap("assets/Nivel/notaspiso.png");
		Rectangle areaMesa = Rectangle(indXm * 420, indYm * 110, 420, 110);
		Rectangle areaEstanteria = Rectangle(indXe * 250, indYe * 170, 250, 170);
		Rectangle areainfo = Rectangle(indXi * 600, indYi * 300, 600, 300);
		Rectangle areanotas = Rectangle(indXn * 200, indYn * 300, 200, 300);
		Bitmap^ estanteriaa = gcnew Bitmap("assets/Nivel/estanterua.png");

		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(mesaa, mesa, areaMesa, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(estanteriaa, estanteria, areaEstanteria, GraphicsUnit::Pixel);

		bf->Graphics->DrawImage(notaa, notas, areanotas, GraphicsUnit::Pixel);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel1);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel2);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel3);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel4);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel5);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), mesa);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), estanteria);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), cama);*/


		//geO->animarr(bf);
				/*geE->animarHel(bf, borde);
				geE->animarLla(bf, borde);
				geE->animarAvi(bf, borde);
				geE->moverBalasHeli(bf, borde, ju);
				geE->animarSer(bf, borde);*/