#include <iostream>
#include <memory>
#include <vector>
#include "shape.hpp"
#include "square.hpp"
#include "circle.hpp"

int main(int, char**){
    std::cout << "Hello, from oop!\n";
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(1));
    shapes.push_back(std::make_unique<Square>(2));
    for(auto& shape : shapes) {
        shape->draw();
    }
}
