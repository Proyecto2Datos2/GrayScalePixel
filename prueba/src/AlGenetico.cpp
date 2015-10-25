/*
 * AlGenetico.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#include "AlGenetico.h"

AlGenetico::AlGenetico(){
	Bola* poblacionInit=(Bola*)malloc(sizeof(Bola)*poblacionI);
	generar(poblacionInit);
}

AlGenetico::~AlGenetico(){
	for (int i=0; i<poblacionT; i++){
		_poblacion[i]->~Bola();
	}
	delete this;
}

/**
 *
 */
void AlGenetico::generar(Bola* pPoblacionInicial){
	int posBB[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
	for(int i=cero; i<poblacionI;i++){
		unsigned short direcc=(unsigned short)genRand(uno,anguloMax);
		unsigned short fuerza=(unsigned short)genRand(cero,fuerzaMax);
		int pos[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
		pPoblacionInicial= new Bola(posBB);
		pPoblacionInicial->setAttr(direcc,fuerza,pos);
		pPoblacionInicial++;
	}
	pPoblacionInicial-=10;
	/**
	 * for para encliclar hasta alcazar objetivo o maximas generaciones
	 */
	for (int i=cero; i<CantGeneraciones; i++){
		for(int i=cero; i<poblacionI;i++){
			pPoblacionInicial->correr();
			_poblacion[i]=pPoblacionInicial;
			pPoblacionInicial++;
		}
		//condicion para detener el generico por objetivo alcanzado
		if(find())
			break;
		//si no, hacemos una nueva especie y volvemos a iterar
		reproducir();
	}
}

void AlGenetico::reproducir(){
	Bola* temp;
	int fitness[dos]={cero,cero};
	int * fit=TotalFitness(fitness);
	for(int i=0;i<poblacionT;i++){
		int rand= genRand(fit[cero],fit[uno]);

	}
}

int AlGenetico::mutar(){

}

int AlGenetico::intercambiar(){

}

Bola* AlGenetico::getPadre(int fitness[]){

}

int* AlGenetico::TotalFitness(int total[]){
	for(int i=cero; i <poblacionT; i++){
		int *dato=_poblacion[i]->getFitness();
		total[cero]+=dato[cero];
		total[uno]+=dato[uno];
	}
	return total;
}

/**
 *
 */
bool AlGenetico::find(){
	int *fitness=(int*)malloc(sizeof(int)*dos);
	*fitness=mil;*(fitness+1)=mil;
	for(int i=cero; i<poblacionT; i++){
		int* dato=_poblacion[i]->getFitness();
		if(dato[cero]<fitness[cero]||dato[uno]<fitness[uno])
			fitness=dato;
	}
	if(fitness[cero]==cero &&fitness[uno]==cero)
		return true;
	return false;
}
