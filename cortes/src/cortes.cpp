//============================================================================
// Name        : cortes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include "cutImg.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat imagen= imread(argv[1],1);
	if( argc != 2 || !imagen.data ){
		printf( "No image data \n" );
		return -1;
	}
	int filas= (imagen.rows)/5;
	int columnas= (imagen.cols)/5;
	//for(int i=0; i<5;i++)
	//	matriz[i]= imagen(Rect(columnas*i,0,columnas,filas));
	/**
	 * falta enclicar la matriz para recrear todos los demas cuadros
	 * Mat matriz[25];
	int i=0;
	for(int x =0;x<(columnas*5);x+=columnas){
		for(int y=0;y<(filas*5);y+=filas){
			matriz[i]=imagen(Rect(y,x,filas,columnas));
			i++;
		}
	}
	//namedWindow( "Display Image", WINDOW_AUTOSIZE );*/
	//cutImg *matirz= new cutImg(imagen,5);
	//Mat corte[5*5];
	//matirz->cut(corte);

	imshow("Input Image", imagen);
	/*//imshow("Input Image2", *(_matriz));
	for (int i =0; i<25;i++){
		ostringstream tmp;tmp.clear();
		tmp<<i;
		const string var="input imagen"+tmp.str();
		imshow(var, corte[i]);
	}
	/*imshow("imagen IMG", imagen);*/
	Mat img=imagen;
	for(int y=0; y<img.rows; y++){
		for(int x=0;x<img.cols; x++){
			Vec3b color = img.at<Vec3b>(Point(x,y));
			int dato=(color.val[0]+color.val[1]+color.val[2])/3;
			color.val[0]=dato;
			color.val[1]=dato;
			color.val[2]=dato;
			img.at<Vec3b>(Point(x,y))=color;
		}
	}
	imwrite("/home/ellioth/Desktop/imagen_prueba.tiff",img);
	waitKey(0);/*
	/*Mat img=imagen;
	for(int y=0; y<img.rows;y++){
		for(int x=0; x<img.cols;x++){
			Vec3b color;
			for(int i=0; i<filas;i++){
				for(int j=0;j>columnas;j++){
					img.at<Vec3b>(Point(j,i));

				}
			}
		}
	}
	VideoCapture cap(0); // inicia la camara por defecto
	if(!cap.isOpened())  // revisa si se inicio
		return -1;

	for(;;)
	{
		Mat frame;
		cap >> frame; // optiene frames para la cámara
		imwrite("/home/ellioth/Desktop/image.png", frame);
		if(waitKey(30) >= 0) break;   // dice cada cuanto se hace la toma
	}
	// la camara se desactiva al finalizar la ejecución*/
	return 0;
}
