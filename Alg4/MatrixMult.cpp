#include "MatrixMult.h"

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    for (int elem : vec)
    {
        os << elem << ' ';
    }
    os << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (auto elem : matrix.mat)
    {
        os << elem;
    }
    os << std::endl;

    return os;
}

Matrix::Matrix(int n, int m, int val) : mat(n, std::vector<int>(m, val)){}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> list)
{
    for (auto elem : list)
    {
        mat.push_back(elem);
    }
}

Matrix Matrix::cutter(int start_x, int end_x, int start_y, int end_y) const
{
    int n = end_x - start_x + 1;
    int m = end_y - start_y + 1;

    Matrix answer(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            answer.mat[i][j] = mat[start_x + i][start_y + j];
        }
    }

    return answer;
}

Matrix Matrix::combiner(const Matrix& matrix1, const Matrix& matrix2, const Matrix& matrix3, const Matrix& matrix4)
{
    int n = matrix1.mat.size() + matrix3.mat.size();
    int m = matrix1.mat[0].size() + matrix2.mat[0].size();

    Matrix answer(n, m);

    for (int i = 0; i < matrix1.mat.size(); ++i)
    {
        for (int j = 0; j < matrix1.mat[0].size(); ++j)
        {
            answer.mat[i][j] = matrix1.mat[i][j];
        }
    }

    for (int i = 0; i < matrix2.mat.size(); ++i)
    {
        for (int j = 0; j < matrix2.mat[0].size(); ++j)
        {
            answer.mat[i][j + matrix1.mat[0].size()] = matrix2.mat[i][j];
        }
    }

    for (int i = 0; i < matrix3.mat.size(); ++i)
    {
        for (int j = 0; j < matrix3.mat[0].size(); ++j)
        {
            answer.mat[i + matrix1.mat.size()][j] = matrix3.mat[i][j];
        }
    }

    for (int i = 0; i < matrix4.mat.size(); ++i)
    {
        for (int j = 0; j < matrix4.mat[0].size(); ++j)
        {
            answer.mat[i + matrix1.mat.size()][j + matrix1.mat[0].size()] = matrix4.mat[i][j];
        }
    }

    return answer;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
    if (mat.size() != matrix.mat.size() || 
    (mat.size() != 0 && mat[0].size() != matrix.mat[0].size()))
    {
        throw std::runtime_error("Something went wrong!");
    }

    if (mat.size() == 0)
    {
        return Matrix(0, 0);
    }

    Matrix answer(mat.size(), mat[0].size());

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            answer.mat[i][j] = mat[i][j] + matrix.mat[i][j];
        }
    }

    return answer;
}
    
Matrix Matrix::operator-(const Matrix& matrix) const
{
    if (mat.size() != matrix.mat.size() || 
    (mat.size() != 0 && mat[0].size() != matrix.mat[0].size()))
    {
        throw std::runtime_error("Something went wrong!");
    }

    if (mat.size() == 0)
    {
        return Matrix(0, 0);
    }

    Matrix answer(mat.size(), mat[0].size());

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            answer.mat[i][j] = mat[i][j] - matrix.mat[i][j];
        }
    }

    return answer;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    if (mat.size() != matrix.mat.size() || 
    (mat.size() != 0 && mat[0].size() != matrix.mat[0].size()))
    {
        throw std::runtime_error("Something went wrong!");
    }

    if (mat.size() == 0)
    {
        return Matrix(0, 0);
    }

    Matrix answer(mat.size(), mat[0].size());

    StrassenMult(answer, *this, matrix);

    return answer;
}

void Matrix::StrassenMult(Matrix& answer, const Matrix& matrix1, const Matrix& matrix2)
{
    int start = 0;
    int end = matrix1.mat.size() - 1;

    if (start != end)
    {
        int mid = (start + end) / 2;

        Matrix A11 = matrix1.cutter(start, mid, start, mid);
        Matrix A12 = matrix1.cutter(start, mid, mid + 1, end);
        Matrix A21 = matrix1.cutter(mid + 1, end, start, mid);
        Matrix A22 = matrix1.cutter(mid + 1, end, mid + 1, end);

        Matrix B11 = matrix2.cutter(start, mid, start, mid);
        Matrix B12 = matrix2.cutter(start, mid, mid + 1, end);
        Matrix B21 = matrix2.cutter(mid + 1, end, start, mid);
        Matrix B22 = matrix2.cutter(mid + 1, end, mid + 1, end);

        Matrix S1 = B12 - B22;
        Matrix S2 = A11 + A12;
        Matrix S3 = A21 + A22;
        Matrix S4 = B21 - B11;
        Matrix S5 = A11 + A22;
        Matrix S6 = B11 + B22;
        Matrix S7 = A12 - A22;
        Matrix S8 = B21 + B22;
        Matrix S9 = A11 - A21;
        Matrix S10 = B11 + B12;

        Matrix P1 = A11 * S1;
        Matrix P2 = S2 * B22;
        Matrix P3 = S3 * B11;
        Matrix P4 = A22 * S4;
        Matrix P5 = S5 * S6;
        Matrix P6 = S7 * S8;
        Matrix P7 = S9 * S10;

        Matrix C11 = P5 + P4 - P2 + P6;
        Matrix C12 = P1 + P2;
        Matrix C21 = P3 + P4;
        Matrix C22 = P5 + P1 - P3 - P7;

        answer = combiner(C11, C12, C21, C22);
    }

    else
    {
        answer.mat[0][0] = matrix1.mat[0][0] * matrix2.mat[0][0];
    }
}

bool Matrix::operator==(const Matrix& matrix) const
{
    if (mat.size() != matrix.mat.size() || 
    (mat.size() != 0 && mat[0].size() != matrix.mat[0].size()))
    {
        return false;
    }

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            if (mat[i][j] != matrix.mat[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& matrix) const
{
    if (mat.size() != matrix.mat.size() || 
    (mat.size() != 0 && mat[0].size() != matrix.mat[0].size()))
    {
        return true;
    }

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            if (mat[i][j] != matrix.mat[i][j])
            {
                return true;
            }
        }
    }

    return false;
}