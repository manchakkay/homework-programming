#include "../Matrix.h"

Matrix::Matrix(double **in, int new_h, int new_w)
{
    if (new_h < 1 || new_w < 1)
    {
        error("ERROR! Size must be greater than zero!", -1002);
    }

    memory = in;
    height = new_h;
    width = new_w;
}

Matrix::Matrix()
{
    memory = nullptr;
    height = 0;
    width = 0;
}