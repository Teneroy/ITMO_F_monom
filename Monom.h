//
// Created by alexc on 3/9/2019.
//

#ifndef ITMO_F_MONOM_MONOM_H
#define ITMO_F_MONOM_MONOM_H

#include <iostream>
#include <iomanip>

namespace circlelist
{
    typedef int elem_t;

    struct node
    {
        elem_t data;
        node * next;
        node()
        {
            data = 0;
            next = this;
        }
        node(elem_t d, node * n):data(d),next(n)
        {}
    };

    class Monom
    {
    public:
        Monom();
        ~Monom();
        Monom & UNION(const Monom & m1, const Monom & m2);
        Monom & INTERSECTION(const Monom & m1, const Monom & m2);
        Monom & DIFFERENCE(const Monom & m1, const Monom & m2);
        Monom & MERGE(const Monom & m1, const Monom & m2);
        friend Monom & FIND(elem_t x, const Monom & m1, const Monom & m2);
        void MAKENULL();
        void INSERT(const elem_t x);
        void DELETE(elem_t x);
        elem_t MIN() const;
        elem_t MAX() const;
        friend bool EQUAL(const Monom & m1, const Monom & m2);
        Monom & ASSIGN(const Monom & m);
        bool EMPTY() const;
        void PRINT() const;
    private:
        node * _tail;
        node * deleteList(node * tail);
        node * copyMonom(node * t1, node * t2);
    };
}

namespace slinkedlist
{
    typedef int elem_t;

    struct node
    {
        elem_t data;
        node * next;
        node()
        {
            data = 0;
            next = this;
        }
        node(elem_t d, node * n):data(d),next(n)
        {}
    };

    class Monom
    {
    public:
        Monom();
        ~Monom();
        Monom & UNION(const Monom & m1, const Monom & m2);
        Monom & INTERSECTION(const Monom & m1, const Monom & m2);
        Monom & DIFFERENCE(const Monom & m1, const Monom & m2);
        Monom & MERGE(const Monom & m1, const Monom & m2);
        friend Monom & FIND(elem_t x, const Monom & m1, const Monom & m2);
        void MAKENULL();
        void INSERT(const elem_t x);
        void DELETE(elem_t x);
        elem_t MIN() const;
        elem_t MAX() const;
        friend bool EQUAL(const Monom & m1, const Monom & m2);
        Monom & ASSIGN(const Monom & m);
        bool EMPTY() const;
        void PRINT() const;
    private:
        node * _head;
    };
}

#endif //ITMO_F_MONOM_MONOM_H
