#include "Monster.h"
#include <conio.h>

class Human: public Monster {
  public:
    Human(string name="플레이어", char icon='&', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int map[DIM][DIM], int xMax, int yMax) {
      if(kbhit()) {
        int num1 = getch();
        int num2 = getch();

        if(num1 == 224) {
          if(num2 == 75) x--;
          else if(num2 == 77) x++;
          else if(num2 == 72) y++;
          else if(num2 == 80) y--;
        }
      }

      clip(xMax, yMax);
      eat(map);
    }

    ~Human() {
      cout << "[  Human] ";
    }
};