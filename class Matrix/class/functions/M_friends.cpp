#include "../Matrix.h"

std::ostream &operator<<(std::ostream &output, const Matrix &object)
{
    int i, j;
    for (i = 0; i < object.width; i++)
    {
        for (j = 0; j < object.height; j++)
            output << object.memory[i][j] << " ";
        output << std::endl;
    }

    return output;
}