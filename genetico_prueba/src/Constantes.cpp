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
	srand(time(0));
	return rand()%(highBound-lowBound+1)+lowBound;
}

/**
 * metodo para establecer en un arreglo de bits un numero.
 */
void Constantes::SetBits( unsigned short A[], unsigned short number){
	int k, c;
	for (c = 15; c >= 0; c--){
		k = number>>c;
		if (k & 1)
			A[c/16] |= 1 << (c%16);
		else
			A[k/16] |= 0 << (k%16);
	}

}

/**
 * metodo para borrar un numero en espeficico en un arreglo de bits
 */
void Constantes::ClearBit( unsigned short A[],  int k ){
   A[k/16] &= ~(1 << (k%16)) ;
}

/**
 * metodo para obtener un true o false si el numero esta en un
 * arreglo de bits.
 */
int Constantes::getBit( unsigned short A[],  int k ){
   return ( (A[k/16] & (1 << (k%16) )) != 0 ) ;  // Return TRUE if bit set
}
