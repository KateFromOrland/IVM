#include <cmath>
#include "vector.h"

Vector::Vector(int size) {
    this->size = size;
    values = new double[size];
    for (int i = 0; i < size; i++) {
        values[i] = 0;
    }
}

Vector::~Vector() {
    delete[] values;
}

int Vector::get_size() {
    return size;
}

double Vector::norm() {
    double norm = 0;
    for (int i = 0; i < size; i++) {
        norm += values[i] * values[i];
    }
    return sqrt(norm);
}

Vector &Vector::operator=(Vector v) {
    for (int i = 0; i < size; i++) {
        values[i] = v[i];
    }
    return *this;
}

void Vector::print() {
    for (int i = 0; i < size; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

Vector Vector::operator+(const Vector& v) {
    Vector res(size);
    for (int i = 0; i < size; i++) {
        res.values[i] = v.values[i] + values[i];
    }
    return res;
}

Vector Vector::operator-(const Vector &v) {
    Vector res(size);
    for (int i = 0; i < size; i++) {
        res.values[i] = values[i] - v.values[i];
    }
    return res;
}

Vector Vector::operator*(double a) {
    Vector res(size);
    for (int i = 0; i < size; i++) {
        res.values[i] = a * values[i];
    }
    return res;
}

double &Vector::operator[](int index) {
    return values[index];
}
