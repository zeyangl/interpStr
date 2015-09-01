#include "interpStr.h"

#include <regex>
#include <sstream>
#include <iomanip>

static void split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if(!item.empty())
            elems.push_back(item);
    }
}

static std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

static std::string trim(const std::string &s)
{
   auto wsfront = std::find_if_not(s.begin(), s.end(), std::ptr_fun<int, int>(std::isspace) );
   auto wsback = std::find_if_not(s.rbegin(), s.rend(), std::ptr_fun<int, int>(std::isspace) ).base();
   return wsback<=wsfront ? std::string() : std::string(wsfront,wsback);
}

struct Range
{
    int begin;
    int end;
    int padding;
};

//---------------------------------------------------
// process single token in the format of  x-y, or z
// with no spaces to the left or right
//---------------------------------------------------
static Range parseRangeToken(const std::string& rawToken)
{
    std::string token = trim(rawToken);
    Range r;

    size_t pos = token.find("-");
    if(pos != std::string::npos) {
        
        std::string first = token.substr(0, pos);
        std::string second = token.substr(pos+1);

        r.begin = std::stoi(first);
        r.end   = std::stoi(second);
        r.padding = first.size()-1;
    }
    else {
        r.end = r.begin = std::stoi(token);
        r.padding = token.size()-1;
    }

    return r;
}

//-----------------------------------------------
// parse a full range str [x-y, z, a-b, d, e]
//-----------------------------------------------
static std::vector<Range> parseRange(const std::string& rangeStr) 
{
    std::vector<Range> stuff;

    std::vector<std::string> tokens = split(rangeStr, ',');
    for(const auto& token : tokens) {
        Range r = parseRangeToken(token);
        stuff.push_back(r);
    }

    return stuff;
}

std::vector<std::string> interpStr(const std::string& path) 
{
    std::vector<Range> rangeList;

    std::regex re("\\[.+\\]");
    std::smatch m;
    
    std::regex_search(path, m, re);

    for(const auto& iter : m) {

        std::string mark = iter;

        size_t beginPos = mark.find("[")+1;
        size_t len = mark.rfind("]") - beginPos;
        std::string rangeStr = mark.substr(beginPos, len);

        std::vector<Range> range = parseRange(rangeStr);
        rangeList.insert(rangeList.end(), range.begin(), range.end());
    }

    std::vector<std::string> expand;

    for(const Range& r : rangeList) {
        for(int i=r.begin; i<=r.end; i++) {
            
            std::stringstream ss;
            ss << std::setw(r.padding+1) << std::setfill('0') << std::to_string(i);
            std::string out = std::regex_replace(path, re, ss.str());
            expand.push_back(out);
        }
    }

    return expand;
}

