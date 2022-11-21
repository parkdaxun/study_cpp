#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#include "Matrix.h"
#define DIM 40
using namespace std;

class Canvas {
private:
    Matrix<char> map;
    int xMax, yMax;
public:
    Canvas(int xMax, int yMax) : xMax(xMax), yMax(yMax), map(xMax, yMax) {
      for(int i = 0; i < yMax; i++) {
        for(int j = 0; j < xMax; j++) {
          map.elem(i, j) = ' ';
        }
      }
    }

    void draw(int i, int j, char word) {
      if(i >= 0 && i < xMax && j >= 0 && j < yMax) map.elem(j, i) = word;
    }

    void print(const char* title = "<My Canvas>") {
      map.print();
    }

    void clear(char val = ' ') {
      for(int i = 0; i < yMax; i++) {
        for(int j = 0; j < xMax; j++) {
          draw(j, i, val);
        }
      }
    }
};

#endif