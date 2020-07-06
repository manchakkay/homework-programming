#include <iostream>
#include "../Matrix.h"

double Matrix::mxDeterminant(Matrix m)
{
    int d = 0, k = 1;

    if (m.width == 1)
    {
        d = m.memory[0][0];
        return (d);
    }
    if (m.width == 2)
    {
        d = m.memory[0][0] * m.memory[1][1] - (m.memory[1][0] * m.memory[0][1]);
        return (d);
    }
    if (m.width > 2)
    {
        for (int i = 0; i < m.width; i++)
        {
            Matrix m_m = mxMinor(m.memory, i, 0, m.height);
            d = d + k * m.memory[i][0] * mxDeterminant(m_m);

            k = -k;
        }
    }

    return d;
}

Matrix Matrix::mxMinor(double **matrix, int i, int j, int size)
{
    double **newm;
    newm = new double *[size - 1];
    for (int l = 0; l < size - 1; l++)
    {
        newm[l] = new double[size - 1];
    }

    int ki, kj, di, dj;
    for (ki = 0; ki < size; ki++)
    {
        if (ki != i)
        {
            for (kj = 0; kj < size; kj++)
            {
                if (kj != j)
                {
                    if (ki > i)
                    {
                        di = 1;
                    }
                    else
                    {
                        di = 0;
                    }

                    if (kj > j)
                    {
                        dj = 1;
                    }
                    else
                    {
                        dj = 0;
                    }

                    newm[ki - di][kj - dj] = matrix[ki][kj];
                }
            }
        }
    }

    return Matrix(newm, size - 1, size - 1);
}

Matrix Matrix::mxTransponate(Matrix m)
{
    double **newm;
    newm = new double *[m.height];
    for (int l = 0; l < m.height; l++)
    {
        newm[l] = new double[m.height];
    }

    for (int i = 0; i < m.height; i++)
    {
        for (int j = 0; j < m.height; j++)
        {
            newm[i][j] = m.memory[j][i];
        }
    }

    return Matrix(newm, m.height, m.width);
}

Matrix Matrix::onNumber(Matrix m, double num)
{
    double **newm;
    newm = new double *[m.width];
    for (int l = 0; l < m.width; l++)
    {
        newm[l] = new double[m.height];
    }

    for (int i = 0; i < m.width; i++)
    {
        for (int j = 0; j < m.height; j++)
        {
            newm[i][j] = m.memory[i][j] * num;
        }
    }

    return Matrix(newm, m.height, m.width);
}

Matrix Matrix::onMatrix(Matrix m1, Matrix m2)
{
    double **newm;
    newm = new double *[m1.height];
    for (int l = 0; l < m1.height; l++)
    {
        newm[l] = new double[m2.width];
    }

    for (int i = 0; i < m1.height; i++)
    {
        for (int j = 0; j < m2.width; j++)
        {
            newm[i][j] = 0;
            for (int k = 0; k < m1.width; k++)
            {
                newm[i][j] += m1.memory[i][k] * m2.memory[k][j];
            }
        }
    }

    return Matrix(newm, m1.height, m2.width);
}

Matrix Matrix::addMatrix(Matrix m1, Matrix m2)
{
    double **newm;
    newm = new double *[m1.height];
    for (int l = 0; l < m1.height; l++)
    {
        newm[l] = new double[m1.width];
    }

    for (int i = 0; i < m1.height; i++)
    {
        for (int j = 0; j < m1.width; j++)
        {
            newm[i][j] = m1.memory[i][j] + m2.memory[i][j];
        }
    }

    return Matrix(newm, m1.height, m1.width);
}

Matrix Matrix::subMatrix(Matrix m1, Matrix m2)
{
    double **newm;
    newm = new double *[m1.height];
    for (int l = 0; l < m1.height; l++)
    {
        newm[l] = new double[m1.width];
    }

    for (int i = 0; i < m1.height; i++)
    {
        for (int j = 0; j < m1.width; j++)
        {
            newm[i][j] = m1.memory[i][j] - m2.memory[i][j];
        }
    }

    return Matrix(newm, m1.height, m2.width);
}

Matrix Matrix::mxAlgebraic(Matrix m)
{
    int k = 1;

    double **newm;
    newm = new double *[m.height];
    for (int l = 0; l < m.height; l++)
    {
        newm[l] = new double[m.height];
    }

    Matrix m_t = mxTransponate(m);

    for (int i = 0; i < m.height; i++)
    {
        for (int j = 0; j < m.height; j++)
        {
            Matrix m_m = mxMinor(m_t.memory, i, j, m.height);
            int d = mxDeterminant(m_m);
            newm[i][j] = k * d;

            k *= -1;
        }

        k *= -1;
    }

    return Matrix(newm, m.height, m.height);
}

void Matrix::error(const char* string, int code){
    std::cerr << string;
    exit(code);
}