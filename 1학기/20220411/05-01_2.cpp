#include<iostream>
#include<cstring>
using namespace std;

#include <iostream>
using namespace std;

class Point
{
private:
	float x, y;
public:
	void InitMembers(float xpos, float ypos)
	{
		SetX(xpos); SetY(ypos);
	}
	void Move(float xNum, float yNum)
	{
		x += xNum;
		y += yNum;
	}
	float GetX() const { return x; }
	float GetY() const { return y; }
	void SetX(float xpos) { x = xpos; }
	void SetY(float ypos) { y = ypos; }
	void ShowPosition() const
	{
		cout << "[" << GetX() << ", " << GetY() << "]" << endl;
	}
};

class Circle
{
	int rad;
	Point center;
public :
	void Init(float xpos, float ypos, int r)
	{
		center.InitMembers(xpos, ypos);
		rad = r;
	}
	void ShowCircleInfo() 
	{
		cout << "¹ÝÁö¸§ : " << rad << endl;
		center.ShowPosition();
	}
};

class Ring
{
	Circle inner;
	Circle outter;
public :
	ShowRingInfo() 
	{
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		
	}
	void Init(float inX, float inY, int inR, int inRad, float outX, float outY, int outRad) 
	{
		inner.Init(inX, inY, inRad);
		outter.Init(outX, outY, outRad);
	}
};

int main(void) 
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
