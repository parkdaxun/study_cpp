#include<iostream>
#include "MyArray.cpp"
#include "16-01.cpp"

int main(void) {
	MyArray<int> iarr(5);
	for(int i = 0 ; i < iarr.GetSize() ; i++) {
			iarr[i] = i;
	}
	for(int i = 0 ; i < iarr.GetSize() ; i++) {
			cout << iarr[i] << endl;
	}
	
	MyArray<Point<int>> parr(3);
	parr[0] = Point<int>(1, 2);
	parr[1] = Point<int>(3, 4);
	parr[2] = Point<int>(5, 6);
	for(int i = 0 ; i < parr.GetSize() ; i++) {
			cout << parr[i] << endl;
	}
	
  return 0;
}
