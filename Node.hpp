//
//  Node.hpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <cstring>
#include "Student.hpp"


class Node
{
public:
    Node(Node *head=NULL,Node *next=NULL, Student stu = Student(),int rank = 0);
    Node(const Node &node);
    friend istream &operator >>(istream &in,Node &node);
    friend istream &operator >>(istream &in,Node *node);

    friend ostream &operator <<(ostream &out,Node &node);
    Node &operator = (const Node &node);
    
    
    Node *_head;
    Node *_next;
    Student _stu;
    int _rank;
};










#endif /* Node_hpp */


