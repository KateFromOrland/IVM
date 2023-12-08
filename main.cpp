#include <iostream>
#include "matrix.h"
#include "vector.h"

int main() {
    Matrix A(3), B(3);
    Vector v(3), u(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> u[i];
    }
    /*for (int i = 0; i < 3; i++) {
        std::cin >> v[i];
    }*/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> A(i, j);
        }
    }
    std::cout << "**********\n";
    A.print();
    std::cout << "**********\n";
    u.print();
    /*std::cout << "**********\n";
    v.print();
    std::cout << "**********\n";
    Vector k(3);
    k = u * 5;
    k.print();
    std::cout << "**********\n";
    (u + v).print();
    std::cout << "**********\n";
    (A * v).print();*/
    std::cout << "**********\n";
    Vector k = solve_system(A, u);
    k.print();
    return 0;
}
