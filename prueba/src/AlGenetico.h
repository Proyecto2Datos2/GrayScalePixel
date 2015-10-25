/*
 * AlGenetico.h
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#ifndef ALGENETICO_H_
#define ALGENETICO_H_
#include "Constantes.h"
#include "Bola.h"
#include <stdio.h>
#include <cstdlib>

using namespace std;
class AlGenetico : public Constantes{
public:
	AlGenetico();
	virtual ~AlGenetico();

private:
	Bola *_poblacion[cinco*dos];
	void generar(Bola *poblacion);
	void reproducir();
	int mutar();
	int intercambiar();
	int* TotalFitness(int total[]);
	bool find();
	Bola* getPadre(int fitness[]);
};

#endif /* ALGENETICO_H_ */
