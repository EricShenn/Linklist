//
//  Node.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include "Node.hpp"
#include <iomanip>

Node::Node(Node *head,Node *next, Student stu,int rank)
:_stu(stu),_rank(rank)
{
    _head = head;
    _next = next;
    //分配空间
}



istream &operator >>(istream &in,Node &node)
{
    cin>>node._stu;
    return in;
}



ostream &operator <<(ostream &out,Node &node)
{
    cout<<node._stu<<setw(5)<<node._rank;
    

    

    return out;
}

Node::Node(const Node &node)
{
    _head = node._head;
    _rank = node._rank;
    _next = node._next;
    _stu  = node._stu;
}

Node &Node::operator = (const Node &node)
{
    _head = node._head;
    _rank = node._rank;
    _next = node._next;
    _stu  = node._stu;
    return *this;
}

istream &operator >>(istream &in,Node *node)
{
    in>>node->_stu;
    return in;
}
