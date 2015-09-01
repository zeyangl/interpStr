#include <vector>
#include <string>

//------------------------------------------
// interpolate a string
// accept only 1 interpolation markup
// in the format of abcdeafe[1-10, 15, 16-20]
// white spaces are ignored
// ex.  /this/is/a/path/file[001-100].png
// will generate str sequence from 001 to 100
//------------------------------------------
std::vector<std::string> interpStr(const std::string& path);

