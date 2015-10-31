//============================================================================
// Name        : genetico_prueba.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include "Bola.h"
#define ClearBit(A,k)   ( A[(k/16)] &= ~(1 << (k%16)) )
#define TestBit(A,k)    ( A[(k/16)] & (1 << (k%16)) )

using namespace std;

static const int cero=0;
static const int uno=1;
static const int dos=2;
static const int diez=10;
static const int poblacionI=10;
static const int posXPista=550;
static const int posYPista=500;
static const int anguloMax=360;
static const int fuerzaMax=10;

/**
 * metodo para generar numeros random entre
 * un intervalo.
 */
int genRand(int lowBound, int highBound){
	return rand()%(highBound-lowBound+1)+lowBound;
}

void SetBit(unsigned short A[],unsigned short number){
	int k, c;
	for (c = 15; c>=0; c--){
		k = number>>c;
		if (k & 1){
			cout<<"1";
			A[c/16] |= 1 << (c%16);
		}
		else{
			cout<<"0";
			A[c/16] |= 0 << (c%16);
		}
	}
	cout<<endl;
}
/**
 * metodo para ordenar los individuos de menor a mayor
 * segun su fitness, se escojen los menores, ya que
 * la funcion utilizada es de distancia, mientra sea
 * menor el numero, mejor su fitness.
 */
void insertSort(Bola* individuos[]){
	for (int i=uno;i<poblacionI; i++){
		Bola* bolaTemp=individuos[i];
		int j=i;
		for(; j>cero && ((bolaTemp->getFitness())<
				(individuos[j-uno]->getFitness()));j--)
			individuos[j]=individuos[j-uno];
		individuos[j]=bolaTemp;
	}
}

/**
 * metodo para correr el algoritmo, genetico
 * **este es de prueba y solo se esta utilizando
 * con un generacion**
 */
void correr(Bola* poblacion[]){
	srand(time(0));
	//posicion de la bola blanca.
	int posBB[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
	unsigned short direcc;
	unsigned short fuerza;
	unsigned short pos[dos];
	//ciclo para crear cada uno de los individuos iniciales.
	for(int i=cero; i<poblacionI;i++){
		direcc=genRand(uno,anguloMax);fuerza=genRand(cero,fuerzaMax);
		pos[cero]=genRand(cero,posXPista);pos[uno]=genRand(cero,posYPista);
		poblacion[i]= new Bola(posBB);
		poblacion[i]->setAttr(direcc,fuerza,pos);
	}
	/**
	 * -el primer ciclio inicializa la sumulacion de movimiento en
	 * 	campo.
	 * -el insertSort los ordena segun su fitness.
	 * -el ultimo ciclio es un debug para ver como quedo el
	 * 	ordenamiento.
	 */
	for(int j=cero;j<poblacionI;j++){
		poblacion[j]->correr();
	}
	insertSort(poblacion);
	for(int x=0; x<poblacionI; x++){
		cout<<"fitness"<<x<<":"<<poblacion[x]->getFitness()<<endl;
	}

}

int main(int argc, char** argv){
	//creo un arreglo de puntero para los primero diez individuos.
	//Bola* _poblacion[diez];
	/*srand(time(0));
	int posBB[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
	unsigned short direcc=genRand(cero, anguloMax);
	unsigned short fuerza=genRand(cero, fuerzaMax);
	unsigned short pos[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
	Bola* individuo=new Bola(posBB);
	individuo->setAttr(direcc,fuerza, pos);
	individuo->correr();
	correr(_poblacion);*/
	unsigned short arreglo[1]={0};
	SetBit(arreglo,10000);
	for(int i=0; i<16;i++){
		if(TestBit(arreglo,i))
			cout<<"Bit %d was set !\n"<<i<<endl;
	}
	//cout << individuo->getFitness() << endl; // prints !!!Hello World!!!
	return 0;
}
