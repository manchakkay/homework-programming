#include <ostream>

/*
    Класс Матрица

    Файлы:
    - Matrix.h -> Инициализация класса
    - M_constructors -> Конструкторы класса
    - M_friends -> Дружественные функции
    - M_operator -> Реализация операторов
    - M_private -> Вспомогательные функции
    - M_public -> Общедоступные функции
*/

class Matrix
{
public:
    Matrix();
    Matrix(double **, int, int);

    int determinant();
    Matrix inverse();

    friend Matrix operator+(Matrix &m1, Matrix &m2);
    friend Matrix operator-(Matrix &m1, Matrix &m2);
    friend Matrix operator*(Matrix &m1, Matrix &m2);
    friend Matrix operator/(Matrix &m1, Matrix &m2);
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

private:
    double **memory;
    int height;
    int width;

    void error(const char *string, int code);

    double mxDeterminant(Matrix);
    Matrix mxAlgebraic(Matrix m);
    Matrix mxTransponate(Matrix m);
    Matrix mxMinor(double **, int, int, int);
    Matrix onNumber(Matrix m, double);
    Matrix onMatrix(Matrix m1, Matrix m2);
    Matrix addMatrix(Matrix m1, Matrix m2);
    Matrix subMatrix(Matrix m1, Matrix m2);
};