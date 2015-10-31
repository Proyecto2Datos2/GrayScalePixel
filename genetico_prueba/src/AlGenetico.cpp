/*
 * AlGenetico.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: ellioth
 */

#include "AlGenetico.h"

/**
 * contructor de la clase, no recibe nada,
 * incializa automaticamente el genetico.
 */
AlGenetico::AlGenetico(){
	this->_generaciones=cero;
	ejecutar(_poblacion);
}

/**
 * destructor del genetico
 */
AlGenetico::~AlGenetico(){
	for (int i=0; i<poblacionT; i++){
		_poblacion[i]->~Bola();
	}
	delete this;
}

/**
 * metodo que es el run de algoritmo, este metodo incializa todo
 * crea la primera generacion y las pone a reproducirse.
 * recibe un arreglo de donde vamos a guardar los primeros
 * individuos.
 */
void AlGenetico::ejecutar(Bola* pPoblacionInicial[]){
	srand(time(0));
	//creacion de la bola blanca
	int posBB[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
	for(int i=cero; i<poblacionT;i++){
		unsigned short direcc=genRand(uno,anguloMax);
		unsigned short fuerza=genRand(cero,fuerzaMax);
		unsigned short pos[dos]={genRand(cero,posXPista),genRand(cero,posYPista)};
		pPoblacionInicial[i]= new Bola(posBB);
		pPoblacionInicial[i]->setAttr(direcc,fuerza,pos);
	}
	/**
	 * for para encliclar hasta alcazar objetivo o maximas generaciones
	 */
	for (; _generaciones<CantGeneraciones;_generaciones++){
		for(int i=cero; i<poblacionT;i++){
			pPoblacionInicial[i]->correr();
		}
		//condicion para detener el generico por objetivo alcanzado
		if(find()){
			insertSort(_poblacion);
			break;
		}
		//si no, hacemos una nueva especie y volvemos a iterar
		reproducir();
	}
	cout<<"el mejor dato fue: "<<_poblacion[cero]<<endl;
}

/**
 * funcion para repoducir a los individuos.
 */
void AlGenetico::reproducir(){
	int tempPadres[poblacionT];
	getPosPadres(tempPadres);
	Bola* temp[poblacionT*dos];
	for(int i=0;i<poblacionT;i+=dos){
		int fitness=TotalFit();
		int randFit= genRand(cero, fitness);
		temp[i]= getPadre(randFit,tempPadres);
		randFit-=temp[i]->getFitness();
		temp[i+uno]= getPadre(randFit,tempPadres);
	}
	Bola* hijos[poblacionT];
	if(_generaciones==cien){
		if(genRand(cero,uno)==cero){}
			//mutar(); aca hacemos la mutacion
		//intercambiar(); aca hacemos el intercambio
	}
	for(int i=0; i<poblacionT;i++){
		unsigned short arreglo[]
	}
	merge(hijos);
}

/**
 * funcion que realiza una mutacion si se le es invocada.
 * Recibe tres datos del mismo tipo, Bola*, estos datos, en
 * orden son, padre1, padre2 e hijo.
 */
void AlGenetico::mutar(Bola* padre1, Bola* padre2, Bola* hijo){
	//aqui vamos a realizar la mutacion.
}

/**
 * funcion que realiza una inversion de datos si se le es
 * invocada. Recibe tres datos del mismo tipo, Bola*, estos datos, en
 * orden son, padre1, padre2 e hijo.
 */
void AlGenetico::intercambiar(Bola* padre1, Bola* padre2, Bola* hijo){
	//aqui vamos a realizar un intercambio de datos.
}

/**
 * funcion que mescla en un arreglo temporal para ir ordenando los datos.
 * recibe el arreglo de los hijos.
 */
void AlGenetico::merge(Bola* hijos[]){
	Bola* temp[poblacionT*dos];
	for(int i =0, j=0; i<poblacionT*dos; i+=2, j++){
		temp[i]=hijos[j];
		temp[i+uno]=_poblacion[j];
	}
	insertSort(temp);
}

/**
 * funcion hace un ordenamiento tipo insert por medio su fitness para
 * escojer los mejores individuos.
 */
void AlGenetico::insertSort(Bola* individuos[]){
	for (int i=uno;i<poblacionT; i++){
		Bola* bolaTemp=individuos[i];
		int j=i;
		for(; j>cero && ((bolaTemp->getFitness())<
				(individuos[j-uno]->getFitness()));j--)
			individuos[j]=individuos[j-uno];
		individuos[j]=bolaTemp;
	}
}

/**
 * funcion que recibe un arreglo, en ese arreglo va a formar el ambito
 * de seleccion de padres para la reproduccion.
 */
void AlGenetico::getPosPadres(int padres[]){
	int cant=0;
	for(int i=cero; i<poblacionT;i++){
		padres[i]=cant;
		cant+=(_poblacion[i]->getFitness());
	}
}

/**
 * metodo que recibe un random de la poscion en el ambito generado por
 * getPosPadres, y el arreglo generado por getPosPadres.
 */
Bola* AlGenetico::getPadre(int padreFit, int padres[]){
	int i =cero;
	for(; i<poblacionT;i++){
		if(padres[i]<=padreFit && padreFit<padres[i+uno])
			break;
	}
	return _poblacion[i];
}

/**
 * metodo que calcula el total del fitness con el cual se esta trabajando
 * actualmente.
 */
int AlGenetico::TotalFit(){
	int total=0;
	for(int i=cero; i <poblacionT; i++){
		int dato=_poblacion[i]->getFitness();
		total+=dato;
	}
	return total;
}

/**
 * metodo que nos indica si ya se alcanzo el objetivo de la bola o aun no.
 */
bool AlGenetico::find(){
	int fitness=mil;
	for(int i=cero; i<poblacionT; i++){
		int dato=_poblacion[i]->getFitness();
		if(dato<fitness)
			fitness=dato;
	}
	if(fitness==cero)
		return true;
	return false;
}
