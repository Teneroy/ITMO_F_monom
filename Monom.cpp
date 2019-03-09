//
// Created by alexc on 3/9/2019.
//

#include "Monom.h"

/*_________CIRCLE LIST IMPLMENTATION_________*/
/*public functions*/

circlelist::Monom::Monom()
{
    _tail = nullptr;
}

circlelist::Monom::~Monom()
{
    MAKENULL();
}

void circlelist::Monom::MAKENULL()
{
    if(_tail != nullptr)
    {
        _tail = deleteList(_tail);
    }
}

circlelist::Monom & circlelist::Monom::UNION(const Monom & m1, const Monom & m2)
{
    node * temp1 = m1._tail -> next;
    node * temp2 = m2._tail -> next;
    if(_tail != nullptr)
    {
        _tail = deleteList(_tail);
    }
    /*copy monom start*/
    _tail = copyMonom(_tail, m1._tail);
    /*copy monom end*/
    return *this;
}

void circlelist::Monom::INSERT(const elem_t x)
{
    if(_tail == nullptr)
    {
        _tail = new node();
        _tail -> data = x;
        return;
    }
    node * temp = _tail -> next;
    if(_tail -> next -> data == x || _tail -> data == x)
    {
        return;
    }
    if(temp == _tail && _tail -> data < x)
    {
        _tail -> next = new node(x, _tail);
        _tail = _tail -> next;
        return;
    }
    if(temp == _tail && _tail -> data > x)
    {
        _tail -> next = new node(x, _tail);
        return;
    }
    if(temp -> data > x)
    {
        _tail -> next = new node(x, temp);
        return;
    }
    if(_tail -> data < x)
    {
        _tail -> next = new node(x, temp);
        _tail = _tail -> next;
    }
    while(temp != _tail)
    {
        if(temp -> data < x && temp -> next -> data > x)
        {
            node * next = temp -> next;
            temp -> next = new node(x, next);
            return;
        }
        temp = temp -> next;
    }
}

circlelist::elem_t circlelist::Monom::MIN() const
{
    return _tail -> next -> data;
}

circlelist::elem_t circlelist::Monom::MAX() const
{
    return _tail -> data;
}

bool circlelist::Monom::EMPTY() const
{
    return _tail == nullptr;
}

void circlelist::Monom::PRINT() const
{
    node * temp = _tail -> next;
    std::cout << std::setw(25) << "<data>" << std::endl;
    while (temp != _tail)
    {
        std::cout << std::setw(25) << temp -> data << std::endl;
        temp = temp -> next;
    }
    std::cout << std::setw(25) << temp -> data << std::endl;
}

/*private functions*/

circlelist::node * circlelist::Monom::copyMonom(node * t1, node * t2)
{
    node * temp2 = t2 -> next;
    t1 = new node;
    t1 -> data = t2 -> data;
    node * temp1 = t1;
    while(temp2 != t2)
    {
        temp1 -> next = new node(temp2 -> data, t1);
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return t1;
}

circlelist::node * circlelist::Monom::deleteList(node * tail)
{
    node * temp1;
    node * temp2 = tail -> next;
    while (temp2 != tail)
    {
        temp1 = temp2;
        temp2 = temp2 -> next;
        delete temp1;
    }
    delete temp2;
    tail = nullptr;
    return tail;
}

/*friend functions*/
bool circlelist::EQUAL(const Monom & m1, const Monom & m2)
{
    if(m1._tail == nullptr || m2._tail == nullptr)
    {
        return false;
    }
    if(m1._tail -> data != m2._tail -> data)
    {
        return false;
    }
    node * temp1 = m1._tail -> next;
    node * temp2 = m2._tail -> next;
    while(temp1 != m1._tail && temp2 != m2._tail)
    {
        if(temp1 -> data != temp2 -> data)
        {
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return true;
}