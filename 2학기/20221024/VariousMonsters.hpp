#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__
#include "Canvas.hpp"
#include "Monster.h"
class Zombie:public Monster {
public:
Zombie(string name = "좀비",char icon='@',int x=0,int y=0):Monster(name,icon,x,y){}
void move(int map[DIM][DIM],int xMax,int yMax){
  switch(rand()%4) {
			case 0: y--; break;  
			case 1: x++; break;   
			case 2: y++; break;  
			case 3: x--; break; 
      }
  clip(xMax,yMax);
    eat(map);
}

};
class Vampier:public Monster{
public:
Vampier(string name = "뱀파이어",char icon='@',int x=0,int y=0):Monster(name,icon,x,y){}
void move(int map[DIM][DIM],int xMax,int yMax){
		switch(rand()%4) {
			case 0: y--; break;  
			case 1: x++; break;   
			case 2: y++; break;  
			case 3: x--; break; 
      }
    clip(xMax,yMax);
    eat(map);
  }
		void print() {
		cout << "\t" << name << icon << ":" << nItem << endl;
	}	
};
  
#endif 