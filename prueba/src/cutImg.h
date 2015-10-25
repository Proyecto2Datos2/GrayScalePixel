/*
 * cutImg.h
 *
 *  Created on: Oct 18, 2015
 *      Author: ellioth
 */

#ifndef CUTIMG_H_
#define CUTIMG_H_

#include <opencv2/opencv.hpp>
#include "Constantes.h"
using namespace cv;

/**
 * clase que se utiliza para cortar una imagen en
 * secciones.
 */
class cutImg :public Constantes{
public:
	cutImg(Mat orgImg, const int cuts);
	Mat* cuted(Mat corte[]);
	virtual ~cutImg();
private:
	Mat _orgIMG;
	int _cuts;
};

#endif /* CUTIMG_H_ */
