#ifndef MATRIXMULT_H
#define MATRIXMULT_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>

class Matrix;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const Matrix& vec);

class Matrix
{
private:
    std::vector<std::vector<int>> mat;

private:
    static Matrix combiner(const Matrix& matrix1, const Matrix& matrix2, const Matrix& matrix3, const Matrix& matrix4);

    static void StrassenMult(Matrix& answer, const Matrix& matrix, const Matrix& matrix2);

public:
    Matrix() = default;
    Matrix(int n, int m, int val = 0);
    Matrix(std::initializer_list<std::initializer_list<int>> list);

    ~Matrix() = default;

    Matrix cutter(int start_x, int end_x, int start_y, int end_y) const;

    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;

    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

#endif