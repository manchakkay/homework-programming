#include "../Matrix.h"

Matrix operator+(Matrix &m1, Matrix &m2)
{

    if (m2.height != m1.height || m2.width != m1.width)
    {
        m1.error("ERROR! Sizes must be equal!", -1001);
    }

    return m1.addMatrix(m1, m2);
}

Matrix operator-(Matrix &m1, Matrix &m2)
{

    if (m2.height != m1.height || m2.width != m1.width)
    {
        m1.error("ERROR! Sizes must be equal!", -1001);
    }

    return m1.subMatrix(m1, m2);
}

Matrix operator*(Matrix &m1, Matrix &m2)
{

    if (m2.height != m1.width)
    {
        m1.error("ERROR! Sizes must be equal!", -1001);
    }

    return m1.onMatrix(m1, m2);
}

Matrix operator/(Matrix &m1, Matrix &m2)
{

    if (m2.height != m1.width)
    {
        m1.error("ERROR! Sizes must be equal!", -1001);
    }
    if (m2.height != m2.width)
    {
        m1.error("ERROR! Matrix must be square!", -1001);
    }

    Matrix m2i = m2;
    m2i = m2i.inverse();

    return m1.onMatrix(m1, m2i);
}