/*
 * cutImg.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: ellioth
 */

#include "cutImg.h"

/**
 *
 */
cutImg::cutImg(Mat orgImg, const int _cuts){
	this->_cuts=_cuts;
	_orgIMG= orgImg;
}

/**
 *
 */
Mat* cutImg::cuted(Mat corte[]){
	int filas= (_orgIMG.rows)/_cuts,i=cero;
	int columnas= (_orgIMG.cols)/_cuts;
	for(int y=cero;y<(filas*_cuts);y+=filas){
		for(int x=cero;x<(columnas*_cuts);x+=columnas){
			corte[i]=_orgIMG(Rect(x,y,columnas,filas));
			i++;
		}
	}
	return corte;
}

/**
 *
 */
cutImg::~cutImg() {
	delete this;
}

