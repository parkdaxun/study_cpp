#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Matrix {
private:
	int rows, cols;
	T** mat;
public:
	Matrix(int rows=0, int cols=0): rows(rows), cols(cols), mat(NULL) {
		mat = new T*[rows];
		for(int i = 0 ; i < rows ; i++)
			mat[i] = new T[cols];
	}
	~Matrix() {
		for(int i = 0 ; i < rows ; i++)
			delete[] mat[i];
		delete[] mat;
	}
	T& elem(int r, int c) {
		return mat[r][c];
	}
	int getRows() {
		return rows;
	}
	int getCols() {
		return cols;
	}
	T** getMatrix() {
		return mat;
	}
	void print(string title="Mat") {
		cout << title << " " << rows << "X" << cols << endl;
		for(int i = 0 ; i < rows ; i++) {
			for(int j = 0 ; j < cols ; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

#endif