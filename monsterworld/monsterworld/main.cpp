#include <string>
#include <cstdlib>
#include <ctime>
#include "Canvas.h"

class Monster {
private:
    string name;
    char icon;
    int x, y, nItem;

    void clip(int xMax, int yMax) {
      if(x < 0) x = 0;
      if(x >= xMax) x = xMax - 1;
      if(y < 0) y = 0;
      if(y >= xMax) y = yMax - 1;
    }

    void eat(int map[DIM][DIM]) {
      if(map[y][x] == 1) {
        map[y][x] = 0;
        nItem++;
      }
    }
public:
    Monster(string name = "괴물", char icon = '@', int x = 0, int y = 0) : name(name), icon(icon), x(x), y(y), nItem(0) {}

    ~Monster() {
      cout << "\t" << name << icon << " 퇴장합니다~~" << endl;
    }

    void draw(Canvas& canvas) {
      canvas.draw(x, y, icon);
    }

    void move(int map[DIM][DIM], int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 8) {
        case 0: y--; break;
        case 1: x++; y--; break;
        case 2: x++; break;
        case 3: x++; y++; break;
        case 4: y++; break;
        case 5: x--; y++; break;
        case 6: x--; break;
        case 7: x--; y--; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    void print() {
      cout << "몬스터" << icon << ":" << nItem << endl;
    }
};
