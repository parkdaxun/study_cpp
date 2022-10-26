#include <iostream>
using namespace std;

template <typename T>
class MyArray {
private:
	T* arr;
	int size;
	MyArray(const MyArray& ref) {}
	MyArray& operator=(const MyArray& ref) { return this; }
public:
	MyArray(int size): size(size) {
		arr = new T[size];
	}
	~MyArray() {
		delete[] arr;
	}
	T& operator[](int index) {
		if(index < 0 || index >= size) {
			cout << "Invalid index" << endl;
			exit(1);
		}
		return arr[index];
	}
	int GetSize() const {
		return size;
	}
};

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T xpos=0, T ypos=0): xpos(xpos), ypos(ypos) {}
	friend ostream& operator<<(ostream& os, const Point& p) {
		os << '[' << p.xpos << ", " << p.ypos << ']';
		return os;
	}
};


int main(void) {
	/*** int형 정수 저장 ***/
	MyArray<int> iarr(5);
	for(int i = 0 ; i < iarr.GetSize() ; i++) {
			iarr[i] = i;
	}
	for(int i = 0 ; i < iarr.GetSize() ; i++) {
			cout << iarr[i] << endl;
	}
	
	/*** Point<int> 객체 저장 ***/
	MyArray<Point<int>> parr(3);
	parr[0] = Point<int>(1, 2);
	parr[1] = Point<int>(3, 4);
	parr[2] = Point<int>(5, 6);
	for(int i = 0 ; i < parr.GetSize() ; i++) {
			cout << parr[i] << endl;
	}
	
  return 0;
}
