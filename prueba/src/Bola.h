/*
 * Bola.h
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#ifndef BOLA_H_
#define BOLA_H_

#include "Constantes.h"

class Bola: public Constantes{
public:
	Bola(int pPosBB[]);
	virtual ~Bola();
	void setAttr(unsigned short pDireccion,
			unsigned short pFuerza, int pPos[]);
	void correr();
	int * getFitness();
private:
	unsigned short _fuerza;
	unsigned short _angulo;
	int *_fitness;//distancia entre _pos y _posBB.
	int *_pos;//posicion inicial de la bola.
	int *_posBB;//posicion de la bola blanca
};

#endif /* BOLA_H_ */
