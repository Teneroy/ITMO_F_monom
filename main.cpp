//
// Created by alexc on 3/9/2019.
//

#include "Monom.h"
using namespace slinkedlist;

int main()
{
    Monom A;
    Monom B;
    Monom C;
    //std::cout << "nullptr -> EQUAL(A,B): " << A.EQUAL(B) << std::endl;
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
    B.INSERT(8);
    B.INSERT(80);
    std::cout << "A==B EQUAL(A,B): " << A.EQUAL(B) << std::endl;
    A.INSERT(0);
    A.INSERT(7);
    A.INSERT(10);
    A.INSERT(9);
    std::cout << "A!=B head EQUAL(A,B): " << A.EQUAL(B) << std::endl;
    A.PRINT();
    B.INSERT(0);
    std::cout << "A!=B EQUAL(A,B): " << A.EQUAL(B) << std::endl;
    std::cout << "MAX(A): " << A.MAX() << std::endl;
    std::cout << "MIN(A): " << A.MIN() << std::endl;
    std::cout << "EMPTY(A): " << A.EMPTY() << std::endl;
    std::cout << "Main functions: <" << std::endl;
    std::cout << "UNION(A,B): {" << std::endl;
    C.UNION(A, B);
    C.PRINT();
    std::cout << "};" << std::endl;
    std::cout << "INTERSECTION(A,B): {" << std::endl;
    C.INTERSECTION(A, B);
    C.PRINT();
    std::cout << "};" << std::endl;
    std::cout << "DIFFERENCE(A,B): {" << std::endl;
    C.DIFFERENCE(A, B);
    C.PRINT();
    std::cout << "};" << std::endl;
    std::cout << "FIND(8, A, B): {" << std::endl;
    A.FIND(8, B).PRINT();
    std::cout << "};" << std::endl;
    std::cout << "FIND(10, A, B): {" << std::endl;
    A.FIND(10, B).PRINT();
    std::cout << "};" << std::endl;
    std::cout << "FIND(100, A, B): {" << std::endl;
    A.FIND(100, B).PRINT();
    std::cout << "};" << std::endl;
    std::cout << "ASSIGN(A, B): {" << std::endl;
    A.ASSIGN(B);
    A.PRINT();
    std::cout << "};" << std::endl;
    std::cout << "DELETE(A, 80): {" << std::endl;
    A.DELETE(80);
    A.PRINT();
    std::cout << "};" << std::endl;
    std::cout << "REPEAT(A, B): {" << std::endl;
    std::cout << A.REPEAT(B) << std::endl;
    std::cout << "}; true" << std::endl;
    A.MAKENULL();
    B.MAKENULL();
    A.INSERT(1);
    A.INSERT(2);
    A.INSERT(6);
    B.INSERT(3);
    B.INSERT(9);
    B.INSERT(10);
    std::cout << "REPEAT(A, B): {" << std::endl;
    std::cout << A.REPEAT(B) << std::endl;
    std::cout << "}; false" << std::endl;
    std::cout << "MERGE(A, B): {" << std::endl;
    C.MERGE(A, B);
    C.PRINT();
    std::cout << "};" << std::endl;
    std::cout << ">" << std::endl;
    A.MAKENULL();
    std::cout << "MAKENULL -> EMPTY(A): " << A.EMPTY() << std::endl;


return 0;
}