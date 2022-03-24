#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "imageio.h"
#include "funcs.h"

void invert(std::string filename, int image[MAX_H][MAX_W], int &height, int &width){
	readImage(filename,image,height,width);
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			image[row][col] = 255 - image[row][col];
		}
	}
 	writeImage("taskA.pgm",image, height, width);
}
void invertright(std::string filename, int image[MAX_H][MAX_W], int &height, int &width){
	readImage(filename,image,height,width);
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			if (col>width/2){
				image[row][col] = 255 - image[row][col];
			}
		}
	}
  	writeImage("taskB.pgm",image, height, width);
}
void whitebox(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	readImage(filename,image,height,width);
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			if ((row>=height/4)&&(row<=height*3/4)&&(col>=width/4)&&(col<=width*3/4))
				image[row][col] = 255;
		}
	}
 	writeImage("taskC.pgm",image, height, width);
}
void frame(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	readImage(filename,image,height,width);
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			if ((abs((height/2)-row)<=height/4)&&(abs((width/2)-col)==width/4)){
				image[row][col] = 255;}
			else if ((abs((width/2)-col)<=width/4)&&(abs((height/2)-row)==height/4)){
				image[row][col] = 255;}
		}
	}	
	writeImage("taskD.pgm",image,height,width);
}
void scale(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	readImage(filename,image,height,width);
	int output[MAX_H][MAX_W]={};
	int w,h;
	width = width*2;
	height = height*2;
	if (width>MAX_W)
		width = MAX_W;
	if (height>MAX_H)
		height = MAX_H;
	for (int row = 0; row < height/2; row++)
		for (int col = 0; col <= width/2; col++){
			output[row*2][col*2]=image[row][col];
			output[row*2+1][col*2]=image[row][col];
			output[row*2][col*2+1]=image[row][col];
			output[row*2+1][col*2+1]=image[row][col];
		}
	writeImage("taskE.pgm",output,height,width);
}
void pixelate(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	readImage(filename,image,height,width);
	for (int row = 0; row <height; row+=2)
		for (int col = 0; col < width; col+=2){
			int sum = 0;
			sum += image[row][col];
			sum += image[row+1][col+1];
			sum += image[row+1][col];
			sum += image[row][col+1];
			sum=(double)sum/4;
			image[row][col]=sum;
			image[row+1][col+1]=sum;
			image[row+1][col]=sum;
			image[row][col+1]=sum;
		}
	writeImage("taskF.pgm",image,height,width);
}