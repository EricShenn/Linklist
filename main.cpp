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
    Node _add;
    test.sort();
    cout<<test;
    cin>>_add;
    test.add_student(_add);
    cout<<test;
    
 
}
