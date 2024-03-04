#include <iostream>
#include "visitor/utils.hpp"

int main(int, char**){
    std::cout << "Hello, from oop!\n";
    std::cout << "value: " << vis::foo();
}
