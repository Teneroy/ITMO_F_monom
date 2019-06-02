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
        node(elem_t d) : data(d)
        {
            next = this;
        }
        node(elem_t d, node * n) : data(d),next(n)
        {}
    };

    class Monom
    {
    public:
        Monom();
        ~Monom();
        Monom & UNION(const Monom & m1, const Monom & m2); //Объединение мн-в(C = UNION(A,B))
        Monom & INTERSECTION(const Monom & m1, const Monom & m2); //Пересечение мн-в(C = INTERSECTION(A,B))
        Monom & DIFFERENCE(const Monom & m1, const Monom & m2); //Разность мн-в(C = DIFFERENCE(A,B))
        Monom & MERGE(const Monom & m1, const Monom & m2); //Мердж мн-в(C = MERGE(A,B))
        Monom & FIND(elem_t x, Monom & m2); // Поиск эл-та в мн-вах A и B, вернет либо A, либо B, либо empty_monom
        void MAKENULL(); //Очистить мн-во
        void INSERT(elem_t x); //Вставить x в мн-во
        void DELETE(elem_t x); //Удалить x из мн-ва
        elem_t MIN() const; //Получить мин эл-т мн-ва
        elem_t MAX() const; //Получить макс эл-т мн-ва
        bool EQUAL(const Monom & m2) const; //Проверка на эквивалентность мн-в(A==B)
        Monom & ASSIGN(const Monom & m); //Приваивание мн-ва В к А(A=B)
        bool EMPTY() const; //Проверка на пустоту мн-ва(в случае вызова мин макс поальзователь проверяет на пустоту мн-в)
        bool REPEAT(const Monom & m) const; //Проверка на пересечение мн-в(Если одно из множеств пустое вернууть истина)
        void PRINT() const;
    private:
        node * _tail;
        node * deleteList(node * tail); //Очистить список
        node * copyMonom(node * t1, node * t2); //Копировать множество t1 в t2
        node * findPrevEl(elem_t x, node * tail) const; //Функция поиска по значению, возвращает предыдущий элемент
        node * deleteEL(node * tail, elem_t x); //Удаление эл-та x из мн-ва
        node * addToMonom(node * l_el, node * tail); //Добавление одного мн-ва к другому
        node * addToEnd(elem_t data, node * tail); //Добавить эл-т data в конец мн-ва
        bool equal(node * tail, node * m2_tail) const; //Эквивалентность множеств
        node * intersect_tail(node * tail, node * m1_tail, node * m2_tail, node * temp2);
        node * merge_tail(node * tail, node * m1_tail, node * m2_tail, node * temp2);
    };
}

//неупорядоченное множество
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
            next = nullptr;
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
        Monom & FIND(elem_t x, Monom & m2);
        void MAKENULL();
        void INSERT(elem_t x);
        void DELETE(elem_t x);
        elem_t MIN() const;
        elem_t MAX() const;
        bool EQUAL(const Monom & m2) const;
        Monom & ASSIGN(const Monom & m);
        bool EMPTY() const; // return _head == nullptr
        void PRINT() const;
        bool REPEAT(const Monom & m) const;
    private:
        node * _head;
        node * deleteList(node * head); //Очистить список
        node * addMonom(node * l_el, node * m2_head); //Добавить одно множество к другому
        node * deleteEl(node * head, node * prev); //Удаление элемета
        node * deleteHead(node * head); //Удалить голову
        node * findPrevEl(elem_t x, node * head) const; //Функция поиска элемента по значению, вернет предыдущий элемент
        node * get_last_el(node * head) const; //Получить последний элемент списка
        bool equal(node * head, node * m2_head) const; //Эквивалентность множеств
    };
}



//в закрытом хешировании сравнить первый элемент с пустым символом

#endif //ITMO_F_MONOM_MONOM_H
