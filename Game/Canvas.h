#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#define DIM 40
using namespace std;

class Canvas {
private:
    char board[DIM][DIM];
    int xMax, yMax;
public:
    Canvas(int xMax, int yMax) : xMax(xMax), yMax(yMax) {
      for(int i = 0; i < yMax; i++) {
        for(int j = 0; j < xMax; j++) {
          board[i][j] = ' ';
        }
      }
    }

    void draw(int i, int j, char word) {
      if(i >= 0 && i < xMax && j >= 0 && j < yMax) board[j][i] = word;
    }

    void print(const char* title = "<My Canvas>") {
      cout << title << endl;
      for(int i = 0; i < yMax; i++) {
        for(int j = 0; j < xMax; j++) {
          cout << board[i][j];
        }
        cout << endl;
      }
      cout << endl;
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