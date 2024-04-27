#include "MatrixMult.h"

int main()
{
    Matrix mat1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 3, 4}, {5, 6, 7, 8}};
    Matrix mat2 = {{1, 2, 3, 4}, {1, 2, 3, 4}, {5, 6, 7, 8} ,{5, 6, 7, 8}};

    Matrix mat = mat1 * mat2;

    std::cout << mat;

    return 0;
}