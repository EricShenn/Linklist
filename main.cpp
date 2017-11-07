//
//  main.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include <iostream>
#include "Linklist.hpp"
#include <iomanip>
using namespace std;




void select(Linklist &oop);
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Linklist oop(4,"oop"),data_structure(4,"data_structure");
    Linklist *all_class[2]={&oop,&data_structure};
    
    while(1)
    {
        cout<<"-------------------------------------------------"<<endl;
        cout<<"1.查看“面向对象程序设计”选课情况 2.查看”计算机组成原理实验“选课情况"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        int i;
        cin>>i;
        if(i==99)
        {cout<<"退出系统！\n"<<endl;break;}
        switch (i) {
            case 1:
                select(*all_class[0]);
                break;
                
            case 2:
                select(*all_class[1]);
                break;
            default:
                cout<<"参数错误"<<endl;
                break;
        }
        
    }
}


void select(Linklist &oop)
{
    oop.origin_data();
    while(1){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"1.当前选课情况 2.添加学生 3.扩课 4.移除学生"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        int i,num;
        string find_name;
        cin>>i;
        if(i==99)
            break;
        Node *_add = new Node;
        switch (i) {
            case 1:
                cout<<oop;
                break;
            case 2:
                cin>>_add;
                oop.add_student(*_add);
                break;
            case 3:
                cout<<"当前限制容量："<<oop.get_num()<<endl;
                cout<<"请输入你想扩的容量：";
                cin>>num;
                oop.kuoke(num);
                break;
            case 4:
                cout<<"请输入你要移除的学生的学号:"<<endl;
                cin>>find_name;
                try{
                    oop.delete_student(oop.find(find_name));}
                catch(char){
                    cout<<"查无此人"<<endl;}
                break;
            default:
                cout<<"错误参数";
                break;
        }
    }
}

