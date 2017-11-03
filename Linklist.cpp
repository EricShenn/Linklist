//
//  Linklist.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include "Linklist.hpp"

Linklist::Linklist(int num)
:_num(num)
{
    _next = new Node[num];
}

Linklist Linklist::init()
{
    cin>>_next[0];
    _next[0]._head = NULL;
    for(int i=1;i<_num;i++)
    {
        cin>>_next[i];
        _next[i-1]._next  = &_next[i];
        _next[i]._head = &_next[i-1];

    }
    return *this;
}

ostream &operator << (ostream &out,const Linklist &linklist)
{
    
    Node *p = &linklist._next[0];
    int i = 1;
    cout<<*p;
    while((p = p->_next))
    {
        if(i++!=linklist._num)
            cout<<*p;
    }
    /*
    for(int i =0;i<linklist._num;i++)
        cout<<linklist._next[i];
    */
    cout<<"\n";
     
    return out;
}


istream &operator >> (istream &in,Linklist &linklist)
{
    linklist.init();
    return in;
}

Linklist Linklist::sort()
{
    Node tmp;
    for(int j = 0;j<(_num-1);j++)
        for(int i = 0;i<(_num-1);i++)
            if(_next[i]._stu.get_gpa()<_next[i+1]._stu.get_gpa())
            {
                tmp  =_next[i];
                _next[i] = _next[i+1];
                _next[i+1] = tmp;
            }
    for(int i =0;i<_num;i++)
        _next[i]._rank = i+1;
    
    _next[0]._head = NULL;
    for(int i=1;i<_num;i++)
    {
        _next[i-1]._next  = &_next[i];
        _next[i]._head = &_next[i-1];
    }
    _next[_num-1]._next = NULL;
    
    return *this;
}

Linklist::Linklist (const Linklist & linklist)
{
    _num  = linklist._num;
    _head = linklist._head;
    _rank = linklist._rank;
    _next = linklist._next;
    _stu  = linklist._stu;
    
}

void Linklist::add_student(Node &node)
{
    if(node._stu.get_gpa()<_next[_num-1]._stu.get_gpa())
        return;
    else
    {
        for(int i=0;i<(_num-1);i++)
            if(node._stu.get_gpa()<_next[i]._stu.get_gpa() && node._stu.get_gpa() >= _next[i+1]._stu.get_gpa())
            {
                _next[i]._next  = &node;
                node._head = &_next[i];
                node._next = &_next[i+1];
                _next[i+1]._head = &node;
                node._rank = _next[i]._rank+1;
            }
        Node *p = &node;
        while((p = p->_next))
        {
            p->_rank++;
        }
        
    }
}


