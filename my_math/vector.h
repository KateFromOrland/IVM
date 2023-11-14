#ifndef IVM_VECTOR_H
#define IVM_VECTOR_H

class Vector {
protected:
  double* values;
  int size;
public:
    Vector(int size);
    double norm();
    Vector& operator=(Vector v);
    ~Vector();
    int get_size();
    void print();
    double& operator[](int index);
    Vector operator +(const Vector& v);
    Vector operator -(const Vector &v);
    Vector operator *(double a);
};

#endif //IVM_VECTOR_H
