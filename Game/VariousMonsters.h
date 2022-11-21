#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__

#include "Monster.h"

class Zombie: public Monster {
  public:
    Zombie(string name="����", char icon='!', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int** map, int xMax, int yMax) {
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

    ~Zombie() {
      cout << "[  Zombie] ";
    }
};

class Vampire: public Monster {
  public:
    Vampire(string name="�����̾�", char icon='@', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int** map, int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 4) {
        case 0: y--; break;
        case 1: x++; break;
        case 2: y++; break;
        case 3: x--; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    ~Vampire() {
      cout << "[ Vampire] ";
    }
};

class PowerZombie: public Monster {
  public:
    PowerZombie(string name="���� ����", char icon='*', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int** map, int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 8) {
        case 0: y--; y--; break;
        case 1: x++; y--; x++; y--; break;
        case 2: x++; x++; break;
        case 3: x++; y++; x++; y++; break;
        case 4: y++; y++; break;
        case 5: x--; y++; x--; y++; break;
        case 6: x--; x--; break;
        case 7: x--; y--; x--; y--; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    ~PowerZombie() {
      cout << "[ PowerZombie] ";
    }
};

#endif