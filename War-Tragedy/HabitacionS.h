#pragma once
#include "GeObjetosmenu.h"
#include "Archivo.h"
class HabitacionS {
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	GeObjetosM* geO;
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
	bool termino;
	bool libro;
public:
	HabitacionS() {
		t_evento = 0;
		//margen = Rectangle(256, 144, 768, 432);
		//indXm = indYm = indXe = indYe =indYi=indXi= indXn= indYn= indXl= indYl = 0;
		margen = Rectangle(193, 158, 892, 470);
		borde = Rectangle(0, 0, 1280, 720);
		geO = new GeObjetosM();
		//mesa = Rectangle(222, 120, 420, 110);
		//estanteria = Rectangle(789, 66, 250, 170);
		//papel1 = Rectangle(613,291,50,40);
		//papel2 = Rectangle(490,356,56,40);
		//papel3 = Rectangle(579,446,60,40);
		//papel4 = Rectangle(697,391,45,36);
		//papel5 = Rectangle(881,328,45,35);
		//cama = Rectangle(193,428,120,199);
		//info = Rectangle(780, 485, 600*0.75, 300*0.75);
		//notas = Rectangle(100,360,200,300);
		//termino = false;
		//geE->crearSer();
	}
	~HabitacionS() {}

	bool verTer() { return termino; }

	//Zona para la creacion de eventos segun el tiempo
	void T_Evento(Jugador* ju) {//añadir jugador
		t_evento++;
		geO->T_Evento(ju);		
		if (t_evento == 1) geO->crearObj();
		//if (t_evento == 1) geO->setIndX(0);
		/*if (t_evento == 400)termino = true;
		if (indXi < 60 && t_evento % 1 == 0)indXi++;
		if (indXi == 60 && t_evento % 50 == 0)indXi++;*/

	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }
	
	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/cuarto3.png");
		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		//if (geO->getIndX() >= 0 && t_evento < geO->getIndX()) geO->animarr(bf);
		/*Bitmap^ fondo = gcnew Bitmap("assets/Nivel/cuarto2.png");
		Bitmap^ mesaa = gcnew Bitmap("assets/Nivel/mesa.png");
		Bitmap^ notaa = gcnew Bitmap("assets/Nivel/notaspiso.png");
		Rectangle areaMesa = Rectangle(indXm * 420, indYm * 110, 420, 110);
		Rectangle areaEstanteria = Rectangle(indXe * 250, indYe * 170, 250, 170);
		Rectangle areainfo = Rectangle(indXi * 600, indYi * 300, 600, 300);
		Rectangle areanotas = Rectangle(indXn * 200, indYn * 300, 200, 300);
		Bitmap^ estanteriaa = gcnew Bitmap("assets/Nivel/estanterua.png");
		Bitmap^ infoo = gcnew Bitmap("assets/Nivel/info.png");
		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(mesaa, mesa, areaMesa, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(estanteriaa, estanteria, areaEstanteria, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(infoo, info, areainfo, GraphicsUnit::Pixel);
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
		delete fondo;
		/*delete mesaa;
		delete notaa;
		delete areaMesa;
		delete areaEstanteria;
		delete areainfo;
		delete areanotas;
		delete estanteriaa;
		delete infoo;*/
	}


	void animarOb(BufferedGraphics^ bf, Jugador* ju) {

		geO->colisiones(bf,ju);
		/*geE->animarHel(bf, borde);
		geE->animarLla(bf, borde);
		geE->animarAvi(bf, borde);
		geE->moverBalasHeli(bf, borde, ju);
		geE->animarSer(bf, borde);*/
	}
};