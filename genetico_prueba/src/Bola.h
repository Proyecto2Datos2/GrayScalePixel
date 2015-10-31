/*
 * Bola.h
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#ifndef BOLA_H_
#define BOLA_H_

#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include "Constantes.h"

using namespace std;

/**
 * clase de bola para crear los individuos que va a utilizarse.
 */
class Bola: public Constantes{
public:
	Bola(int pPosBB[]);
	virtual ~Bola();
	void setAttr(unsigned short pDireccion,
			unsigned short pFuerza, unsigned short pPos[]);
	void correr();
	int getFitness();
private:
	unsigned short _fuerza;
	unsigned short _angulo;
	unsigned short _posI[dos];//posicion inicial de la bola.
	unsigned short _posF[dos];//posicion inicial de la bola.
	int _fitness;//distancia entre _pos y _posBB.
	int _posBB[dos];//posicion de la bola blanca
};

#endif /* BOLA_H_ */
