#include "../Matrix.h"

Matrix Matrix::inverse()
{
    if (width != height)
    {
        error("ERROR! Inverse unavailable for not square matrix",-1002);
    }

    double d_coeff = (1 / (double)mxDeterminant(Matrix(memory, height, width)));

    return onNumber(mxAlgebraic(Matrix(memory, height, width)), d_coeff);
}

int Matrix::determinant()
{
    if (width != height)
    {
        error("ERROR! Determinant unavailable for not square matrix", -1002);
    }

    return mxDeterminant(Matrix(memory, height, width));
}
