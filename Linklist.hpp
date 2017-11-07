//
//  Linklist.hpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#ifndef Linklist_hpp
#define Linklist_hpp

#include <stdio.h>
#include "Node.hpp"

class Linklist:public Node
{
public:
    Linklist(int num=1,const char* classname = "incomplete");
    
    Linklist init();
    friend ostream &operator << (ostream &out,const Linklist &linklist);
    friend istream &operator >> (istream &in,Linklist &linklist);
    Linklist sort();
    Linklist (const Linklist & linklist);
    void add_student(Node &node);
    Linklist add_node();
    void kuoke(int num);
    int get_num();
    Linklist delete_student(Node &node);
    Node &find(string name)throw (char);
    void origin_data();
    void add_classname(const char* classname);
private:
    int _num;
    string _classname;
    
};



#endif /* Linklist_hpp */
