#include "interpStr.h"

#include <iostream>

int main() 
{
    std::string path1 = "/Users/xuser/avatar[1-10].png";
    std::string path2 = "/Users/xuser/avatar[01-10].png";
    std::string path3 = "/Users/xuser/avatar[17-10,23, 13-20].png";

    std::vector<std::string> stuff = interpStr(path3);

    for(auto& s : stuff) {
        std::cout << s << std::endl;
    }

    return 0;
}
