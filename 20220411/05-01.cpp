#include<iostream>
#include<cstring>
using namespace std;

class Point
{
	int x, y;
public :
	bool InitMembers(int xpos, int ypos)
	{
		if(xpos<0 || xpos>100 || ypos<0 || ypos>100)
		{
			x = xpos;
			y = ypos;
			cout << "벗어난 범위의 값 전달" << endl;
			return false;
		} 
		else
		return true;
	}
	
	void ShowPosition() 
	{
		cout << "[" << x << ", " << y << "]" << endl; 
	}
};

int main(void)
{
	Point p;
	if(!p.InitMembers(-2,4))
		cout << "초기화 실패" << endl;
	if(!p.InitMembers(2, 4))
		cout << "초기화 실패" << endl;
	p.ShowPosition();
	return 0;
}
