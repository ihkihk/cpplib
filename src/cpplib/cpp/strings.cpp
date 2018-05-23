#include <string>


using namespace std;

namespace cpplib {

template <typename ComponentT>
void tokenize(const string& str, ComponentT& tokens, string& delimiters,
        bool squashDelims = true, bool trimEmpty = false)
{
    std::string::size_type length = str.length(), pos, lastPos = 0;

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

}; // namespace

