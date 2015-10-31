/*
 * Bola.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#include "Bola.h"

/**
 * contructor de la clase, recibe un
 * arreglo que es la posicion de la
 * bola blanca.
 */
Bola::Bola(int pPosBB[]) {
	this->_posBB[cero]=pPosBB[cero];
	this->_posBB[uno]=pPosBB[uno];
}

/**
 * destructor.
 */
Bola::~Bola() {
	delete this;
}

/**
 * funcion que recibe la direccion,
 * la fuerza, y la posicion inicial del
 * individuo.
 */
void Bola::setAttr(unsigned short pDireccion, unsigned short
		pFuerza, unsigned short pPos[]){
	this->_angulo=pDireccion;
	this->_fuerza=pFuerza;
	this->_posI[cero]=pPos[cero];
	this->_posI[uno]=pPos[uno];
}

/**
 * funcion que se utiliza para
 * simular el movimiento de la
 * bola sobre el campo.
 * **INCOMPLETO**
 */
void Bola::correr(){
	_posF[cero]=_posI[cero];
	_posF[uno]=_posI[uno];
	cout<<_angulo<<endl;
	int SumPosX=_fuerza;//*sin(_angulo*(pi/cientoOchenta));
	int SumPosY=_fuerza;//*cos(_angulo*(pi/cientoOchenta));
	for(int i=0; i<(_fuerza*ochenta); i++){
		_posF[cero]+=SumPosX;
		_posF[uno]+=SumPosY;
		if(_posF[cero]==posXPista){
			SumPosX=(-SumPosX);//*cos(_angulo*(pi/cientoOchenta)));
		}
		else if(_posF[cero]==cero){
			SumPosX=(SumPosX);//*cos(_angulo*(pi/cientoOchenta)));
		}
		if(_posF[uno]==posYPista){
			SumPosY=(-SumPosY);//*sin(_angulo*(pi/cientoOchenta)));
		}
		else if(_posF[uno]==cero){
			SumPosY=(SumPosY);//*sin(_angulo*(pi/cientoOchenta)));
		}
		if(_posF[cero]==_posBB[cero]&&_posF[uno]==_posBB[uno]){
			cout<<"se a golpeado la bola blanca"<<endl;
			break;
		}
	}
	int x=pow((_posF[cero]-_posBB[cero]),dos);
	int y=pow((_posF[uno]-_posBB[uno]),dos);
	_fitness=sqrt(x+y);
}

/**
 * metodo que retorna el valor
 * del fitness de la bola.
 */
int Bola::getFitness(){
	return _fitness;
}



