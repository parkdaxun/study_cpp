#include "MonsterWorld.h"
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));
    int width = 16, height = 8;
    MonsterWorld game(width, height);
    game.add(new Monster("몬스터", '@', rand() % width, rand() % height));
    game.add(new Monster("도깨비", '#', rand() % width, rand() % height));
    game.add(new Monster("고스트", '$', rand() % width, rand() % height));
    game.play(3, 1);
    return 0;
}