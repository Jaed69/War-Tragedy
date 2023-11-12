#pragma once
#include "Entidad.h"
#include "mono.h"
#include "Bala.h"
#include <vector>
class GeAliado {
private:
	int contador;

public:
	GeAliado(){
		contador = 0;
	}
	~GeAliado(){}

	void sumCont() {
		contador += 1;
	}

};