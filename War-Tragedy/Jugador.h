#pragma once
#include"Entidad.h"
#include"Bala.h"

class Jugador:public Entidad
{
private:
	int chaleco;
	bool dash;
	vector<Bala*> vBala;
	int ammo;
	int t_evento;
	bool danado;

public:
	Jugador(){}
	Jugador(int x,int y):Entidad(x,y,32,48,100){
		indX = 4;
		indY = 2;
		aumento = 1;
		dash = true;
		vel = 8;
		Rx = 10; Ry = 9;
		Rancho = 10;
		Ralto = 28;
		ammo = 50;
		chaleco = 100;
		danado = false;
	}

	~Jugador(){}

	int getchaleco() { return this->chaleco; }
	void setchaleco(int chaleco) { this->chaleco = chaleco; }
	bool getDash() { return dash; }
	void setDash(bool dash) { this->dash = dash; }
	int getbulletsize() { return vBala.size(); }
	Direcciones getDir() { return direccion; }
	Direcciones getUltDir() { return ultDireccion; }
	void setDir(Direcciones dir) { direccion = dir; }
	void setUltDir(Direcciones ultdir) { ultDireccion = ultdir; }


	void animar(BufferedGraphics^ bg, Rectangle rec) {
		Bitmap^ bm = gcnew Bitmap("assets/Personaje/Personaje.png");

		switch (direccion)
		{
		case Ninguna:
			indX = 4;
			indY = 2;
			dx = 0; dy = 0;
			switch (ultDireccion)
			{
			case Abajo:
				indX = 4;
				indY = 2;
				break;
			case Arriba:
				indX = 4;
				indY = 0;
				break;
			case Izquierda:
				indX = 1;
				indY = 1;
				break;
			case Derecha:
				indX = 7;
				indY = 1;
				break;
			case ArrDer:
				indX = 8;
				indY = 0;
				break;
			case ArrIzq:
				indX = 1;
				indY = 0;
				break;
			case AbDer:
				indX = 8;
				indY = 2;
				break;
			case AbIzq:
				indX = 1;
				indY = 2;
				break;
			default:
				break;
			}
			break;
		case Abajo:
			indY = 2;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;

			dx = 0; dy = 1; 
			ultDireccion = Abajo;

			break;
		case Arriba:
			indY = 0;
			if (indX >= 3 && indX < 5) indX++;
			else indX = 3;

			dx = 0; dy = -1;
			ultDireccion = Arriba;
			
			break;
		case Izquierda:
			indY = 1;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;

			dx = -1; dy = 0; 
			ultDireccion = Izquierda;

			break;
		case Derecha:
			indY = 1;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;

			dx = 1; dy = 0;
			ultDireccion = Derecha;

			break;
		case ArrDer:
			indY = 0;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;

			dx = 1; dy = -1;
			ultDireccion = ArrDer;
			
			break;
		case ArrIzq:
			indY = 0;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;

			dx = -1; dy = -1; 
			ultDireccion = ArrIzq;

			break;
		case AbDer:
			indY = 2;
			if (indX >= 6 && indX < 8) indX++;
			else indX = 7;

			dx = 1; dy = 1; 
			ultDireccion = AbDer;
			
			break;
		case AbIzq:
			indY = 2;
			if (indX >= 0 && indX < 2) indX++;
			else indX = 0;
			
			dx = -1; dy = 1; 
			ultDireccion = AbIzq;
			
			break;

		case Dash: // nose como arreglar pipipi //podemos hacer q muera cuando se sale para no tener q corregir nada xdxdxdxdxdxdxdxdxdxdxd
			switch (ultDireccion) {
			case Arriba:
				if (!Container(rec)) {
					vida = -1;
					//dead or smth
				}
				else {
					y -= alto * 2;
					ultDireccion = Arriba;
				}
				break;
			case Abajo:
				if (!Container(rec)) {
					vida = -1;
					//dead or smth
				}
				else {
					y += alto * 2;
					ultDireccion = Abajo;
				}
				break;
			case Derecha:
				if (!Container(rec)){
					vida = -1;
					//dead or smth
				}
				else {
					x += ancho * 2;
					ultDireccion = Derecha;
				}
				break;
			case Izquierda:
				if (!Container(rec)) {
					vida = -1;
					//dead or smth
				}
				else {
					x -= ancho * 2;
					ultDireccion = Izquierda;
				}
				break;
			}
		
		}
		
		dibujar(bg, bm);
		mover(rec);
		delete bm;
	}

	void mover(Rectangle rec) {
		if (Container(rec)) {
			if (danado)	{
				x += dx * vel * -1.5;
				y += dy * vel * -1.5;
			}else{
				x += dx * vel;
				y += dy * vel;
			}
			danado = false;
		}
		
	}

	void Dano() { danado = true; }

	void disparar(int fx, int fy) {
		if (ammo > 0) {
			Bala* oBala = new Bala(x, y, fx, fy);
			oBala->setRnRl(10, 10);
			vBala.push_back(oBala);
			ammo--;
		}		
	}

	void moverB(BufferedGraphics^ bg, Rectangle rec) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->Container(rec)) vBala.at(i)->mover(bg);
			else vBala.erase(vBala.begin() + i);
		}
	}

	void masBalas() {
		ammo += 30;
	}

	bool colBala(Rectangle objetivo) {
		for (int i = 0; i < vBala.size(); i++) {
			if (vBala.at(i)->colBal(objetivo)) return true;
		}
		return false;
	}


};
