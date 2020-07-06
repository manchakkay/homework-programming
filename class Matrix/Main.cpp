#include <iostream>
#include "class/Matrix.h"

using namespace std;

int main()
{
    // Создаём и заполняем массив А
    int m1s;
    cout << "Enter first matrix size: ";
    cin >> m1s;

    cout << "Enter first matrix A values: " << endl;
    double **m1m = new double *[m1s];
    for (int i = 0; i < m1s; i++)
    {
        m1m[i] = new double[m1s];
        for (int j = 0; j < m1s; j++)
        {
            cout << "A[" << i << "," << j << "] = ";
            cin >> m1m[i][j];
        }
    }
    Matrix m1(m1m, m1s, m1s);

    // Создаём и заполняем массив B
    int m2s;
    cout << "Enter second matrix size: ";
    cin >> m2s;

    cout << "Enter second matrix values: " << endl;
    double **m2m = new double *[m2s];
    for (int i = 0; i < m2s; i++)
    {
        m2m[i] = new double[m2s];
        for (int j = 0; j < m2s; j++)
        {
            cout << "B[" << i << "," << j << "] = ";
            cin >> m2m[i][j];
        }
    }
    Matrix m2(m2m, m2s, m2s);

    //Вывод значений
    cout << endl
         << "First matrix:" << endl
         << m1;
    cout << "Second matrix:" << endl
         << m2;

    //Вывод определителей
    cout << endl
         << "Determinant of first matrix: " << m1.determinant() << endl;
    cout << "Determinant of second matrix: " << m2.determinant() << endl;

    //Операции над матрицами
    cout << "First matrix inverse:" << endl;
    cout << endl
         << m1.inverse();
    cout << "Second matrix inverse:" << endl;
    cout << endl
         << m2.inverse();

    cout << endl
         << "Sum of first and second matrix:" << endl;
    cout << m1 + m2;

    cout << endl
         << "Difference of first and second matrix:" << endl;
    cout << m1 - m2;

    cout << endl
         << "Multiply of first and second matrix:" << endl;
    cout << m1 * m2;

    cout << endl
         << "Division of first matrix by second matrix:" << endl;
    cout << m1 / m2;

    return 0;
}
