#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix {
private:
    int** data;
    unsigned int rows_;
    unsigned int columns_;
public:
    Matrix(unsigned int m, unsigned int n);
    Matrix(const Matrix& mat);
    Matrix(int** array, unsigned int m, unsigned int n);
    ~Matrix();

    unsigned int rows() const;
    unsigned int columns() const;
    int get(unsigned int i, unsigned int j) const;

    void set(unsigned int i, unsigned int j, int value);    

    Matrix operator+(const Matrix& mat) const;
    Matrix operator-(const Matrix& mat) const;
    Matrix operator*(const Matrix& mat) const;
    Matrix operator~() const;
    bool operator==(const Matrix& mat);

    std::string toStr() const;
};

#endif