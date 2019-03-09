//
// Created by alexc on 3/9/2019.
//

#include "Monom.h"
using namespace circlelist;

int main()
{
    Monom A;
    Monom B;
    std::cout << "nullptr -> EQUAL(A,B): " << EQUAL(A, B) << std::endl;
    std::cout << "EMPTY(A): " << A.EMPTY() << std::endl;
    A.INSERT(1);
    A.INSERT(3);
    A.INSERT(5);
    A.INSERT(4);
    A.PRINT();
    B.INSERT(1);
    B.INSERT(3);
    B.INSERT(5);
    B.INSERT(4);
    std::cout << "A==B EQUAL(A,B): " << EQUAL(A, B) << std::endl;
    A.INSERT(0);
    A.INSERT(7);
    A.INSERT(10);
    A.INSERT(9);
    std::cout << "A!=B head EQUAL(A,B): " << EQUAL(A, B) << std::endl;
    A.PRINT();
    B.INSERT(0);
    std::cout << "A!=B EQUAL(A,B): " << EQUAL(A, B) << std::endl;
    std::cout << "MAX(A): " << A.MAX() << std::endl;
    std::cout << "MIN(A): " << A.MIN() << std::endl;
    std::cout << "EMPTY(A): " << A.EMPTY() << std::endl;
    A.MAKENULL();
    std::cout << "MAKENULL -> EMPTY(A): " << A.EMPTY() << std::endl;

return 0;
}