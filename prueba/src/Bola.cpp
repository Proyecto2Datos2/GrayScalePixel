/*
 * Bola.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#include "Bola.h"

Bola::Bola(int pPosBB[]) {
	this->_posBB=pPosBB;
}

Bola::~Bola() {
	delete this;
}
void Bola::setAttr(unsigned short pDireccion, unsigned short
		pFuerza, int pPos[]){
	this->_angulo=pDireccion;
	this->_fuerza=pFuerza;
	this->_pos=pPos;
}

void Bola::correr(){
	//aqui se va a simular el movimiento de la bola por el campo.
	//aca calculamos el fitness, que es la distancia entre la bola
	//blanca y esta bola.
}

int *Bola::getFitness(){
	return _fitness;
}


