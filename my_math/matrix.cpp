#include "matrix.h"
#include <iostream>

Matrix::Matrix(int size) {
    this->size = size;
    values = new double *[size];
    for (int i = 0; i < size; i++) {
        values[i] = new double[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            values[i][j] = 0.;
        }
        values[i][i] = 1.;
    }
    // std::cout << "Init square matrix of size = " << size << std::endl;
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++) {
        delete[] values[i];
    }
    delete values;
}

int Matrix::get_size() {
    return size;
}

void Matrix::print() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Vector Matrix::operator*(Vector &v) {
    Vector res(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i] += values[i][j] * v[j];
        }
    }
    return res;
}

Vector solve_system(Matrix &A, Vector &b) {
    Vector x(A.size);
    for (int i = 0; i < A.size; i++) {
        x[i] = 1;
    }
    double norm = (A * x - b).norm();
    double a = 0.1;
    int iter = 1000;
    while (norm > 0.000005 && iter > 0) {
        x = x + (b - A * x) * a;
        //(A * x - b).print();
        //x.print();
        norm = (A * x - b).norm();
        iter--;
    }
    return x;
}

double &Matrix::operator()(int i, int j) {
    return values[i][j];
}