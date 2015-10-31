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
#include <ctime>
#include <cstdlib>

using namespace std;
/**
 * clase para inicializar el algoritmo
 * genetico.
 */
class AlGenetico : public Constantes{
public:
	AlGenetico();
	virtual ~AlGenetico();

private:
	Bola *_poblacion[poblacionT];
	int _generaciones;
	void ejecutar(Bola *poblacion[]);
	void reproducir();
	void mutar(Bola* padre1, Bola* padre2,Bola* hijo);
	void intercambiar(Bola* padre1, Bola* padre2,Bola* hijo);
	int TotalFit();
	bool find();
	Bola* getPadre(int fitness, int padres[]);
	void getPosPadres(int padres[]);
	void merge(Bola* hijos[]);
	void insertSort(Bola* individuos[]);
};

#endif /* ALGENETICO_H_ */
