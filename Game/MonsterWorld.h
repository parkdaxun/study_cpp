#ifndef __MONSTER_WORLD_H__
#define __MONSTER_WORLD_H__

#include "Monster.h"
#include "windows.h"
#include "Canvas.h"
#define MAX_MONSTER 20

class MonsterWorld {
private:
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster* mon[MAX_MONSTER];
    Canvas canvas;
public:
    MonsterWorld(int width, int height): canvas(width, height), xMax(width), yMax(height), nMon(0), nMove(0) {
        for(int i = 0; i < yMax; i++) {
            for(int j = 0; j < xMax; j++) {
                map[i][j] = 1;
            }
        }
    }

    ~MonsterWorld() {
        for(int i = 0; i < nMon; i++) {
            delete mon[i];
        }
    }

    void add(Monster* m) {
        if(nMon < MAX_MONSTER) mon[nMon++] = m;
    }

    void print() {
        system("cls");
        canvas.clear();
        for(int y = 0; y < yMax; y++) {
            for(int x = 0; x < xMax; x++) {
                if(map[y][x] == 1) {
                    canvas.draw(x, y, '.');
                }
            }
        }
        for(int i = 0; i < nMon; i++) {
            mon[i] -> draw(canvas);
        }

        canvas.print("[ Monster World ]");

        cout << "��ü �̵� Ƚ�� = " << nMove << endl;

        cout << "���� ������ �� = " << countItems() << endl;

        for(int i = 0; i < nMon; i++) {
            mon[i] -> print();
        }
    }

    int countItems() {
        int nItems = 0;
        for(int y = 0; y < yMax; y++) {
            for(int x = 0; x < xMax; x++) {
                if(map[y][x] == 1) nItems++;
            }
        }
        return nItems;
    }

    void play(int maxWalk, int wait) {
        print();
        cout << " ���͸� ��������...";
        getchar();
        for(int i = 0; i < maxWalk; i++) {
            for(int k = 0; k < nMon; k++) {
                mon[k] -> move(map, xMax, yMax);
            }
            nMove++;
            print();

            if(countItems() == 0) break;

            Sleep(wait);
        }
    }
};

#endif