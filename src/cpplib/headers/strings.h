#ifndef INCLUDE_STRINGS_H
#define INCLUDE_STRINGS_H

#include <string>
#include <iostream>

namespace cpplib {


template <typename ComponentT>
void tokenize(const std::string& str, ComponentT& tokens, const std::string& delimiters,
        bool squashDelims = false, bool trimEmpty = false);



}; // namespace cpplib

template<int n>
void sayHello()
{
    std::cout << "Hello " << n << std::endl;
}

#endif /* INCLUDE_STRINGS_H */
