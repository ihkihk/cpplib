#include "strings.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

namespace cpplib {

template <typename ComponentT>
void tokenize(const string& str, ComponentT& tokens,  const string& delimiters,
        bool squashDelims, bool trimEmpty)
{
    std::string::size_type length = str.length(), pos, lastPos = 0;

    if (length == 0)
        return;

    if (delimiters.length() == 0) {
        tokens.push_back(str);
        return;
    }

    typedef typename ComponentT::value_type ValueType;
    typedef typename ComponentT::size_type SizeType;
    
    while (lastPos < length - 1) {
        pos = str.find_first_of(delimiters, lastPos);
        if (pos == std::string::npos) {
            pos = length;
        }

        if (pos != lastPos || !trimEmpty) {
            tokens.push_back(ValueType(str.data() + lastPos,
                        (SizeType)pos - lastPos));
        }

        lastPos = pos + 1;
    }


} // tokenize(...)

template void tokenize<std::vector<std::string> >(const std::string&, std::vector<std::string>&, const std::string&, bool, bool);

}; // namespace

