/*
 * Constantes.h
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * archivo de constantes para usar en el proyecto
 */
class Constantes {
public:
	//cero=0
	static const int cero=0;
	//uno=1
	static const int uno=1;
	//dos=2
	static const int dos=2;
	//cuatro=4
	static const int cuatro=4;
	//cinco=5
	static const int cinco=5;
	//diez=10
	static const int diez=10;
	//cien=100
	static const int cien=100;
	//ochenta=80
	static const int ochenta=80;
	//cientoOchenta=180
	static const int cientoOchenta=180;
	//mil=1000
	static const int mil=1000;
	//pi=3.1415
	static const double pi=3.1415;
	//poblacionT=10;
	static const int poblacionT=10;
	//posXPista=550;
	static const int posXPista=550;
	//posYPista=500;
	static const int posYPista=500;
	//anguloMax=360
	static const int anguloMax=360;
	//fuerzaMax=10
	static const int fuerzaMax=10;
	//CantGeneraciones=50
	static const int CantGeneraciones=50;
	int genRand(int lowBound, int highBound);

};

#endif /* CONSTANTES_H_ */
