//
// Created by alexc on 3/9/2019.
//

#include "Monom.h"

/*_________CIRCLE LIST IMPLMENTATION_________*/
/*public functions*/

circlelist::Monom empty_monom;

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

circlelist::Monom & circlelist::Monom::DIFFERENCE(const Monom & m1, const Monom & m2)
{
    if(&empty_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return empty_monom;
    if(_tail != nullptr)//Если множество на котором вызываем не пустое, то чистим его
    {
        _tail = deleteList(_tail);
    }
    if(&m1 == &m2)//Если множества равны, то возвращаем пустое множество
        return *this;
    if(m1._tail == nullptr) //Если первое множество пустое, то возвращаем пустое множество
        return *this;
    if(m2._tail == nullptr) //Если второе множество пустое, то возвращаем первое множество
    {
        _tail = new node(m1._tail -> data, nullptr);
        _tail = copyMonom(_tail, m1._tail);
        return *this;
    }
    if(equal(m1._tail, m2._tail))
    {
        return *this;
    }
    node * temp = m1._tail -> next;
    node * temp2 = m2._tail -> next;
    while (temp != m1._tail && temp2 != m2._tail && (temp -> data < m2._tail -> data) && (temp2 -> data < m1._tail -> data))
    {
        if(temp -> data < temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
            temp = temp -> next;
            continue;
        }
        if(temp -> data > temp2 -> data)
        {
            temp2 = temp2 -> next;
            continue;
        }
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    if(temp == m1._tail && temp2 == m2._tail)
    {
        if(temp -> data != temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
        }
        return *this;
    }
    if(temp == m1._tail && (temp2 -> data < temp -> data))
    {
        while (temp2 != m2._tail && temp -> data > temp2 -> data)
        {
            temp2 = temp2 -> next;
        }
        if(temp -> data != temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
        }
        return *this;
    }
    if(temp -> data > m2._tail -> data)
    {
        while (temp != m1._tail)
        {
            _tail = addWithCheck(temp -> data, _tail);
            temp = temp -> next;
        }
        _tail = addWithCheck(temp -> data, _tail);
        return *this;
    }
    if(temp2 == m2._tail && temp -> data < temp2 -> data)
    {
        while (temp != m1._tail)
        {
            if(temp -> data != temp2 -> data)
            {
                _tail = addWithCheck(temp -> data, _tail);
            }
            temp = temp -> next;
        }
        if(temp -> data != temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
        }
    }
    return *this;
}

circlelist::Monom & circlelist::Monom::INTERSECTION(const Monom & m1, const Monom & m2)
{
    if(&empty_monom == this) //Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return empty_monom;
    if(_tail != nullptr) //Если множество на котором вызываем не пустое, то чистим его
    {
        _tail = deleteList(_tail);
    }
    if(m1._tail == nullptr || m2._tail == nullptr) //Если одно из множеств пустое, то возвращаем пустое множество
        return *this;
    if(&m1 == &m2) //Если мн-ва равны, то возвращаем одно из можеств
    {
        _tail = copyMonom(_tail, m1._tail);
        return *this;
    }
    if(equal(m1._tail, m2._tail))
    {
        _tail = copyMonom(_tail, m1._tail);
        return *this;
    }
    node * temp = m1._tail -> next;
    node * temp2 = m2._tail -> next;
    if(m1._tail -> next -> data > m2._tail -> data || m2._tail -> next -> data > m1._tail -> data)
        return *this;//Если значение головы первого больше хвоста второго или наоборот, то мн-ва не пересекаются и смысла идти по ним нет
    while(temp != m1._tail && (temp -> data <= m2._tail -> data) && (temp2 -> data <= m1._tail -> data) && temp2 != m2._tail)
    {//Идем по спискам, пока не дошли до конца одного из них, и значения указателей не больше значений хвостов списков
        if(temp -> data > temp2 -> data) //Если значение первого указателя больше значения второго, то перверяем следующий эл-т второго мн-ва
        {
            temp2 = temp2 -> next;
            continue;
        }
        if(temp -> data < temp2 -> data) //Если значение первого указателя меньше значения второго, то перверяем следующий эл-т первого мн-ва
        {
            temp = temp -> next;
            continue;
        }
        //Если значения совпали:
        _tail = addWithCheck(temp -> data, _tail);
        temp2 = temp2 -> next;
        temp = temp -> next;
    }
    //Проверка хвостов мн-в
    if(temp == m1._tail && temp2 == m2._tail) //Если указатели обоих мн-в указывают на последние эл-ты ссписка
    {
        if(temp -> data == temp2 -> data) //Если хвосты равны, то добавляем значение во мн-во
        {
            _tail = addWithCheck(temp -> data, _tail);
        }
        return *this; //Возвращаем мн-во
    }
    if(temp == m1._tail && (temp2 -> data <= temp -> data)) //Если дошли до конца первого мн-ва и указатель на эл-т второго мн-ва не больше хвоста первого
    {
        _tail = intersect_tail(_tail, m1._tail, m2._tail, temp2);
        return *this;
    }
    if(temp2 == m2._tail && (temp -> data <= temp2 -> data)) //Если дошли до конца второго мн-ва и указатель на эл-т первогшо мн-ва не больше хвоста второго
    {
        _tail = intersect_tail(_tail, m2._tail, m1._tail, temp);
        return *this;
    }
    return *this;
}

circlelist::Monom & circlelist::Monom::UNION(const Monom & m1, const Monom & m2)
{
    if(&empty_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return empty_monom;
    if(_tail != nullptr)//Если множество на котором вызываем не пустое, то чистим его
    {
        _tail = deleteList(_tail);
    }
    if(m2._tail == nullptr)//Если второе множество пустое, то возвращаем первое множество
    {
        _tail = copyMonom(_tail, m1._tail);
        return *this;
    }
    if(m1._tail == nullptr)//Если первое множество пустое, то возвращаем второе множество
    {
        _tail = copyMonom(_tail, m2._tail);
        return *this;
    }
    if(&m1 == &m2)//Если множества равны, то возвращаем первое множество
    {
        _tail = copyMonom(_tail, m1._tail);
        return *this;
    }
    if(m1._tail -> next -> data > m2._tail -> data)
    {
        _tail = copyMonom(_tail, m2._tail);
        _tail = addToMonom(_tail, m1._tail);
        return *this;
    }
    if(m2._tail -> next -> data > m1._tail -> data)
    {
        _tail = copyMonom(_tail, m1._tail);
        _tail = addToMonom(_tail, m2._tail);
        return *this;
    }
    _tail = copyMonom(_tail, m1._tail);
    node * temp = m2._tail -> next;
    node * temp_r = _tail -> next;
    node * next;
    while (temp != m2._tail)
    {
        if(temp -> data > _tail -> data)
        {
            //Добавляем в конец(temp_r)
            _tail = addToEnd(temp -> data, _tail);
            temp = temp -> next;
            continue;
        }
        if(temp -> data < _tail -> next -> data)
        {
            //добавляем в начало(temp_r)
            next = _tail -> next;
            _tail -> next = new node(temp -> data, next);
            temp = temp -> next;
            continue;
        }
        while (temp_r != _tail) //НАДО ЛИ ВЫНОСИТЬ В ОТДЕЛЬНУЮ ФУНКЦИЮ?
        {
            if(temp -> data == temp_r -> data)
                break;
            if( (temp -> data > temp_r -> data) && (temp -> data < temp_r -> next -> data) )
            {
                next = temp_r -> next;
                temp_r -> next = new node(temp -> data, next);
                break;
            }
            temp_r = temp_r -> next;
        }
        temp = temp -> next;
    }
    if(temp -> data > _tail -> data)
    {
        //Добавляем в конец(temp_r)
        _tail = addToEnd(temp -> data, _tail);
        temp = temp -> next;
    }
    if(temp -> data < _tail -> next -> data)
    {
        //добавляем в начало(temp_r)
        next = _tail -> next;
        _tail -> next = new node(temp -> data, next);
        temp = temp -> next;
    }
    while (temp_r != _tail)
    {
        if(temp -> data == temp_r -> data)
            break;
        if( (temp -> data > temp_r -> data) && (temp -> data < temp_r -> next -> data) )
        {
            next = temp_r -> next;
            temp_r -> next = new node(temp -> data, next);
            break;
        }
        temp_r = temp_r -> next;
    }

    return *this;
    /*copy monom start*/
    /*copy monom end*/
}

void circlelist::Monom::INSERT(const elem_t x)
{
    if(&empty_monom == this)
        return;
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
    if(&empty_monom == this)
    {
        std::cout << "Fake monom" << std::endl;
        return;
    }
    node * temp = _tail -> next;
    std::cout << std::setw(25) << "<data>" << std::endl;
    while (temp != _tail)
    {
        std::cout << std::setw(25) << temp -> data << std::endl;
        temp = temp -> next;
    }
    std::cout << std::setw(25) << temp -> data << std::endl;
}

bool circlelist::Monom::EQUAL(const Monom & m2) const
{
    if(this == &m2)
        return true;
    return equal(_tail, m2._tail);
}

bool circlelist::Monom::equal(node * tail, node * m2_tail) const
{
    if(tail == nullptr || m2_tail == nullptr)
    {
        return false;
    }
    if(tail -> data != m2_tail -> data)
    {
        return false;
    }
    node * temp1 = tail -> next;
    node * temp2 = m2_tail -> next;
    while(temp1 != tail && temp2 != m2_tail)
    {
        if(temp1 -> data != temp2 -> data)
        {
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return !(temp1 != tail || temp2 != m2_tail);
}

circlelist::Monom & circlelist::Monom::FIND(elem_t x, Monom & m2)
{
    if(&empty_monom == this || &empty_monom == &m2)
        return empty_monom;
    node * check;
    if(_tail -> next -> data == x || _tail -> data == x)
    {
        return *this;
    }
    if(m2._tail -> data == x || m2._tail -> next -> data == x)
    {
        return m2;
    }
    if(_tail -> next == _tail)
    {
        if(m2._tail -> next == m2._tail)
        {
            return empty_monom;//false
        }
        check = findPrevEl(x, m2._tail);
        if(check != nullptr)
            return m2;
        return empty_monom;
    }
    if(m2._tail -> next == m2._tail)
    {
        check = findPrevEl(x, _tail);
        if(check != nullptr)
        {
            return *this;
        }
        return empty_monom;//False
    }
    check = findPrevEl(x, _tail);
    if(check != nullptr)
        return *this;
    check = findPrevEl(x, m2._tail);
    if(check != nullptr)
        return m2;
    return empty_monom;
}

void circlelist::Monom::DELETE(elem_t x)
{
    if(&empty_monom == this)
        return;
    _tail = deleteEL(_tail, x);
}

circlelist::Monom & circlelist::Monom::ASSIGN(const Monom & m)
{
    if(&empty_monom == this)
        return empty_monom;
    if(m._tail == _tail) //???????????????????????????? шо ето за хуйня?(проверка на самоприсваивание)
    {
        return *this;
    }
    if(_tail != nullptr)
    {
        _tail = deleteList(_tail);
    }
    if(m._tail == nullptr)
    {
        return *this;
    }
    _tail = copyMonom(_tail, m._tail);
    return *this;
}

bool circlelist::Monom::REPEAT(const Monom & m) const
{
    if(_tail == nullptr || m._tail == nullptr)
        return true;
    node * temp = _tail -> next;
    node * check;
    if(_tail -> data == m._tail -> data)
        return true;
    while (temp != _tail)
    {
        if(temp -> data == m._tail -> data)
            return true;
        check = findPrevEl(temp -> data, m._tail);
        if(check != nullptr)
            return true;
        temp = temp -> next;
    }
    check = findPrevEl(_tail -> data, m._tail);
    return check != nullptr;
}

circlelist::Monom & circlelist::Monom::MERGE(const Monom & m1, const Monom & m2)
{
    if(&empty_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return empty_monom;
    if(_tail != nullptr)
    {
        _tail = deleteList(_tail);
    }
    node * temp = m1._tail -> next;
    node * temp2 = m2._tail -> next;
    while(temp != m1._tail && temp2 != m2._tail)
    {
        if(temp -> data < temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
            temp = temp -> next;
        }
        if(temp -> data > temp2 -> data)
        {
            _tail = addWithCheck(temp2 -> data, _tail);
            temp2 = temp2 -> next;
        }
    }

    if(temp == m1._tail && temp2 == m2._tail)
    {
        if(temp -> data < temp2 -> data)
        {
            _tail = addWithCheck(temp -> data, _tail);
            _tail = addToEnd(temp2 -> data, _tail);
        } else
        {
            _tail = addWithCheck(temp2 -> data, _tail);
            _tail = addToEnd(temp -> data, _tail);
        }
    }
    if(temp == m1._tail && temp2 != m2._tail)
    {
        _tail = merge_tail(_tail, m1._tail, m2._tail, temp2);
        return *this;
    }
    if(temp2 == m2._tail && temp != m1._tail)
    {
        _tail = merge_tail(_tail, m2._tail, m1._tail, temp);
    }
    return *this;
}

/*private functions*/

circlelist::node * circlelist::Monom::addWithCheck(elem_t data, node * tail)
{
    if(tail == nullptr)
    {
        tail = new node(data);
    } else
    {
        tail = addToEnd(data, tail);
    }
    return tail;
}

circlelist::node * circlelist::Monom::addToMonom(node * l_el, node * tail)
{
    node * temp = tail -> next;
    node * l_temp = l_el;
    while (temp != tail)
    {
        l_temp -> next = new node(temp -> data, l_temp -> next);
        l_temp = l_temp -> next;
        temp = temp -> next;
    }
    l_temp -> next = new node(tail -> data, l_temp -> next);
    l_temp = l_temp -> next;
    return l_temp;
}

circlelist::node * circlelist::Monom::deleteEL(node * tail, elem_t x)
{
    node * prev;
    node * cur;
    if(tail -> data == x)
    {
        //delete tail
        if(tail -> next == _tail)
        {
            delete tail;
            tail = nullptr;
        } else
        {
            cur = tail;
            prev = findPrevEl(x, tail);
            prev -> next = tail -> next;
            tail = prev;
            delete cur;
        }
        return tail;
    }
    if(tail -> next == tail)
        return tail;
    if(tail -> next -> data == x)
    {
        //delete head
        cur = tail -> next;
        tail -> next = cur -> next;
        delete cur;
        return tail;
    }
    prev = findPrevEl(x, _tail);
    if(prev == nullptr)
        return tail;
    cur = prev -> next;
    prev -> next = cur -> next;
    delete cur;
    return tail;
}

circlelist::node * circlelist::Monom::addToEnd(elem_t data, node * tail)
{
    node * next = new node(data, tail -> next);
    tail -> next = next;
    return next;
}

circlelist::node * circlelist::Monom::findPrevEl(elem_t x, node * tail) const
{
    node * temp = tail -> next;
    while (temp != tail)
    {
        if(temp -> next -> data > x)
            return nullptr;
        if(temp -> next -> data == x)
            return temp;
        temp = temp -> next;
    }
    return nullptr;
}

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


circlelist::node * circlelist::Monom::intersect_tail(node * tail, node * m1_tail, node * m2_tail, node * temp2)
{
    while (temp2 != m2_tail && m1_tail -> data >= temp2 -> data) //Идем по второму мн-ву, проверяя эл-ты на соответствие с хвостом первого
    {
        if(m1_tail -> data == temp2 -> data)
        {
            tail = addWithCheck(m1_tail -> data, tail);
            return tail;
        }
        temp2 = temp2 -> next;
    }
    if(m1_tail -> data == temp2 -> data) //Если хвосты равны, то добавляем эл-т
    {
        tail = addWithCheck(m1_tail -> data, tail);
    }
    return tail;
}


circlelist::node * circlelist::Monom::merge_tail(node * tail, node * m1_tail, node * m2_tail, node * temp2)
{
    if(m1_tail -> data < temp2 -> data)
        tail = addToEnd(m1_tail -> data, tail);
    while (temp2 != m2_tail)
    {
        tail = addWithCheck(temp2 -> data, tail);
        if(m1_tail -> data > temp2 -> data && m1_tail -> data < temp2 -> next -> data)
            tail = addToEnd(m1_tail -> data, tail);
        temp2 = temp2 -> next;
    }
    tail = addToEnd(temp2 -> data, tail);
    return tail;
}

/*___________________SINGLE LINKED LIST______________________*/

slinkedlist::Monom fake_monom;

slinkedlist::Monom::Monom()
{
    _head = nullptr;
}

slinkedlist::Monom::~Monom()
{
    MAKENULL();
}

void slinkedlist::Monom::MAKENULL()
{
    if(_head != nullptr)
    {
        _head = deleteList(_head);
    }
}

slinkedlist::Monom & slinkedlist::Monom::INTERSECTION(const Monom & m1, const Monom & m2)
{
    if(&fake_monom == this) //Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return fake_monom;
    if(_head != nullptr) //Если множество на котором вызываем не пустое, то чистим его
    {
        _head = deleteList(_head);
    }
    if(m1._head == nullptr || m2._head == nullptr) //Если одно из множеств пустое, то возвращаем пустое множество
        return *this;
    if(&m1 == &m2) //Если мн-ва равны, то возвращаем одно из можеств
    {
        _head = new node(m1._head -> data, nullptr);
        addMonom(_head, m1._head -> next);
        return *this;
    }
    if(equal(m1._head, m2._head))//Если мн-ва равны, то возвращаем одно из можеств
    {
        _head = new node(m1._head -> data, nullptr);
        addMonom(_head, m1._head -> next);
        return *this;
    }
    node * temp = m1._head;
    node * l_el = _head; //Указатель на конец множества
    while (temp != nullptr)
    {
        if(temp -> data == m2._head -> data) //Если значение текущего элемента равно значению головы второго множества
        {
            if(l_el == nullptr) //Если множества в которое мы пишем пустое
            {
                _head = new node(temp -> data, nullptr); //Создаем новую голову
                 l_el = _head; //Указатель на последний элемент теперь равен голове
            }
            else
            {
                l_el -> next = new node(temp -> data, nullptr); //Добавляем элемент в хвост
                l_el = l_el -> next; //Обновляем конец списка
            }
        } else
        {
            if(findPrevEl(temp -> data, m2._head -> next) != nullptr) //Ищем повторяющееся значение во втором множестве, если нашли, добавляем новый элемент
            {
                if(l_el == nullptr) //Если множества в которое мы пишем пустое
                {
                    _head = new node(temp -> data, nullptr); //Создаем новую голову
                    l_el = _head; //Указатель на последний элемент теперь равен голове
                } else
                {
                    l_el -> next = new node(temp -> data, nullptr);
                    l_el = l_el -> next;
                }
            }
        }
        temp = temp -> next;
    }
    return *this;
}

slinkedlist::Monom & slinkedlist::Monom::DIFFERENCE(const Monom & m1, const Monom & m2)
{
    if(&fake_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return fake_monom;
    if(_head != nullptr)//Если множество на котором вызываем не пустое, то чистим его
    {
        _head = deleteList(_head);
    }
    if(&m1 == &m2)//Если множества равны, то возвращаем пустое множество
        return *this;
    if(m1._head == nullptr) //Если первое множество пустое, то возвращаем пустое множество
        return *this;
    if(m2._head == nullptr) //Если второе множество пустое, то возвращаем первое множество
    {
        _head = new node(m1._head -> data, nullptr);
        addMonom(_head, m1._head -> next);
        return *this;
    }
    if(equal(m1._head, m2._head))
        return *this;
    node * temp = m2._head;
    _head = new node(m1._head -> data, nullptr);//Копируем множество m1 в текущее
    addMonom(_head, m1._head -> next);//Копируем множество m1 в текущее
    while (temp != nullptr)
    {
        if(_head -> data == temp -> data) //Если значения головы m1 совпадают с текущим значением
        {
            _head = deleteHead(_head); //Удаляем голову
        } else
        {
            node * prev = findPrevEl(temp -> data, _head); //Ищем значение в искомом множестве
            if(prev != nullptr) //Если нашли повторяющееся значение
            {
                _head = deleteEl(_head, prev); //Удаляем элемент
            }
        }
        temp = temp -> next;
    }
    return *this;
}

slinkedlist::Monom & slinkedlist::Monom::UNION(const Monom & m1, const Monom & m2)
{
    if(&fake_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return fake_monom;
    if(_head != nullptr)//Если множество на котором вызываем не пустое, то чистим его
    {
        _head = deleteList(_head);
    }
    if(m1._head == nullptr && m2._head == nullptr)
        return *this;
    if(m2._head == nullptr || &m1 == &m2)//Если второе множество пустое или они равны, то возвращаем первое множество
    {
        _head = new node(m1._head -> data, nullptr);
        addMonom(_head, m1._head -> next);
        return *this;
    }
    if(m1._head == nullptr)//Если первое множество пустое, то возвращаем второе множество
    {
        _head = new node(m2._head -> data, nullptr);
        addMonom(_head, m2._head -> next);
        return *this;
    }
    if(equal(m1._head, m2._head)) //Если мн-ва равны, то возвращаем первое множество
    {
        _head = new node(m1._head -> data, nullptr);
        addMonom(_head, m1._head -> next);
        return *this;
    }
    node * temp = m2._head;
    node * check; //Заводим указатель для проверки на существование элемента в мн-ве
    _head = new node(m1._head -> data, nullptr); //Копируем множество m1 в текущее множество
    node * l_el = addMonom(_head, m1._head -> next);
    while (temp != nullptr)
    {
        if(temp -> data != m1._head -> data) //Если значение текущее зачение второго множества не равно значению головы первого множества
        {
            check = findPrevEl(temp -> data, m1._head); //Ищем текущее зачение второго в первом множестве
            if(check == nullptr) // Если ничего не нашло(этого значения нету в первом множестве)
            {
                l_el -> next = new node(temp -> data, nullptr); //Добавляем значение в текущее множество
                l_el = l_el -> next;
            }
        }
        temp = temp -> next;
    }
    return *this;
}

slinkedlist::Monom & slinkedlist::Monom::MERGE(const Monom & m1, const Monom & m2)
{
    if(&fake_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return fake_monom;
    if(_head != nullptr)//Если множество на котором вызываем не пустое, то чистим его
    {
        _head = deleteList(_head);
    }
    _head = new node(m1._head -> data, nullptr);
    node * temp = addMonom(_head, m1._head -> next);
    addMonom(temp, m2._head);
    return * this;
}

void slinkedlist::Monom::INSERT(elem_t x)
{
    if(&fake_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return;
    if(_head == nullptr) //Если список пуст
    {
        _head = new node(x, nullptr); //Добавляем новую голову
        return;
    }
    if(_head -> data == x) //Если элемент уже существует, выходим из функции
        return;
    if(findPrevEl(x, _head) != nullptr)//Ищем элемент, если элемент уже существует, выходим из функции
        return;
    node * last = get_last_el(_head); //Добавляем элемент в конец множества
    last -> next = new node(x, nullptr);
}

slinkedlist::Monom & slinkedlist::Monom::ASSIGN(const Monom & m)
{
    if(&fake_monom == this)//Если пытаемся вызвать на фейковом элементе, то возвращаем фейковый элемент
        return fake_monom;
    if(this == &m) //Если происходит самоприсваивание
    {
        return *this;
    }
    if(_head != nullptr) //Если множество на котором вызываем не пустое, то чистим его
    {
        _head = deleteList(_head);
    }
    if(m._head == nullptr) //Если множество m пустое, возвращаем пустое множество
    {
        return *this;
    }
    _head = new node(m._head -> data, nullptr); //Присваиваем мн-во
    addMonom(_head, m._head -> next);
    return * this;
}

bool slinkedlist::Monom::REPEAT(const Monom & m) const
{
    if(_head == nullptr || m._head == nullptr) //Если одно из множеств пустое, возвращаем истину(тк пустое множество, является подмножеством любого множества)
        return true;
    if(_head -> data == m._head -> data)//Если значения голов совпадает, возвращаем истина
        return true;
    node * temp = _head;
    while(temp != nullptr)
    {
        if(temp -> data == m._head -> data) //Сравниваем текщее значение с головным значение
            return true;
        if(findPrevEl(temp -> data, m._head)) //Поиск по значению, если нашли текущий элемент в мн-ве, true
            return true;
        temp = temp -> next;
    }
    return false;
}

bool slinkedlist::Monom::EQUAL(const Monom & m2) const
{
    if(this == &m2)
        return true;
    return equal(_head, m2._head);
}

slinkedlist::elem_t slinkedlist::Monom::MIN() const
{
    node * temp = _head -> next;
    elem_t min = _head -> data;
    while(temp != nullptr)
    {
        if(min > temp -> data)
            min = temp -> data;
        temp = temp -> next;
    }
    return min;
}

slinkedlist::elem_t slinkedlist::Monom::MAX() const
{
    node * temp = _head -> next;
    elem_t max = _head -> data;
    while(temp != nullptr)
    {
        if(max < temp -> data)
            max = temp -> data;
        temp = temp -> next;
    }
    return max;
}

void slinkedlist::Monom::DELETE(elem_t x)
{
    if(_head == nullptr)
        return;
    if(_head -> data == x)
    {
        _head = deleteHead(_head);
        return;
    }
    node * prev = findPrevEl(x, _head);
    if(prev != nullptr)
    {
        _head = deleteEl(_head, prev);
    }
}

slinkedlist::Monom & slinkedlist::Monom::FIND(elem_t x, Monom & m2)
{
    if(&fake_monom == this || &fake_monom == &m2)//Если пытаемся вызвать на фейковом элементе или передать фейковый элемент, то возвращаем фейковый элемент
        return fake_monom;
    if(_head -> data == x)
        return *this;
    if(m2._head -> data == x)
        return m2;
    node * temp = _head -> next;
    node * temp2 = m2._head -> next;
    if(findPrevEl(x, temp) != nullptr)
        return *this;
    if(findPrevEl(x, temp2) != nullptr)
        return m2;
    return fake_monom;
}

bool slinkedlist::Monom::EMPTY() const
{
    return _head == nullptr;
}

void slinkedlist::Monom::PRINT() const
{
    if(&fake_monom == this)
    {
        std::cout << "Fake elem" << std::endl;
        return;
    }
    node * temp = _head;
    std::cout << std::setw(25) << "<data>" << std::endl;
    while (temp != nullptr)
    {
        std::cout << std::setw(25) << temp -> data << std::endl;
        temp = temp -> next;
    }
}

bool slinkedlist::Monom::equal(node * head, node * m2_head) const
{
    if(head == nullptr || m2_head == nullptr)
        return false;
    if(head -> data != m2_head -> data)
        return false;
    node * temp = head -> next;
    node * temp2 = m2_head -> next;
    while (temp != nullptr && temp2 != nullptr)
    {
        if(temp -> data != temp2 -> data)
            return false;
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    return !(temp != nullptr || temp2 != nullptr);
}

slinkedlist::node * slinkedlist::Monom::deleteEl(node * head, node * prev)
{
    node * cur = prev -> next;
    prev -> next = cur -> next;
    delete cur;
    return head;
}

slinkedlist::node * slinkedlist::Monom::deleteHead(node * head)
{
    node * cur = head;
    head = head -> next;
    delete cur;
    return head;
}

slinkedlist::node * slinkedlist::Monom::addMonom(node * l_el, node * m2_head)
{
    node * temp = l_el;
    node * temp2 = m2_head;
    while (temp2 != nullptr)
    {
        temp -> next = new node(temp2 -> data, nullptr);
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    return temp;
}

slinkedlist::node * slinkedlist::Monom::findPrevEl(elem_t x, node * head) const
{
    node * temp = head;
    while (temp != nullptr)
    {
        if(temp -> next == nullptr)
            break;
        if(temp -> next -> data == x)
            return temp;
        temp = temp -> next;
    }
    return nullptr;
}

slinkedlist::node * slinkedlist::Monom::get_last_el(node * head) const
{
    node * temp = head;
    node * temp2 = temp -> next;
    while (temp2 != nullptr)
    {
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    return temp;
}

slinkedlist::node * slinkedlist::Monom::deleteList(node * head)
{
    node * temp1;
    node * temp2 = head;
    while (temp2 != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2 -> next;
        delete temp1;
    }
    head = nullptr;
    return head;
}
