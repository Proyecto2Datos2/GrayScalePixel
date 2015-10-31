/*
 * pistaVillar.h
 *
 *  Created on: Oct 30, 2015
 *      Author: ellioth
 */

#ifndef PISTAVILLAR_H_
#define PISTAVILLAR_H_
#include "Bola.h"
#include "Constantes.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * clase para guardar los datos de la pista de villar
 * e interactuar si se es necesario.
 */
class pistaVillar :public Constantes{
public:
	pistaVillar();
	virtual ~pistaVillar();
private:
	int _bolaBlanca[dos];
	int _bordes[dos];
};

#endif /* PISTAVILLAR_H_ */
