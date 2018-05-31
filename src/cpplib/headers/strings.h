#include <string>

namespace cpplib {


template <typename ComponentT>
void tokenize(const std::string& str, ComponentT& tokens, std::string& delimiters,
        bool squashDelims = false, bool trimEmpty = false);
};
