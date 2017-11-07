//
//  Linklist.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include "Linklist.hpp"
#include <iomanip>
Linklist::Linklist(int num,const char* classname)
:_num(num),_classname(classname)
{
    _next = new Node;
}

Linklist Linklist::init()
{
    cin>>_next[0];
    _next[0]._stu._id = "\n" + _next[0]._stu._id;
    _next[0]._head = NULL;
    _next[0]._next = NULL;
    for(int i=1;i<_num;i++)
    {
        Node *etmp = new Node;
        cin>>etmp;
        
        //_next[i-1]._next  = &_next[i];
        //_next[i]._head = &_next[i-1];
        this->add_student(*etmp);

    }
    return *this;
}

ostream &operator << (ostream &out,const Linklist &linklist)
{
    cout<<linklist._classname<<"容量："<<linklist._num<<endl;
    cout<<setw(8)<<"stu_id"<<setw(20)<<"name"<<setw(5)<<"GPA"<<setw(7)<<"rank"<<endl;
    Node *p = linklist._next;
    int i = 1;
    cout<<*p<<'/'<<linklist._num;
    while((p = p->_next)!=NULL)
    {
        if(i++<linklist._num)
            cout<<*p<<'/'<<linklist._num;
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
        insert_by_gpa(node);    
        Node *p = this;

        p->_next->_rank = 0;
        int i = 0;
        while((p = p->_next))
        {
            p->_rank = ++i;
        
        }
        
}

Linklist Linklist::insert_by_gpa(Node &node)
{
    Node *base = this;
    if (node._stu.get_gpa() >= _next[0]._stu.get_gpa())
    {
        node._head = NULL;
        node._next = &_next[0];
        node._next->_head = &node;
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
                    node._next->_head = &node;
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
    return *this;
}

void Linklist::kuoke(int num)
{
    _num = num;
    cout<<"课程容量已变为："<<num<<endl;
}
int Linklist::get_num()
{
    return _num;
}


Linklist Linklist::delete_student(Node &node)
{
    if (node._rank == 1)
    {
        _next = node._next;
        node._next->_head = NULL;
    }
    else if(node._next == NULL)
    {
        node._head->_next =NULL;
    }
    else
    {
        node._head->_next = node._next;
        node._next->_head = node._head;
    }
    Node *p = this;
    p->_next->_rank = 0;
    int i = 0;
    while((p = p->_next))
    {
        p->_rank = ++i;
        
    }
    return *this;
}

Node &Linklist::find(string name)throw (char)
{
    Node *p = this;
    name = "\n" + name;
    while((p = p->_next))
        if(p->_stu._id==name)
            return *p;
    throw (char)0;
}

void Linklist::origin_data()
{
    Student *tmp1 = new Student("\n16121990","Shen Bonan",3.65);
    Student *tmp2 = new Student("\n16121932","Zhi Yihao",3.96);
    Student *tmp3 = new Student("\n16121943","Sun Hanzhe",3.84);
    Student *tmp4 = new Student("\n16121922","Liu Chengshuai",3.74);

    Node *node_tmp1 = new Node(NULL,NULL,*tmp1,0);
    Node *node_tmp2 = new Node(NULL,NULL,*tmp2,0);
    Node *node_tmp3 = new Node(NULL,NULL,*tmp3,0);
    Node *node_tmp4 = new Node(NULL,NULL,*tmp4,0);
    
    this->_next = node_tmp1;
    this->add_student(*node_tmp2);
    this->add_student(*node_tmp3);
    this->add_student(*node_tmp4);

}

void Linklist::add_classname(const char*classname)
{
    _classname = classname;
}


