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
