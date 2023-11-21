#pragma once
#include<vector>
#include "conio.h"
#include "iostream"
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha, ArrDer, ArrIzq, AbDer, AbIzq, Dash };
enum Niveles { NTejado, NEdificio, NPrado, FinalM, FinalB, FinalBS, FinalMS, habitacionS };

struct Datos
{
	int vida;
	int armadura;
	int X, Y;
	int nivel;
	int direcion;
	int ultdireccion;
	int t_evento;
};