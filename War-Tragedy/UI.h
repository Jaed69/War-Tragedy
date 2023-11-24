#pragma once
using namespace System::Drawing;

class UI {
private:
	int anchoVida, altoVida;
	int anchoChaleco, altoChaleco;
	int indXv, indYv;
	int indXc, indYc;
	int xv, yv, xc, yc;
public:
	UI() {
		anchoVida = 96; altoVida = 96;
		altoChaleco = 96; anchoChaleco = 192;
		indXv = 10; indYv = 0;
		indXc = 7; indYc = 2;
		xv = 10;  xc = 100; yv = 5; yc = 5;
	}
	~UI() {}

	void movVida(BufferedGraphics^ bg, int vida) {
		if (vida == 100) indXv = 10;
		if (vida < 100 && vida >= 90)indXv = 9;
		if (vida < 90 && vida >= 75)indXv = 8;
		if (vida < 75 && vida >= 65)indXv = 7;
		if (vida < 65 && vida >= 50)indXv = 6;
		if (vida < 50 && vida >= 37)indXv = 5;
		if (vida < 37 && vida >= 25)indXv = 4;
		if (vida < 25 && vida >= 12)indXv = 3;
		if (vida < 12 && vida > 0)indXv = 2;
		if (vida <= 0) indXv = 1;
		DibujarVida(bg, vida);
	}

	void DibujarVida(BufferedGraphics^ bg, int vida) {
		Bitmap^ vidaa = gcnew Bitmap("assets/UI/Vida.png");
		Rectangle area = Rectangle(indXv * anchoVida, indYv * altoVida, anchoVida, altoVida);
		Rectangle zonaAumento = Rectangle(xv, yv, anchoVida, altoVida);
		bg->Graphics->DrawImage(vidaa, zonaAumento, area, GraphicsUnit::Pixel);
		delete vidaa;
	}

	void movChaleco(BufferedGraphics^ bg, int Chaleco) {
		if (Chaleco == 100)indXc = 7; indYc = 2;
		if (Chaleco == 0)indXc = 1; indYc = 0;
		if (Chaleco < 100 && Chaleco >= 94)indXc = 2; indYc = 0;
		if (Chaleco < 94 && Chaleco >= 90)indXc = 3; indYc = 0;
		if (Chaleco < 90 && Chaleco >= 86)indXc = 4; indYc = 0;
		if (Chaleco < 86 && Chaleco >= 82)indXc = 5; indYc = 0;
		if (Chaleco < 82 && Chaleco >= 78)indXc = 6; indYc = 0;
		if (Chaleco < 78 && Chaleco >= 74)indXc = 7; indYc = 0;
		if (Chaleco < 74 && Chaleco >= 72)indXc = 8; indYc = 0;
		if (Chaleco < 72 && Chaleco >= 68)indXc = 9; indYc = 0;
		if (Chaleco < 68 && Chaleco >= 64)indXc = 0; indYc = 1;
		if (Chaleco < 64 && Chaleco >= 60)indXc = 1; indYc = 1;
		if (Chaleco < 60 && Chaleco >= 56)indXc = 2; indYc = 1;
		if (Chaleco < 56 && Chaleco >= 52)indXc = 3; indYc = 1;
		if (Chaleco < 52 && Chaleco >= 48)indXc = 4; indYc = 1;
		if (Chaleco < 48 && Chaleco >= 44)indXc = 5; indYc = 1;
		if (Chaleco < 44 && Chaleco >= 40)indXc = 6; indYc = 1;
		if (Chaleco < 40 && Chaleco >= 36)indXc = 7; indYc = 1;
		if (Chaleco < 36 && Chaleco >= 32)indXc = 8; indYc = 1;
		if (Chaleco < 32 && Chaleco >= 28)indXc = 9; indYc = 1;
		if (Chaleco < 28 && Chaleco >= 24)indXc = 0; indYc = 2;
		if (Chaleco < 24 && Chaleco >= 20)indXc = 1; indYc = 2;
		if (Chaleco < 20 && Chaleco >= 16)indXc = 2; indYc = 2;
		if (Chaleco < 16 && Chaleco >= 12)indXc = 3; indYc = 2;
		if (Chaleco < 12 && Chaleco >= 8)indXc = 4; indYc = 2;
		if (Chaleco < 8 && Chaleco >= 4)indXc = 5; indYc = 2;
		if (Chaleco < 4 && Chaleco >0)indXc = 6; indYc = 2;
		/*if (Chaleco == 100) {
			indXc == 7; indYc = 2;
		}
		if (Chaleco >= 97 && Chaleco <= 99) {
			indXc == 6; indYc = 2;
		}
		if (Chaleco < 100 && Chaleco % 4 == 0) {
			if (indXc > 0) {
				indXc--;
			}
			else if (indYc > 0 && indXc >= 1) {
				indXc = 9;
				indYc--;
			}
		}
		if (Chaleco <= 0) {
			indXc = 1; indYc = 0;
		}*/
		DibujarChaleco(bg, Chaleco);
	}

	void DibujarChaleco(BufferedGraphics^ bg, int chaleco) {
		Bitmap^ chalecoo = gcnew Bitmap("assets/UI/Escudo.png");
		Rectangle area = Rectangle(indXc * anchoChaleco, indYc * altoChaleco, anchoChaleco, altoChaleco);
		Rectangle zonaAumento = Rectangle(xc, yc, anchoChaleco, altoChaleco);
		bg->Graphics->DrawImage(chalecoo, zonaAumento, area, GraphicsUnit::Pixel);
		delete chalecoo;
	}
};