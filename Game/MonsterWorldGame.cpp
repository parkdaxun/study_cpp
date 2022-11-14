#include "MonsterWorld.h"
#include "Human.h"
#include "VariousMonsters.h"
#include <time.h>

int main(void) {
	srand((unsigned int)time(NULL));
	int width = 16, height = 8;

	MonsterWorld game(width, height);
	game.add(new Human("�÷��̾�", '&', rand() % width, rand() % height));
	game.add(new Zombie("����������", '!', rand() % width, rand() % height));
	game.add(new Vampire("�������̾�", '@', rand() % width, rand() % height));
	game.add(new Vampire("�������� ���� ����", '*', rand() % width, rand() % height));
	game.play(30, 1000);
	return 0;
}