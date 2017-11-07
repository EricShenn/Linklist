//
//  main.cpp
//  Course_Selection
//
//  Created by 沈博南 on 2017/11/3.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include <iostream>
#include "Linklist.hpp"

using namespace std;





int main(int argc, const char * argv[]) {
    // insert code here...
    

    Linklist test(4);
    cin>>test;
    while(1){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"1.当前选课情况 2.添加学生 3.扩课 4.移除学生"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        int i,num;
        string find_name;
        cin>>i;
        Node *_add = new Node;
        switch (i) {
            case 1:
                cout<<test;
                break;
            case 2:
                cin>>_add;
                test.add_student(*_add);
                break;
            case 3:
                cout<<"当前限制容量："<<test.get_num()<<endl;
                cout<<"请输入你想扩的容量：";
                cin>>num;
                test.kuoke(num);
                break;
            case 4:
                cout<<"请输入你要移除的学生的学号:"<<endl;
                cin>>find_name;
                try{
                    test.delete_student(test.find(find_name));}
                catch(char){
                    cout<<"查无此人"<<endl;}
                break;
            default:
                cout<<"错误参数";
                break;
        }

        
    }
    cout<<test;
    test.kuoke(5);
    cout<<test;
    
 
}
