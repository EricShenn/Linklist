//
//  Student.hpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>


#include<string.h>
#include<iostream>
#include <cstring>


using namespace std;




class Student
{
public:
    Student(string id="00000000",string name="None",double gpa=0.00);
    Student & operator = (const Student &stu);
    friend ostream & operator<<(ostream &out, const Student &m);
    friend istream & operator>>(istream &in, Student &m);
    Student(const Student &stu);
    double get_gpa();
    friend class Linklist;

private:
    string _id;
    string _name;
    double GPA;
};


#endif /* Student_hpp */
