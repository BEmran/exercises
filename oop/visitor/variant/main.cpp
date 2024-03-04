#include <iostream>
#include "draw.hpp"
#include "circle.hpp"
#include "translate.hpp"
#include "shape.hpp"
#include "square.hpp"

int main(int, char**) {
    std::cout << "Hello, from oop!\n";
    Shapes shapes;
    shapes.push_back(Circle(0, 1));
    shapes.push_back(Square(0, 2));
    draw_all(shapes);
    translate_all(shapes, 7);
}
