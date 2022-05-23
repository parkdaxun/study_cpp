#include<iostream>
#include<cstring>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0): xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point AddMemberFunc(const *Point src)
	{
		Point res(this->xpos+src.xpos, this->ypos+src.ypos);
		return res;
	}
};

int main(void)
{
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3 = p1.AddMemberFunc(p2);
	p3.ShowPosition();
	
	return 0;
}
