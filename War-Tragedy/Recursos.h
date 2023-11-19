#pragma once
#include<vector>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha, ArrDer, ArrIzq, AbDer, AbIzq, Dash };
enum Niveles { NTejado, NEdificio, NPrado, FinalM, FinalB, FinalBS, FinalMS };