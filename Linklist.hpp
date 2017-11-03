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
    Linklist(int num);
    
    Linklist init();
    friend ostream &operator << (ostream &out,const Linklist &linklist);
    friend istream &operator >> (istream &in,Linklist &linklist);
    Linklist sort();
    Linklist (const Linklist & linklist);
    void add_student(Node &stu);
private:
    int _num;
    
};



#endif /* Linklist_hpp */
