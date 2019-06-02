//
// Created by alexc on 3/9/2019.
//

#include "Monom.h"
using namespace circlelist;

int main()
{
//    Monom A;
//    Monom B;
//    Monom C;
//    //std::cout << "nullptr -> EQUAL(A,B): " << A.EQUAL(B) << std::endl;
//    std::cout << "EMPTY(A): " << A.EMPTY() << std::endl;
//    A.INSERT(1);
//    A.INSERT(5);
//    A.INSERT(9);
//    A.INSERT(14);
//    A.INSERT(15);
//   // A.PRINT();
//    B.INSERT(10);
//    B.INSERT(13);
//    B.INSERT(15);
//    B.INSERT(9);
//    B.INSERT(20);
//    B.INSERT(21);
//    B.INSERT(31);
////    B.INSERT(4);
////    B.INSERT(8);
////    B.INSERT(80);
//
//    std::cout << "_______________A______________" << std::endl;
//    A.PRINT();
//    std::cout << "______________________________" << std::endl;
//    std::cout << "_______________B______________" << std::endl;
//    B.PRINT();
//    std::cout << "______________________________" << std::endl;
//    std::cout << "_______________UNION(A,B)______________" << std::endl;
//    C.UNION(A,B).PRINT();
//    std::cout << "______________________________" << std::endl;
//    std::cout << "_______________INTERSECTION(A,B)______________" << std::endl;
//    C.INTERSECTION(A,B).PRINT();
//    std::cout << "______________________________" << std::endl;
//    std::cout << "A!=B EQUAL(A,B): " << A.EQUAL(B) << std::endl;
//    A.INSERT(0);
//    A.INSERT(7);
//    A.INSERT(10);
//    A.INSERT(9);
//    std::cout << "A!=B head EQUAL(A,B): " << A.EQUAL(B) << std::endl;
//    A.PRINT();
//    B.INSERT(0);
//    std::cout << "A!=B EQUAL(A,B): " << A.EQUAL(B) << std::endl;
//    std::cout << "MAX(A): " << A.MAX() << std::endl;
//    std::cout << "MIN(A): " << A.MIN() << std::endl;
//    std::cout << "EMPTY(A): " << A.EMPTY() << std::endl;
//    std::cout << "Main functions: <" << std::endl;
//    std::cout << "UNION(A,B): {" << std::endl;
//    C.UNION(A, B);
//    C.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "INTERSECTION(A,B): {" << std::endl;
//    C.INTERSECTION(A, B);
//    C.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "DIFFERENCE(A,B): {" << std::endl;
//    C.DIFFERENCE(A, B);
//    C.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "FIND(8, A, B): {" << std::endl;
//    A.FIND(8, B).PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "FIND(10, A, B): {" << std::endl;
//    A.FIND(10, B).PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "FIND(100, A, B): {" << std::endl;
//    A.FIND(100, B).PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "ASSIGN(A, B): {" << std::endl;
//    A.ASSIGN(B);
//    A.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "DELETE(A, 80): {" << std::endl;
//    A.DELETE(80);
//    A.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "REPEAT(A, B): {" << std::endl;
//    std::cout << A.REPEAT(B) << std::endl;
//    std::cout << "}; true" << std::endl;
//    A.MAKENULL();
//    B.MAKENULL();
//    A.INSERT(1);
//    A.INSERT(2);
//    A.INSERT(6);
//    B.INSERT(3);
//    B.INSERT(9);
//    B.INSERT(10);
//    std::cout << "REPEAT(A, B): {" << std::endl;
//    std::cout << A.REPEAT(B) << std::endl;
//    std::cout << "}; false" << std::endl;
//    std::cout << "PRINT(A): {" << std::endl;
//    A.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "PRINT(B): {" << std::endl;
//    B.PRINT();
//    std::cout << "};" << std::endl;
//    std::cout << "MERGE(A, B): {" << std::endl;
//    C.MERGE(A, B);
//    C.PRINT();
//    std::cout << "};" << std::endl;
    Monom A1;
    Monom B1;
    Monom C1;
    A1.INSERT(1);
//    A1.INSERT(3);
    A1.INSERT(9);
//    A1.INSERT(6);
//    A1.INSERT(8);
//    A1.INSERT(9);
    A1.INSERT(10);
    A1.INSERT(11);
    A1.INSERT(24);

    B1.INSERT(2);
   // B1.INSERT(3);
    B1.INSERT(8);
    C1.MERGE(A1, B1).PRINT();
//    std::cout << ">" << std::endl;
//    A.MAKENULL();
//    std::cout << "MAKENULL -> EMPTY(A): " << A.EMPTY() << std::endl;


return 0;
}