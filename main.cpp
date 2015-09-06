#include "interpStr.h"

#include <iostream>

int main() 
{
    std::string path1 = "/Users/xuser/avatar[1-10].png";
    std::string path2 = "/Users/xuser/avatar[01-10].png";
    std::string path3 = "/Users/xuser/avatar[01-156,23, 13-20].png";
    std::string path4 = "/Users/xuser/avatar[1-3,4,3-1, 1-1].png";

    std::vector<std::string> stuff = interpStr(path4);

    for(auto& s : stuff) {
        std::cout << s << std::endl;
    }

    return 0;
}
