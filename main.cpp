#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main()
{
  std::string input = "inImage.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  writeImage("outImage.pgm",img, h, w);
  invert(input, img, h, w);
  invertright(input, img, h, w);
  whitebox(input, img, h, w);
  frame(input, img, h, w);
  scale(input, img, h, w);
  pixelate(input, img, h, w);
  return 0;
}