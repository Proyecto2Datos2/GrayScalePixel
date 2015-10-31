/*
 * pistaVillar.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: ellioth
 */

#include "pistaVillar.h"

pistaVillar::pistaVillar() {
	_bordes[cero]=posXPista;
	_bordes[uno]=posYPista;
	_bolaBlanca[cero]=genRand(cero, _bordes[cero]);
	_bolaBlanca[uno]=genRand(cero, _bordes[uno]);
}

pistaVillar::~pistaVillar() {
	delete []_bordes;
	delete[] _bolaBlanca;
}

