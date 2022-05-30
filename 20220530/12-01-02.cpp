#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0): xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);
    friend Point operator*(const int& num, const Point& p);
    
    Point operator*(const Point& p) {
        return Point(xpos * p.xpos, ypos * p.ypos);
    }
    
    Point operator*(const int& num) {
        return Point(xpos * num, ypos * num);
    }


    Point& operator+=(const Point& p) {
        this->xpos += p.xpos;
        this->ypos += p.ypos;
        return *this;
    }
    
    Point& operator-=(const Point& p) {
        this->xpos -= p.xpos;
        this->ypos -= p.ypos;
        return *this;
    }
    Point& operator++(){
       xpos+=1;
       ypos+=1;
       return *this;
   }
   Point& operator--(){
       xpos-=1;
       ypos-=1;
       return *this;
   }
    
    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
    friend Point& operator++(Point& p1);
    friend Point& operator--(Point& p2);
};

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.xpos + p2.xpos, p1.ypos + p2.ypos);
}

Point operator-(const Point& p1, const Point& p2) {
    return Point(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
}


Point operator*(const int& num, const Point& p) {
    return Point(p.xpos * num, p.ypos * num);
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.xpos == p2.xpos && p1.ypos == p2.ypos;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}
Point& operator++(Point& p1){
   p1.xpos+=1;
   p1.ypos+=1;
   return p1;
}
Point& operator--(Point& p2){
   p2.xpos-=1;
   p2.ypos-=1;
   return p2;
}
int main(void)
{
    cout << "전위 증가 연산자" << endl;
    Point p1(1, 2);
    Point& p2 = ++p1;
    p1.ShowPosition();
    p2.ShowPosition();
    ++(++p2);
    p1.ShowPosition();
    p2.ShowPosition();
    
    cout << endl << "전위 감소 연산자" << endl;
    Point p3(11, 22);
    Point& p4 = --p3;
    p3.ShowPosition();
    p4.ShowPosition();
    --(--p4);
    p3.ShowPosition();
    p4.ShowPosition();
    
    return 0;
}