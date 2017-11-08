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
#include <stdlib.h>
using namespace std;




void select(Linklist &oop);
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Linklist oop(4,"oop"),data_structure(4,"data_structure"),operating_system(4,"operating_system");
    Linklist *all_class[3]={&oop,&data_structure,&operating_system};
    
    while(1)
    {
        cout<<"-------------------------------------------------"<<endl;
        cout<<"1.查看“面向对象程序设计”选课情况 2.查看”计算机组成原理实验“选课情况 3.查看“操作系统”选课情况 9.退出系统"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        char i;
        cin>>i;
        if(i=='9')
        {cout<<"退出系统！\n"<<endl;break;}
        switch (i) {
            case '1':
                select(*all_class[0]);
                break;
                
            case '2':
                select(*all_class[1]);
                break;
            case '3':
                select(*all_class[2]);
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
        system("clear");
        cout<<"-------------------------------------------------"<<endl;
        cout<<"1.当前选课情况 2.添加学生 3.扩课 4.移除学生 5.返回上一级菜单"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        
        int num;
        string find_name;
        char i;
        cin>>i;
        if(i=='9')
            break;
        Node *_add = new Node;
        if(i=='5')
            break;
        switch (i) {
            case '1':
                cout<<oop;
                break;
            case '2':
                cin>>*_add;
                oop.add_student(*_add);
                break;
            case '3':
                cout<<"当前限制容量："<<oop.get_num()<<endl;
                cout<<"请输入你想扩的容量：";
                cin>>num;
                oop.kuoke(num);
                break;
            case '4':
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
        cout<<"输入任意键以继续。。"<<endl;
        getchar();
        getchar();
      
    }
}

