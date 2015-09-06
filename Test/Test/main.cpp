//
//  main.cpp
//  Test
//
//  Created by Max Young on 6/09/2015.
//  Copyright (c) 2015 Max. All rights reserved.
//

#include <iostream>
#include "interpStr.h"

int main(int argc, const char * argv[]) {
    std::string path1 = "/Users/xuser/avatar[1-10].png";
    std::string path2 = "/Users/xuser/avatar[01-10].png";
    std::string path3 = "/Users/xuser/avatar[01-06,23, 13-20].png";
    std::string path4 = "/Users/xuser/avatar[07-04,23, 13-20].png";
    
    std::vector<std::string> stuff = interpStr(path4);
    
    for(auto& s : stuff) {
        std::cout << s << std::endl;
    }
    

    return 0;
}
