#ifndef IVM_MATRIX_H
#define IVM_MATRIX_H
#include "vector.h"

class Matrix {
    int test;
public:
    Matrix(int size);
    ~Matrix();
    int get_size();
    void print();
    Vector operator *(Vector& v);
    friend Vector solve_system(Matrix& A, Vector& v);
    double &operator()(int n, int m);

protected:
    int size;
    double **values;
};

#endif //IVM_MATRIX_H
