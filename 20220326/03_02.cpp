#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point & PntAdder(const Point & p1, const Point &p2)
{
	Point * ptr = new Point;
	ptr -> xpos = p1.xpos + p2.xpos;
	ptr -> ypos = p1.ypos + p2.ypos;
	return *ptr;
}

int main(void) 
{
	Point * ptr1 = new Point;
	Point * ptr2 = new Point;
	
	ptr1 -> xpos = 8;
	ptr1 -> ypos = 2;
	
	ptr2 -> xpos = 10;
	ptr2 -> ypos = 9;
	
	Point & result = PntAdder(*ptr1, *ptr2);
	
	cout << result.xpos << ", " << result.ypos << endl; 
}
