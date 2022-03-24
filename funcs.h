#pragma once
void invert(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void invertright(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void whitebox(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void frame(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void scale(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void pixelate(std::string f, int i[MAX_H][MAX_W],int &j, int&w);