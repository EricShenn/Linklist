//
//  Student.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include "Student.hpp"
#include <stdlib.h>
#include <iomanip>
Student::Student(string id,string name,double gpa)
:_id(id),_name(name),GPA(gpa)
{
    ;
}

ostream & operator<<(ostream &out, const Student &m)
{
    {
        out <<m._id<<' '<<setw(11)<<m._name<<' '<<setw(5)<<m.GPA;
    }
    return out;
}



istream & operator>>(istream &in,Student &m)
{
    cout<<"请输入学号姓名和绩点，用空格隔开"<<endl;
    char str[100]="";
    in.getline(str,100,' ');
    m._id = str;
    in.getline(str, 100,' ');
    m._name = str;
    in>>m.GPA;
    
    return in;
}

Student &Student::operator = (const Student &stu)
{
    _id = stu._id;
    _name = stu._name;
    GPA = stu.GPA;
    return *this;
}

Student::Student(const Student &stu)
{
    _id = stu._id;
    _name = stu._name;
    GPA = stu.GPA;
}

double Student::get_gpa()
{
    return this->GPA;
}
