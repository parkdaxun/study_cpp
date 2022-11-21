#include <iostream>
using namespace std;

class Matrix {
  private:
    int rows;
    int cols;
    int** matrix;

  public:
    Matrix(int rows, int cols): rows(rows), cols(cols) {
      matrix = new int*[rows];
      for(int i = 0; i < cols; i++) {
        matrix[i] = new int[cols];
      }
    }

    void print() {
      cout << "Mat " << rows << "X" << cols << endl;
      for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }

    int& elem(int row, int col) {
      return matrix[row][col];
    }

    int getRows() {
      return rows;
    }

    int getCols() {
      return cols;ㅃ
    }

    int** getMatrix() {
      return matrix;
    }

    ~Matrix() {
      for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
      }
      delete[] matrix;
    }
};
