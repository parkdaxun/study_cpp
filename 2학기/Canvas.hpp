#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#define MAX_LINE 100
#define DIM 40
using namespace std;

class Canvas {
private:
	char board[DIM][DIM];
	int xMax, yMax;
public:
	Canvas(int width=10, int height=10): xMax(width), yMax(height) {
		for(int y = 0 ; y < yMax ; y++)
			for(int x = 0 ; x < xMax ; x++)
				board[y][x] = ' ';
	}
	void draw(int x, int y, char val) {
		if(x >= 0 && x < xMax && y >= 0 && y < yMax) {
			board[y][x] = val;
		}
	}
	void clear(char val = ' ') {
		for(int y = 0 ; y < yMax ; y++)
			for(int x = 0 ; x < xMax ; x++) {
				draw(x, y, val);
			}
	}
	void print(const char* title = "<My Canvas>") {
		cout << title << endl;
		for(int y = 0 ; y < yMax ; y++) {
			for(int x = 0 ; x < xMax ; x++) {
				cout << board[y][x];
				}
			cout << endl;
		}
		cout << endl;
	}
};

#endif