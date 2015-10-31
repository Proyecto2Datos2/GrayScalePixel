/*
 * Constantes.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#include "Constantes.h"

/**
 * metodo que retorna un dato random entre dos limites,
 * incluye los limites.
 */
int Constantes::genRand(int lowBound, int highBound){
	time_t t;
	time(&t);
	srand((unsigned int)t);
	return rand()%(highBound-lowBound+1)+lowBound;
}
