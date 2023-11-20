#pragma once
class HabitacionS {
private:
	int t_evento;
	Rectangle margen;
	Rectangle borde;
	Rectangle mesa;
	Rectangle estanteria;
	Rectangle papel1;
	Rectangle papel2;
	Rectangle papel3;
	Rectangle papel4;
	Rectangle papel5;
	int indXm, indYm;
	int indXe, indYe;
	bool termino;
public:
	HabitacionS() {
		t_evento = 0;
		//margen = Rectangle(256, 144, 768, 432);
		indXm = indYm = indXe = indYe = 0;
		margen = Rectangle(193, 158, 892, 470);
		borde = Rectangle(0, 0, 1280, 720);
		mesa = Rectangle(222, 120, 420, 110);
		estanteria = Rectangle(789, 66, 250, 170);
		papel1 = Rectangle(613,291,50,40);
		papel2 = Rectangle(490,356,56,40);
		papel3 = Rectangle(579,446,60,40);
		papel4 = Rectangle(697,391,45,36);
		papel5 = Rectangle(881,328,45,35);
		termino = false;
		//geE->crearSer();
	}
	~HabitacionS() {}

	bool verTer() { return termino; }

	//Zona para la creacion de eventos segun el tiempo
	void T_Evento(Jugador* ju) {//añadir jugador
		t_evento++;
		if (t_evento == 400)termino = true;
	}

	Rectangle getMargen() { return margen; }
	Rectangle getBorde() { return borde; }

	void animarFn(BufferedGraphics^ bf) {
		Bitmap^ fondo = gcnew Bitmap("assets/Nivel/cuarto.png");
		Bitmap^ mesaa = gcnew Bitmap("assets/Nivel/mesa.png");
		Rectangle areaMesa = Rectangle(indXm * 420, indYm * 110, 420, 110);
		Rectangle areaEstanteria = Rectangle(indXe * 250, indYe * 170, 250, 170);
		Bitmap^ estanteriaa = gcnew Bitmap("assets/Nivel/estanterua.png");
		bf->Graphics->DrawImage(fondo, borde, borde, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(mesaa, mesa, areaMesa, GraphicsUnit::Pixel);
		bf->Graphics->DrawImage(estanteriaa, estanteria, areaEstanteria, GraphicsUnit::Pixel);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), borde);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), margen);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel1);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel2);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel3);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel4);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), papel5);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), mesa);
		bf->Graphics->DrawRectangle(gcnew Pen(Color::Orange), estanteria);
		delete fondo;
	}

	//Zona en qeu se codifica el comportamiento de los enemigos
	void animarEn(BufferedGraphics^ bf, Jugador* ju) {
		/*geE->animarHel(bf, borde);
		geE->animarLla(bf, borde);
		geE->animarAvi(bf, borde);
		geE->moverBalasHeli(bf, borde, ju);*/
		//geE->animarSer(bf, borde);
	}
};