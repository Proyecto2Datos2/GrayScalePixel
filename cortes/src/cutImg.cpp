/*
 * cutImg.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: ellioth
 */

#include "cutImg.h"

/**
 * constructor para inicializar la clase, este recibe un
 * Mat de la imagen en donde vamos a operar y la cantidad
 * de cortes que se quieren realizar.
 */
cutImg::cutImg(Mat orgImg, const int _cuts){
	this->_cuts=_cuts;
	_orgIMG= orgImg;
}

/**
 * funcion que recibe por parametros un arreglo de Mat
 * en donde se van a aguardar las porciones de las imagenes.
 */
void cutImg::cut(Mat corte[]){
	int filas= (_orgIMG.rows)/_cuts,i=cero;
	int columnas= (_orgIMG.cols)/_cuts;
	for(int y=cero;y<(filas*_cuts);y+=filas){
		for(int x=cero;x<(columnas*_cuts);x+=columnas){
			corte[i]=_orgIMG(Rect(x,y,columnas,filas));
			i++;
		}
	}
}

/**
 * destructor de la clase
 */
cutImg::~cutImg() {
	delete this;
}

