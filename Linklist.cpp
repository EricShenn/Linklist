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
    _next[0]._next = NULL;
    for(int i=1;i<_num;i++)
    {
        cin>>_next[i];
        
        //_next[i-1]._next  = &_next[i];
        //_next[i]._head = &_next[i-1];
        this->add_student(_next[i]);

    }
    return *this;
}

ostream &operator << (ostream &out,const Linklist &linklist)
{
    
    Node *p = linklist._next;
    int i = 1;
    cout<<*p;
    while((p = p->_next)!=NULL)
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
        Node *base = this;
        if (node._stu.get_gpa() >= _next[0]._stu.get_gpa())
        {
            node._head = NULL;
            node._next = &_next[0];
            _next = &node;
        }
        else
            while((base = base->_next))
        {
            if(base->_next!=NULL)
            if (node._stu.get_gpa()<base->_stu.get_gpa()&&node._stu.get_gpa()>=base->_next->_stu.get_gpa())
            {
                node._head = base;
                node._next = base->_next;
                base->_next = &node;
                break;
            }
            if(base->_next ==NULL)
            {
                base->_next = &node;
                node._head = base;
                node._next = NULL;
                break;
            }
        }
    
    
    
        Node *p = this;

        p->_next->_rank = 0;
        int i = 0;
        while((p = p->_next))
        {
            p->_rank = ++i;
        
        }
        
}


