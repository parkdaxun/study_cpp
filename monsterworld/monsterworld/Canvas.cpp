#include <iostream>
#define DIM 40
using namespace std;

class Canvas {
private:
    char board[DIM][DIM];
    int xMax, yMax;
public:
    Canvas(int width, int height);
    void draw(int x, int y, char val);
    void clear(char val = ' ');
    void print(char* title = "<My Canvas>");
};
